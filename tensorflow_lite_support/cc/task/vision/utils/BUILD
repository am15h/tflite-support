package(
    default_visibility = [
        "//third_party/tensorflow_lite_support:users",
    ],
    licenses = ["notice"],  # Apache 2.0
)

cc_library(
    name = "score_calibration",
    srcs = ["score_calibration.cc"],
    hdrs = ["score_calibration.h"],
    deps = [
        "//third_party/absl/container:flat_hash_map",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/strings:str_format",
        "//third_party/absl/types:optional",
        "//third_party/tensorflow/lite/experimental/support/metadata:metadata_schema_cc",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/task/vision/core:label_map_item",
    ],
)

cc_library(
    name = "frame_buffer_common_utils",
    srcs = [
        "frame_buffer_common_utils.cc",
    ],
    hdrs = [
        "frame_buffer_common_utils.h",
        "frame_buffer_utils_interface.h",
    ],
    deps = [
        "//third_party/absl/base:core_headers",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/strings:str_format",
        "//third_party/absl/time",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/task/vision/core:frame_buffer",
    ],
)

cc_library(
    name = "frame_buffer_utils",
    srcs = [
        "frame_buffer_utils.cc",
    ],
    hdrs = [
        "frame_buffer_utils.h",
    ],
    deps = [
        ":frame_buffer_common_utils",
        ":libyuv_frame_buffer_utils",
        "//third_party/absl/base:core_headers",
        "//third_party/absl/memory",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/strings:str_format",
        "//third_party/absl/types:optional",
        "//third_party/absl/types:variant",
        "//third_party/tensorflow/lite/kernels:op_macros",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/task/vision/core:frame_buffer",
        "//third_party/tensorflow_lite_support/cc/task/vision/proto:bounding_box_proto_inc",
    ],
)

cc_library(
    name = "libyuv_frame_buffer_utils",
    srcs = ["libyuv_frame_buffer_utils.cc"],
    hdrs = ["libyuv_frame_buffer_utils.h"],
    deps = [
        ":frame_buffer_common_utils",
        "//third_party/absl/base:core_headers",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/strings:str_format",
        "//third_party/libyuv",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/task/vision/core:frame_buffer",
    ],
)

cc_library(
    name = "image_tensor_specs",
    srcs = ["image_tensor_specs.cc"],
    hdrs = ["image_tensor_specs.h"],
    deps = [
        "//third_party/absl/status",
        "//third_party/absl/types:optional",
        "//third_party/tensorflow/lite:framework",
        "//third_party/tensorflow/lite/c:common",
        "//third_party/tensorflow/lite/experimental/support/metadata:metadata_schema_cc",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/metadata/cc:metadata_extractor",
    ],
)
