package(
    default_visibility = [
        "//third_party/tensorflow_lite_support/cc/port:__pkg__",
        "//third_party/tensorflow_lite_support/cc/test:__pkg__",
    ],
    licenses = ["notice"],  # Apache 2.0
)

# TODO(b/155676035): replace base:logging with glog/logging when OSSing.
cc_library(
    name = "statusor",
    srcs = ["statusor.cc"],
    hdrs = [
        "statusor.h",
        "statusor_internals.h",
    ],
    deps = [
        "//base:logging",
        "//third_party/absl/base:core_headers",
        "//third_party/absl/meta:type_traits",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/types:variant",
        "//third_party/absl/utility",
    ],
)

cc_library(
    name = "status_macros",
    hdrs = [
        "status_macros.h",
    ],
    compatible_with = [
        "//buildenv/target:appengine",
        "//buildenv/target:gce",
        "//buildenv/target:mobile",
        "//buildenv/target:non_prod",
        "//buildenv/target:vendor",
    ],
    deps = [
        "//third_party/absl/base:core_headers",
        "//third_party/absl/status",
    ],
)

cc_library(
    name = "tflite_wrapper",
    srcs = ["tflite_wrapper.cc"],
    hdrs = [
        "tflite_wrapper.h",
    ],
    deps = [
        "//third_party/absl/status",
        "//third_party/tensorflow/lite:framework",
        "//third_party/tensorflow/lite/experimental/acceleration/configuration:configuration_cc_proto",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
    ],
)
