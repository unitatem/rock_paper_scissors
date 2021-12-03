cmake_minimum_required(VERSION 3.10)
project(rock_paper_scissors)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(TESTS "enable tests" ON)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wshadow
    -Wnon-virtual-dtor
    # -pedantic Disabled because GoogleTest introduces polution
    )

include_directories(include)
add_subdirectory(src)

if (TESTS)
    add_subdirectory(tests_libs)
    add_subdirectory(tests)
endif ()
