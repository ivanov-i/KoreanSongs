include_directories(SYSTEM gtest/include)

add_executable(Tests unit_test.cpp)

link_directories(gtest/lib)

target_link_libraries(Tests libgtest.a libgtest_main.a)

add_test(Test Test)