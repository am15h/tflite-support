package(
    default_visibility = [
        "//third_party/tensorflow/lite/experimental/support:users",
        "//third_party/tensorflow_lite_support:users",
    ],
    licenses = ["notice"],  # Apache 2.0
)

cc_library(
    name = "metadata_extractor",
    srcs = ["metadata_extractor.cc"],
    hdrs = ["metadata_extractor.h"],
    deps = [
        "//third_party/absl/container:flat_hash_map",
        "//third_party/absl/memory",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/absl/strings:str_format",
        "//third_party/flatbuffers",
        "//third_party/libzip:zip",
        "//third_party/tensorflow/lite:framework",
        "//third_party/tensorflow/lite/experimental/support/metadata:metadata_schema_cc",
        "//third_party/tensorflow/lite/schema:schema_fbs",
        "//third_party/tensorflow/lite/tools:verifier",
        "//third_party/tensorflow_lite_support/cc:common",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
    ],
)
