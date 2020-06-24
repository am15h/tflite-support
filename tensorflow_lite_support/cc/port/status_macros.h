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

#ifndef TENSORFLOW_LITE_SUPPORT_CC_PORT_STATUS_MACROS_H_
#define TENSORFLOW_LITE_SUPPORT_CC_PORT_STATUS_MACROS_H_

// This header file is used to manage the depended status macros library. It
// creates an extra layer that makes it easier to switch between the desired
// version of status_macros.h.
#include "util/task/status_macros.h"  // IWYU pragma: export

/* TODO(b/155676035): Set Copybara to switch to the following forked
status_macros.h externally.
third_party/tensorflow_lite_support/cc/port/default/status_macros.h
*/

#endif  // TENSORFLOW_LITE_SUPPORT_CC_PORT_STATUS_MACROS_H_
