package(
    default_visibility = ["//third_party/tensorflow_lite_support:users"],
    licenses = ["notice"],  # Apache 2.0
)

cc_library(
    name = "nl_classifier",
    srcs = [
        "nl_classifier.cc",
    ],
    hdrs = [
        "nl_classifier.h",
    ],
    deps = [
        "//third_party/absl/algorithm:container",
        "//third_party/absl/status",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/task/core:base_task_api",
        "//third_party/tensorflow_lite_support/cc/task/core:category",
        "//third_party/tensorflow_lite_support/cc/task/core:task_api_factory",
        "//third_party/tensorflow_lite_support/cc/task/core:task_utils",
        "//third_party/tensorflow_lite_support/cc/utils:common_utils",
    ],
)
