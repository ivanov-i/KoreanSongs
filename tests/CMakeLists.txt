include_directories(SYSTEM gtest/include)

add_executable(Tests Characters2Lines_test.cpp File2Characters_test.cpp Lines2Songs_test.cpp Song_test.cpp)

link_directories(gtest/lib)
include_directories(../Core)

target_link_libraries(Tests Core libgtest.a libgtest_main.a ${Boost_LIBRARY_DIR})

add_test(Test Test)