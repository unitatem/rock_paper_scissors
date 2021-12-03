set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)

add_executable(app
    main.cpp
    RockPaperScissors.cpp)
target_link_libraries(app
    GameInterface)

add_library(GameInterface SHARED
    CommandLineInterface.cpp
    GameInterface.cpp)
