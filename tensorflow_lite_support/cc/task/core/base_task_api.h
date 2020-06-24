/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_LITE_SUPPORT_CC_TASK_CORE_BASE_TASK_API_H_
#define TENSORFLOW_LITE_SUPPORT_CC_TASK_CORE_BASE_TASK_API_H_

#include <utility>

#include "third_party/absl/status/status.h"
#include "third_party/absl/strings/string_view.h"
#include "third_party/tensorflow/lite/c/common.h"
#include "third_party/tensorflow_lite_support/cc/common.h"
#include "third_party/tensorflow_lite_support/cc/port/status_macros.h"
#include "third_party/tensorflow_lite_support/cc/port/statusor.h"
#include "third_party/tensorflow_lite_support/cc/port/tflite_wrapper.h"
#include "third_party/tensorflow_lite_support/cc/task/core/tflite_engine.h"

namespace tflite {
namespace support {
namespace task {
namespace core {

class BaseUntypedTaskApi {
 public:
  explicit BaseUntypedTaskApi(std::unique_ptr<TfLiteEngine> engine)
      : engine_{std::move(engine)} {}

  virtual ~BaseUntypedTaskApi() = default;

  const TfLiteEngine* GetTfLiteEngine() const { return engine_.get(); }
  const metadata::ModelMetadataExtractor* GetMetadataExtractor() const {
    return engine_->metadata_extractor();
  }

 protected:
  std::unique_ptr<TfLiteEngine> engine_;
};

template <class OutputType, class... InputTypes>
class BaseTaskApi : public BaseUntypedTaskApi {
 public:
  explicit BaseTaskApi(std::unique_ptr<TfLiteEngine> engine)
      : BaseUntypedTaskApi(std::move(engine)) {}
  // BaseTaskApi is neither copyable nor movable.
  BaseTaskApi(const BaseTaskApi&) = delete;
  BaseTaskApi& operator=(const BaseTaskApi&) = delete;

 protected:
  // Subclasses need to populate input_tensors from api_inputs.
  virtual absl::Status Preprocess(
      const std::vector<TfLiteTensor*>& input_tensors,
      InputTypes... api_inputs) = 0;

  // Subclasses need to construct OutputType object from output_tensors.
  // Original inputs are also provided as they may be needed.
  virtual StatusOr<OutputType> Postprocess(
      const std::vector<const TfLiteTensor*>& output_tensors,
      InputTypes... api_inputs) = 0;

  // Returns the tensors associated with the given input/output indexes.
  template <typename TensorType>
  std::vector<TensorType*> GetTensors(const std::vector<int>& tensor_indices) {
    tflite::Interpreter* interpreter = engine_->interpreter();
    std::vector<TensorType*> tensors;
    tensors.reserve(tensor_indices.size());
    for (int index : tensor_indices) {
      tensors.push_back(interpreter->tensor(index));
    }
    return tensors;
  }

  std::vector<TfLiteTensor*> GetInputTensors() {
    return GetTensors<TfLiteTensor>(engine_->interpreter()->inputs());
  }

  std::vector<const TfLiteTensor*> GetOutputTensors() {
    return GetTensors<const TfLiteTensor>(engine_->interpreter()->outputs());
  }

  // Performs inference using tflite::support::TfLiteInterpreterWrapper
  // InvokeWithoutFallback().
  StatusOr<OutputType> Infer(InputTypes... args) {
    tflite::support::TfLiteInterpreterWrapper* interpreter_wrapper =
        engine_->interpreter_wrapper();
    // Note: AllocateTensors() is already performed by the interpreter wrapper
    // at InitInterpreter time (see TfLiteEngine).
    RETURN_IF_ERROR(Preprocess(GetInputTensors(), args...));
    absl::Status status = interpreter_wrapper->InvokeWithoutFallback();
    if (!status.ok()) {
      return status.GetPayload(tflite::support::kTfLiteSupportPayload)
                     .has_value()
                 ? status
                 : CreateStatusWithPayload(status.code(), status.message());
    }
    return Postprocess(GetOutputTensors(), args...);
  }

  // Performs inference using tflite::support::TfLiteInterpreterWrapper
  // InvokeWithFallback() to benefit from automatic fallback from delegation to
  // CPU where applicable.
  StatusOr<OutputType> InferWithFallback(InputTypes... args) {
    tflite::support::TfLiteInterpreterWrapper* interpreter_wrapper =
        engine_->interpreter_wrapper();
    // Note: AllocateTensors() is already performed by the interpreter wrapper
    // at InitInterpreter time (see TfLiteEngine).
    RETURN_IF_ERROR(Preprocess(GetInputTensors(), args...));
    auto set_inputs_nop = [](tflite::Interpreter* interpreter) -> absl::Status {
      // NOP since inputs are populated at Preprocess() time.
      return absl::OkStatus();
    };
    absl::Status status =
        interpreter_wrapper->InvokeWithFallback(set_inputs_nop);
    if (!status.ok()) {
      return status.GetPayload(tflite::support::kTfLiteSupportPayload)
                     .has_value()
                 ? status
                 : CreateStatusWithPayload(status.code(), status.message());
    }
    return Postprocess(GetOutputTensors(), args...);
  }
};

}  // namespace core
}  // namespace task
}  // namespace support
}  // namespace tflite
#endif  // TENSORFLOW_LITE_SUPPORT_CC_TASK_CORE_BASE_TASK_API_H_
