package(
    default_visibility = [
        "//visibility:public",
    ],
    licenses = ["notice"],  # Apache 2.0
)

cc_library(
    name = "object_detector",
    srcs = ["object_detector.cc"],
    hdrs = ["object_detector.h"],
    deps = [
        "//third_party/absl/container:flat_hash_set",
        "//third_party/absl/memory",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/strings:str_format",
        "//third_party/tensorflow/lite:framework",
        "//third_party/tensorflow/lite/c:common",
        "//third_party/tensorflow/lite/experimental/support/metadata:metadata_schema_cc",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/task/core:external_file_handler",
        "//third_party/tensorflow_lite_support/cc/task/core:task_utils",
        "//third_party/tensorflow_lite_support/cc/task/core:tflite_engine",
        "//third_party/tensorflow_lite_support/cc/task/vision/core:base_vision_task_api",
        "//third_party/tensorflow_lite_support/cc/task/vision/core:frame_buffer",
        "//third_party/tensorflow_lite_support/cc/task/vision/core:label_map_item",
        "//third_party/tensorflow_lite_support/cc/task/vision/proto:bounding_box_proto_inc",
        "//third_party/tensorflow_lite_support/cc/task/vision/proto:class_proto_inc",
        "//third_party/tensorflow_lite_support/cc/task/vision/proto:detections_proto_inc",
        "//third_party/tensorflow_lite_support/cc/task/vision/proto:object_detector_options_proto_inc",
        "//third_party/tensorflow_lite_support/cc/task/vision/utils:frame_buffer_utils",
        "//third_party/tensorflow_lite_support/cc/task/vision/utils:image_tensor_specs",
    ],
)
