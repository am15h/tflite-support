package(
    default_visibility = [
        "//visibility:public",
    ],
    licenses = ["notice"],  # Apache 2.0
)

exports_files(srcs = ["base_vision_task_api.h"])

cc_library(
    name = "base_vision_task_api",
    hdrs = [
        "base_vision_task_api.h",
    ],
    deps = [
        ":frame_buffer",
        "//third_party/absl/base:core_headers",
        "//third_party/absl/memory",
        "//third_party/absl/status",
        "//third_party/absl/time",
        "//third_party/tensorflow/lite/c:common",
        "//third_party/tensorflow/lite/experimental/support/metadata:metadata_schema_cc",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/task/core:base_task_api",
        "//third_party/tensorflow_lite_support/cc/task/core:task_utils",
        "//third_party/tensorflow_lite_support/cc/task/core:tflite_engine",
        "//third_party/tensorflow_lite_support/cc/task/vision/proto:bounding_box_proto_inc",
        "//third_party/tensorflow_lite_support/cc/task/vision/utils:frame_buffer_utils",
        "//third_party/tensorflow_lite_support/cc/task/vision/utils:image_tensor_specs",
    ],
)

cc_library(
    name = "frame_buffer",
    srcs = ["frame_buffer.cc"],
    hdrs = ["frame_buffer.h"],
    deps = [
        "//third_party/absl/base:core_headers",
        "//third_party/absl/memory",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/time",
        "//third_party/absl/types:any",
        "//third_party/absl/types:optional",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
    ],
)

cc_library(
    name = "label_map_item",
    srcs = ["label_map_item.cc"],
    hdrs = ["label_map_item.h"],
    deps = [
        "//third_party/absl/container:flat_hash_map",
        "//third_party/absl/container:flat_hash_set",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/strings:str_format",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
    ],
)

cc_library(
    name = "classification_head",
    srcs = ["classification_head.cc"],
    hdrs = ["classification_head.h"],
    deps = [
        ":label_map_item",
        "//third_party/absl/memory",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/tensorflow/lite/experimental/support/metadata:metadata_schema_cc",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/task/vision/utils:score_calibration",
        "//third_party/tensorflow_lite_support/metadata/cc:metadata_extractor",
    ],
)
