include_directories(SYSTEM gtest/include)

add_executable(Tests unit_test.cpp)

link_directories(gtest/lib)
include_directories(../Core)

target_link_libraries(Tests Core libgtest.a libgtest_main.a)

add_test(Test Test)