set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin)

add_executable(app
    main.cpp
    game/RockPaperScissors.cpp)
target_link_libraries(app
    AlgorithmicPlayer
    GameInterface)

add_library(GameInterface SHARED
    interface/CommandLineInterface.cpp
    interface/GameInterface.cpp)

add_library(AlgorithmicPlayer SHARED
    algo_player/AlgorithmicPlayer.cpp
    algo_player/RandomPlayer.cpp)
