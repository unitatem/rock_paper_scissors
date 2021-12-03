# ref https://github.com/abseil/googletest/blob/master/googletest/README.md

cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
        SOURCE_DIR "@DESTINATION_ROOT@/googletest-src"
        BINARY_DIR "@DESTINATION_ROOT@/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        )
