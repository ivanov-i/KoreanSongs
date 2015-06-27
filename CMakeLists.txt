cmake_minimum_required(VERSION 3.2)
project(KoreanSongs)

enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(BOOST_ROOT "/Users/zesst/boost/boost_1_58_0")
set(Boost_NO_SYSTEM_PATHS ON)

find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

include_directories(/Users/zesst/boost/boost_1_58_0)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

link_directories(tests/gtest/lib)

add_subdirectory(Core)
add_subdirectory(tests)

add_executable(KoreanSongs main.cpp)
target_link_libraries(KoreanSongs Core ${Boost_LIBRARY_DIR})

add_test(Tests KoreanSongs)

configure_file(songs.txt tests/songs.txt COPYONLy)