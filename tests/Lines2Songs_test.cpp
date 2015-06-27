#include "Lines2Songs.h"
#include <string>

#include <gtest/gtest.h>

namespace {

    class TestSongsSink : public Lines2Songs {
    };

    class Lines2SongsTest : public ::testing::Test
    {
    public:
        Lines2SongsTest();
    };

    Lines2SongsTest::Lines2SongsTest() {

    }

    TEST_F(Lines2SongsTest, a) {
//        037 사랑과 평화['78]A01 한동안 뜸 했었지2:01:11★
        auto line =   std::string(" 024 Two Ace(금과은)['75]A01 빗속을 둘이서(1:15:36)");

    }
}