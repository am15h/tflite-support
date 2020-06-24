workspace(name = "org_tensorflow_lite_support")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "io_bazel_rules_closure",
    sha256 = "5b00383d08dd71f28503736db0500b6fb4dda47489ff5fc6bed42557c07c6ba9",
    strip_prefix = "rules_closure-308b05b2419edb5c8ee0471b67a40403df940149",
    urls = [
        "https://storage.googleapis.com/mirror.tensorflow.org/github.com/bazelbuild/rules_closure/archive/308b05b2419edb5c8ee0471b67a40403df940149.tar.gz",
        "https://github.com/bazelbuild/rules_closure/archive/308b05b2419edb5c8ee0471b67a40403df940149.tar.gz",  # 2019-06-13
    ],
)

# Apple and Swift rules.
# https://github.com/bazelbuild/rules_apple/releases
http_archive(
    name = "build_bazel_rules_apple",
    sha256 = "ee9e6073aeb5a65c100cb9c44b0017c937706a4ae03176e14a7e78620a198079",
    strip_prefix = "rules_apple-5131f3d46794bf227d296c82f30c2499c9de3c5b",
    urls = [
        "https://storage.googleapis.com/mirror.tensorflow.org/github.com/bazelbuild/rules_apple/archive/5131f3d46794bf227d296c82f30c2499c9de3c5b.tar.gz",
        "https://github.com/bazelbuild/rules_apple/archive/5131f3d46794bf227d296c82f30c2499c9de3c5b.tar.gz",
    ],
)

# https://github.com/bazelbuild/rules_swift/releases
http_archive(
    name = "build_bazel_rules_swift",
    sha256 = "d0833bc6dad817a367936a5f902a0c11318160b5e80a20ece35fb85a5675c886",
    strip_prefix = "rules_swift-3eeeb53cebda55b349d64c9fc144e18c5f7c0eb8",
    urls = [
        "https://storage.googleapis.com/mirror.tensorflow.org/github.com/bazelbuild/rules_swift/archive/3eeeb53cebda55b349d64c9fc144e18c5f7c0eb8.tar.gz",
        "https://github.com/bazelbuild/rules_swift/archive/3eeeb53cebda55b349d64c9fc144e18c5f7c0eb8.tar.gz",
    ],
)

http_archive(
    name = "org_tensorflow",
    strip_prefix = "tensorflow-2.2.0",
    sha256 = "fd3e6580cfe2035aa80d569b76bba5f33119362907f3d77039b6bedf76172712",
    urls = [
        "https://github.com/tensorflow/tensorflow/archive/v2.2.0.zip"
    ],
)

http_archive(
    name = "com_google_sentencepiece",
    strip_prefix = "sentencepiece-1.0.0",
    sha256 = "c05901f30a1d0ed64cbcf40eba08e48894e1b0e985777217b7c9036cac631346",
    urls = [
        "https://github.com/google/sentencepiece/archive/1.0.0.zip",
    ],
)

# tf_http_archive(
#     name = "org_tensorflow_text",
#     sha256 = "83e4ed74661b5ec6a956f45edf515b26e5ac7b357ee1382146117dfa47729b61",
#     strip_prefix = "text-2.1.1",
#     urls = [
#         "http://mirror.tensorflow.org/github.com/tensorflow/text/archive/v2.1.1.zip",
#         "https://github.com/tensorflow/text/archive/v2.1.1.zip",
#     ],
#     patch_file = clean_dep("//third_party:tensorflow_text_fix_local_config_tf.patch"),
# )

http_archive(
    name = "org_tensorflow_text",
    sha256 = "f64647276f7288d1b1fe4c89581d51404d0ce4ae97f2bcc4c19bd667549adca8",
    strip_prefix = "text-2.2.0",
    urls = [
        "https://github.com/tensorflow/text/archive/v2.2.0.zip",
    ],
    patch_file = clean_dep("//third_party:tensorflow_text_fix_local_config_tf.patch"),
)

http_archive(
    name = "com_googlesource_code_re2",
    sha256 = "d070e2ffc5476c496a6a872a6f246bfddce8e7797d6ba605a7c8d72866743bf9",
    strip_prefix = "re2-506cfa4bffd060c06ec338ce50ea3468daa6c814",
    urls = [
        "https://github.com/google/re2/archive/506cfa4bffd060c06ec338ce50ea3468daa6c814.tar.gz",
    ],
)

# do we need this?
# http_archive(
#     name = "com_google_glog",
#     sha256 = "1ee310e5d0a19b9d584a855000434bb724aa744745d5b8ab1855c85bff8a8e21",
#     strip_prefix = "glog-028d37889a1e80e8a07da1b8945ac706259e5fd8",
#     urls = [
#         "https://mirror.bazel.build/github.com/google/glog/archive/028d37889a1e80e8a07da1b8945ac706259e5fd8.tar.gz",
#         "https://github.com/google/glog/archive/028d37889a1e80e8a07da1b8945ac706259e5fd8.tar.gz",
#     ],
# )

# Configure TF.
load("@org_tensorflow//tensorflow:workspace.bzl", "tf_workspace")

tf_workspace(tf_repo_name="@org_tensorflow")

load("//third_party/tensorflow:tf_configure.bzl", "tf_configure")

tf_configure(name = "local_config_tf")


# Configure Android.
load("//third_party/android:android_configure.bzl", "android_configure")

android_configure(name="local_config_android")

load("@local_config_android//:android.bzl", "android_workspace")

android_workspace()
