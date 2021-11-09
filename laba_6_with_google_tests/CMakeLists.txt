cmake_minimum_required(VERSION 3.20)
project(laba_6_with_google_tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(laba_6_with_google_tests main.cpp proper_fraction.cpp proper_fraction.h)



# 'Google_test' is the subproject name
project(Google_test)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run proper_fraction.h proper_fraction.cpp google_tests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)