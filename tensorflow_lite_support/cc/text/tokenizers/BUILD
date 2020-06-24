# This package contains C++ support libraries that Java libraries can invoke.
load("@build_bazel_rules_android//android:rules.bzl", "android_library")
load(
    "//third_party/tensorflow/lite:build_def.bzl",
    "tflite_copts",
    "tflite_jni_binary",
)

package(
    default_visibility = ["//third_party/tensorflow_lite_support:users"],
    licenses = ["notice"],  # Apache 2.0
)

cc_library(
    name = "tokenizer",
    hdrs = [
        "tokenizer.h",
    ],
    deps = [
        "//third_party/absl/strings",
    ],
)

cc_library(
    name = "tokenizer_jni_lib",
    srcs = [
        "tokenizer_jni_lib.cc",
    ],
    hdrs = [
        "tokenizer_jni_lib.h",
    ],
    deps = [
        ":tokenizer",
        "//third_party/tensorflow/lite/java/jni",
        "//third_party/tensorflow_lite_support/cc/utils:jni_utils",
    ],
)

cc_library(
    name = "bert_tokenizer",
    srcs = [
        "bert_tokenizer.cc",
    ],
    hdrs = [
        "bert_tokenizer.h",
    ],
    deps = [
        ":tokenizer",
        "//third_party/absl/container:flat_hash_map",
        "//third_party/tensorflow_lite_support/cc/utils:common_utils",
        "@com_googlesource_code_re2//:re2",
        "@org_tensorflow_text//tensorflow_text/core/kernels:regex_split",
        "@org_tensorflow_text//tensorflow_text/core/kernels:wordpiece_tokenizer",
    ],
)

cc_library(
    name = "bert_tokenizer_jni_lib",
    srcs = [
        "bert_tokenizer_jni.cc",
    ],
    copts = tflite_copts(),
    linkopts = [
        "-lm",
        "-ldl",
    ],
    deps = [
        ":bert_tokenizer",
        ":tokenizer_jni_lib",
        "//third_party/tensorflow/lite/java/jni",
        "//third_party/tensorflow_lite_support/cc/utils:jni_utils",
    ],
    alwayslink = 1,
)

tflite_jni_binary(
    name = "libbert_tokenizer_jni.so",
    deps = [
        ":bert_tokenizer_jni_lib",
    ],
)

cc_library(
    name = "bert_tokenizer_runtime",
    srcs = ["libbert_tokenizer_jni.so"],
    alwayslink = 1,
)

android_library(
    name = "bert_tokenizer_jni",
    custom_package = "org.tensorflow.lite.support.text",
    manifest = "DummyManifest.xml",
    resource_files = [],
    deps = [
        ":bert_tokenizer_runtime",  # build_cleaner: skip
    ],
)

cc_library(
    name = "sentencepiece_tokenizer",
    hdrs = [
        "sentencepiece_tokenizer.h",
    ],
    deps = [
        ":tokenizer",
        "@com_google_sentencepiece//src:sentencepiece_processor",
    ],
)

cc_library(
    name = "sentencepiece_jni_lib",
    srcs = [
        "sentencepiece_jni.cc",
    ],
    copts = tflite_copts(),
    linkopts = [
        "-lm",
        "-ldl",
    ],
    deps = [
        ":sentencepiece_tokenizer",
        ":tokenizer_jni_lib",
        "//third_party/absl/strings",
        "//third_party/tensorflow/lite/java/jni",
        "//third_party/tensorflow_lite_support/cc/utils:jni_utils",
    ],
    alwayslink = 1,
)

cc_library(
    name = "sentencepiece_runtime",
    srcs = ["libsentencepiece_jni.so"],
    alwayslink = 1,
)

tflite_jni_binary(
    name = "libsentencepiece_jni.so",
    deps = [
        ":sentencepiece_jni_lib",
    ],
)

android_library(
    name = "sentencepiece_jni",
    custom_package = "org.tensorflow.lite.support.text",
    manifest = "DummyManifest.xml",
    resource_files = [],
    deps = [
        ":sentencepiece_runtime",  # build_cleaner: skip
    ],
)
