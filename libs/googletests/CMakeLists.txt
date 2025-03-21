cmake_minimum_required(VERSION 3.28)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

project(TestsNote)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(Project main.cpp)
add_executable(Tests tests.cpp)

target_include_directories(Tests PRIVATE ${gtest_SOURCE_DIR}/googletest/include)
target_link_libraries(Tests gtest gtest_main)

enable_testing()
add_test(NAME Tests COMMAND Tests)