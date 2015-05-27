cmake_minimum_required(VERSION 3.2)
project(KoreanSongs)

enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

link_directories(tests/gtest/lib)

add_subdirectory(Core)
add_subdirectory(tests)

add_executable(KoreanSongs main.cpp)
target_link_libraries(KoreanSongs Core)

add_test(Tests KoreanSongs)


