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

#ifndef TENSORFLOW_LITE_SUPPORT_CC_TASK_VISION_OBJECT_DETECTOR_H_
#define TENSORFLOW_LITE_SUPPORT_CC_TASK_VISION_OBJECT_DETECTOR_H_

#include <memory>

#include "third_party/absl/container/flat_hash_set.h"
#include "third_party/absl/status/status.h"
#include "third_party/tensorflow_lite_support/cc/port/statusor.h"
#include "third_party/tensorflow_lite_support/cc/task/core/external_file_handler.h"
#include "third_party/tensorflow_lite_support/cc/task/vision/core/base_vision_task_api.h"
#include "third_party/tensorflow_lite_support/cc/task/vision/core/frame_buffer.h"
#include "third_party/tensorflow_lite_support/cc/task/vision/core/label_map_item.h"
#include "third_party/tensorflow_lite_support/cc/task/vision/proto/detections_proto_inc.h"
#include "third_party/tensorflow_lite_support/cc/task/vision/proto/object_detector_options_proto_inc.h"

namespace tflite {
namespace support {
namespace task {
namespace vision {

// Performs object detection on images.
//
// The API expects a TFLite model with mandatory TFLite Model Metadata.
// Input tensor:
//   (kTfLiteUInt8/kTfLiteFloat32)
//    - image input of size `[batch x height x width x channels]`.
//    - batch inference is not supported (`batch` is required to be 1).
//    - only RGB inputs are supported (`channels` is required to be 3).
//    - if type is kTfLiteFloat32, NormalizationOptions are required to be
//      attached to the metadata for input dequantization and normalization.
// Output tensors must be the 4 outputs of a `DetectionPostProcess` op, i.e:
//  (kTfLiteFloat32)
//   - locations tensor of size `[num_results x 4]`, the inner array
//     representing bounding boxes in the form [top, left, right, bottom].
//   - BoundingBoxProperties are required to be attached to the metadata
//     and must specify type=BOUNDARIES and coordinate_type=RATIO.
//  (kTfLiteFloat32)
//   - classes tensor of size `[num_results]`, each value representing the
//     integer index of a class.
//   - if label maps are attached to the metadata as TENSOR_VALUE_LABELS
//     associated files, they are used to populate the `class_name` and
//     (optional) `display_name` fields of the detection results; otherwise
//     these are left empty and only the `index` field is set.
//  (kTfLiteFloat32)
//   - scores tensor of size `[num_results]`, each value representing the score
//     of the detected object.
//  (kTfLiteFloat32)
//   - integer num_results as a tensor of size `[1]`
//
// An example of such model can be found at:
// https://tfhub.dev/google/lite-model/object_detection/mobile_object_localizer_v1/1/metadata/1
class ObjectDetector : public BaseVisionTaskApi<DetectionResult> {
 public:
  using BaseVisionTaskApi::BaseVisionTaskApi;

  // Creates an ObjectDetector from the provided options.
  static StatusOr<std::unique_ptr<ObjectDetector>> CreateFromOptions(
      const ObjectDetectorOptions& options);

  // Performs actual detection on the provided FrameBuffer.
  StatusOr<DetectionResult> Detect(const FrameBuffer& frame_buffer);

 protected:
  // Post-processing to transform the raw model outputs into detection results.
  StatusOr<DetectionResult> Postprocess(
      const std::vector<const TfLiteTensor*>& output_tensors,
      const FrameBuffer& frame_buffer, const BoundingBox& roi) override;

  // Performs sanity checks on the provided ObjectDetectorOptions.
  static absl::Status SanityCheckOptions(const ObjectDetectorOptions& options);

  // Initializes the ObjectDetector from the provided ObjectDetectorOptions.
  absl::Status Init(const ObjectDetectorOptions& options);

 private:
  // Performs sanity checks on the model outputs and extracts their metadata.
  absl::Status CheckAndSetOutputs();

  // Performs sanity checks on the class whitelist/blacklist and forms the class
  // index set.
  absl::Status CheckAndSetClassIndexSet();

  // Checks if the class at the provided index is allowed, i.e. whitelisted in
  // case a whitelist is provided or not blacklisted if a blacklist is provided.
  // Always returns true if no whitelist or blacklist were provided.
  bool IsClassIndexAllowed(int class_index);

  // Given a DetectionResult object containing class indices, fills the name and
  // display name from the label map.
  absl::Status FillResultsFromLabelMap(DetectionResult* result);

  // The options used to build this ObjectDetector.
  ObjectDetectorOptions options_;

  // Pointer to the model file handler.
  std::unique_ptr<tflite::support::task::core::ExternalFileHandler>
      model_file_handler_;

  // This is populated by reading the label files from the TFLite Model
  // Metadata: if no such files are available, this is left empty and the
  // ObjectDetector will only be able to populate the `index` field of the
  // detection results `classes` field.
  std::vector<LabelMapItem> label_map_;

  // For each pack of 4 coordinates returned by the model, this denotes the
  // order in which to get the left, top, right and bottom coordinates.
  std::vector<unsigned int> bounding_box_corners_order_;

  // Set of whitelisted or blacklisted class indices.
  struct ClassIndexSet {
    absl::flat_hash_set<int> values;
    bool is_whitelist;
  };
  // Whitelisted or blacklisted class indices based on provided options at
  // construction time. These are used to filter out results during
  // post-processing.
  ClassIndexSet class_index_set_;

  // Score threshold. Detections with a confidence below this value are
  // discarded. If none is provided via metadata or options, -FLT_MAX is set as
  // default value.
  float score_threshold_;
};

}  // namespace vision
}  // namespace task
}  // namespace support
}  // namespace tflite

#endif  // TENSORFLOW_LITE_SUPPORT_CC_TASK_VISION_OBJECT_DETECTOR_H_
