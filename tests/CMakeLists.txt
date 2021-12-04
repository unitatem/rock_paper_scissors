enable_testing()

include(GoogleTest)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/tests)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/bin/tests)

add_executable(CommandLineInterface_test CommandLineInterface_test.cpp)
target_link_libraries(CommandLineInterface_test
  gtest gmock_main
  GameInterface)
gtest_discover_tests(CommandLineInterface_test)

add_executable(DefaultRules_test DefaultRules_test.cpp)
target_link_libraries(DefaultRules_test
  gtest gmock_main
  Game)
gtest_discover_tests(DefaultRules_test)

add_executable(RandomPlayer_test RandomPlayer_test.cpp)
target_link_libraries(RandomPlayer_test
  gtest gmock_main
  AlgorithmicPlayer)
gtest_discover_tests(RandomPlayer_test)

add_executable(RockPaperScissors_test RockPaperScissors_test.cpp)
target_link_libraries(RockPaperScissors_test
  gtest gmock_main
  AlgorithmicPlayer
  Game
  GameInterface)
gtest_discover_tests(RockPaperScissors_test)
