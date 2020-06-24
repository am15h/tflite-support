load("@build_bazel_rules_android//android:rules.bzl", "android_library")
load("//third_party/tensorflow/lite:build_def.bzl", "tflite_jni_binary")

package(
    default_visibility = ["//third_party/tensorflow_lite_support:users"],
    licenses = ["notice"],  # Apache 2.0
)

tflite_jni_binary(
    name = "libbert_question_answerer_jni.so",
    srcs = [
        "bert_question_answerer_jni.cc",
    ],
    deps = [
        "//third_party/java/jdk:jni",
        "//third_party/tensorflow_lite_support/cc/task/text/qa:bert_question_answerer",
        "//third_party/tensorflow_lite_support/cc/utils:jni_utils",
    ],
)

cc_library(
    name = "bert_question_answerer_native",
    srcs = [
        ":libbert_question_answerer_jni.so",
    ],
)

android_library(
    name = "bert_question_answerer",
    srcs = glob(["*.java"]),
    deps = [
        ":bert_question_answerer_native",
        "//third_party/java/android/android_sdk_linux/extras/android/compatibility/annotations",
        "//third_party/tensorflow/lite/java:tensorflowlite_java",
        "//third_party/tensorflow_lite_support/java/src/java/org/tensorflow/lite/support/task/core:base_task_api",
    ],
)
