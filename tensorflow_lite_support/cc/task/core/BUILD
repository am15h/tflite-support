package(
    default_visibility = ["//third_party/tensorflow_lite_support:users"],
    licenses = ["notice"],  # Apache 2.0
)

cc_library(
    name = "tflite_engine",
    srcs = ["tflite_engine.cc"],
    hdrs = [
        "tflite_engine.h",
    ],
    deps = [
        ":external_file_handler",
        "//third_party/absl/memory",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/tensorflow/lite:framework",
        "//third_party/tensorflow/lite/c:common",
        "//third_party/tensorflow/lite/core/api",
        "//third_party/tensorflow/lite/kernels:builtin_ops",
        "//third_party/tensorflow/lite/tools:verifier",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:tflite_wrapper",
        "//third_party/tensorflow_lite_support/cc/task/core/proto:external_file_proto_inc",
        "//third_party/tensorflow_lite_support/metadata/cc:metadata_extractor",
    ],
)

cc_library(
    name = "base_task_api",
    hdrs = [
        "base_task_api.h",
    ],
    deps = [
        ":tflite_engine",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/tensorflow/lite/c:common",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/port:tflite_wrapper",
    ],
)

cc_library(
    name = "task_api_factory",
    hdrs = [
        "task_api_factory.h",
    ],
    deps = [
        ":base_task_api",
        ":tflite_engine",
        "//third_party/absl/status",
        "//third_party/tensorflow/lite/c:common",
        "//third_party/tensorflow/lite/kernels:op_macros",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
    ],
)

cc_library(
    name = "task_utils",
    srcs = [
        "task_utils.cc",
    ],
    hdrs = [
        "task_utils.h",
    ],
    deps = [
        "//third_party/absl/memory",
        "//third_party/absl/strings",
        "//third_party/tensorflow/lite:string_util",
        "//third_party/tensorflow/lite:type_to_tflitetype",
        "//third_party/tensorflow/lite/kernels:op_macros",
        "//third_party/tensorflow/lite/kernels/internal:tensor",
    ],
)

cc_library(
    name = "category",
    hdrs = ["category.h"],
)

cc_library(
    name = "external_file_handler",
    srcs = ["external_file_handler.cc"],
    hdrs = ["external_file_handler.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//third_party/absl/base:core_headers",
        "//third_party/absl/memory",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/strings:str_format",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/task/core/proto:external_file_proto_inc",
    ],
)
