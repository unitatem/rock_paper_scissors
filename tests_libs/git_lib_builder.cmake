# The following code to fetch and build library from git is inspired by and adapted after:
# https://crascit.com/2015/07/25/cmake-gtest/
# https://github.com/bast/gtest-demo
# https://github.com/abseil/googletest/blob/master/googletest/README.md

# Brief: Download, confgiure and build library from GitHub
#
# _project_name name of the project folder that should be created in build directory
# _binary_dir directory where project folder with srouce code and build binaries should be located
#
macro(git_lib_build _project_name _binary_dir)
    # defines where all library source files will be downloaded and builded
    set(_project_root ${_binary_dir}/${_project_name})

    # congiure download specification
    set(DESTINATION_ROOT ${_project_root})
    configure_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/${_project_name}-download.cmake
            ${_project_root}/CMakeLists.txt
            @ONLY
    )
    unset(DESTINATION_ROOT)

    # run generator to generate makefiles or project files
    execute_process(
            COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
            WORKING_DIRECTORY ${_project_root}
    )
    # execute build on first level files -> download git repository
    execute_process(
            COMMAND "${CMAKE_COMMAND}" --build .
            WORKING_DIRECTORY ${_project_root}
    )

    # run build specified in Makefile from target project located in *-src directory, generated binary files will end up in *-build directory
    add_subdirectory(
            ${_project_root}/${_project_name}-src
            ${_project_root}/${_project_name}-build
    )
endmacro()
