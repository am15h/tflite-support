package(
    default_visibility = ["//third_party/tensorflow_lite_support:users"],
    licenses = ["notice"],  # Apache 2.0
)

cc_library(
    name = "question_answerer",
    hdrs = [
        "question_answerer.h",
    ],
    deps = [
        "//third_party/tensorflow_lite_support/cc/task/core:base_task_api",
        "//third_party/tensorflow_lite_support/cc/task/core:tflite_engine",
    ],
)

cc_library(
    name = "bert_question_answerer",
    srcs = [
        "bert_question_answerer.cc",
    ],
    hdrs = [
        "bert_question_answerer.h",
    ],
    deps = [
        ":question_answerer",
        "//third_party/absl/container:flat_hash_map",
        "//third_party/absl/status",
        "//third_party/absl/strings",
        "//third_party/tensorflow_lite_support/cc/port:status_macros",
        "//third_party/tensorflow_lite_support/cc/port:statusor",
        "//third_party/tensorflow_lite_support/cc/task/core:base_task_api",
        "//third_party/tensorflow_lite_support/cc/task/core:task_api_factory",
        "//third_party/tensorflow_lite_support/cc/task/core:task_utils",
        "//third_party/tensorflow_lite_support/cc/task/core:tflite_engine",
        "//third_party/tensorflow_lite_support/cc/text/tokenizers:bert_tokenizer",
        "//third_party/tensorflow_lite_support/cc/text/tokenizers:sentencepiece_tokenizer",
    ],
)
