package(
    default_visibility = ["//third_party/tensorflow_lite_support:users"],
    licenses = ["notice"],  # Apache 2.0
)

cc_library(
    name = "statusor",
    hdrs = [
        "statusor.h",
    ],
    deps = [
        "//tensorflow_lite_support/cc/port/default:statusor",
    ],
)

cc_library(
    name = "status_macros",
    hdrs = [
        "status_macros.h",
    ],
    deps = [
        "//tensorflow_lite_support/cc/port/default:status_macros",
    ],
)

cc_library(
    name = "tflite_wrapper",
    hdrs = [
        "tflite_wrapper.h",
    ],
    deps = [
        "//intelligence/mobile_acceleration/proto:whitelist_portable_proto",
        "//intelligence/mobile_acceleration/support_library:tflite_wrapper",
    ],
)
