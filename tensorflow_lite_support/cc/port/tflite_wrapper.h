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

#ifndef TENSORFLOW_LITE_SUPPORT_CC_PORT_TFLITE_WRAPPER_H_
#define TENSORFLOW_LITE_SUPPORT_CC_PORT_TFLITE_WRAPPER_H_

#include "intelligence/mobile_acceleration/proto/whitelist_portable_proto.pb.h"
#include "intelligence/mobile_acceleration/support_library/tflite_wrapper.h"

namespace tflite {
namespace support {
using ::acceleration::TfLiteInterpreterWrapper;
}  // namespace support
}  // namespace tflite

namespace tflite {
namespace proto {
using ComputeSettings = ::acceleration::Acceleration;
}  // namespace proto
}  // namespace tflite

/* TODO(b/158778124): Set Copybara to switch to the following wrapper
externally. #include
"third_party/tensorflow_lite_support/cc/port/default/tflite_wrapper.h"
*/

#endif  // TENSORFLOW_LITE_SUPPORT_CC_PORT_TFLITE_WRAPPER_H_