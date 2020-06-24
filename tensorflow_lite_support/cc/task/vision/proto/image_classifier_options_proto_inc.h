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

#ifndef THIRD_PARTY_TENSORFLOW_LITE_SUPPORT_CC_TASK_VISION_PROTO_IMAGE_CLASSIFIER_OPTIONS_PROTO_INC_H_
#define THIRD_PARTY_TENSORFLOW_LITE_SUPPORT_CC_TASK_VISION_PROTO_IMAGE_CLASSIFIER_OPTIONS_PROTO_INC_H_

#include "third_party/tensorflow_lite_support/cc/task/core/proto/external_file_proto_inc.h"

// TODO(b/159023727): set copybara rule to switch to
// "third_party/tensorflow_lite_support/cc/task/vision/proto/image_classifier_options.proto.h"
// for external users.
#include "photos/vision/visionkit/engines/proto/classifier_client_options.proto.h"

namespace tflite {
namespace support {
namespace task {
namespace vision {

using ImageClassifierOptions = ::visionkit::ClassifierClientOptions;

}  // namespace vision
}  // namespace task
}  // namespace support
}  // namespace tflite

#endif  // THIRD_PARTY_TENSORFLOW_LITE_SUPPORT_CC_TASK_VISION_PROTO_IMAGE_CLASSIFIER_OPTIONS_PROTO_INC_H_
