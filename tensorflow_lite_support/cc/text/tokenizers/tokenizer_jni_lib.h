/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

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
#ifndef TENSORFLOW_LITE_SUPPORT_CC_TEXT_TOKENIZERS_TOKENIZER_JNI_LIB_H_
#define TENSORFLOW_LITE_SUPPORT_CC_TEXT_TOKENIZERS_TOKENIZER_JNI_LIB_H_

#include <jni.h>

#include <string>

#include "third_party/tensorflow_lite_support/cc/text/tokenizers/tokenizer.h"
#include "third_party/tensorflow_lite_support/cc/utils/jni_utils.h"

namespace tflite {
namespace support {

jobjectArray nativeTokenize(JNIEnv* env, jlong handle, jstring jtext);

jintArray nativeConvertTokensToIds(JNIEnv* env, jlong handle,
                                   jobjectArray jtokens);

}  // namespace support
}  // namespace tflite

#endif  // TENSORFLOW_LITE_SUPPORT_CC_TEXT_TOKENIZERS_TOKENIZER_JNI_LIB_H_