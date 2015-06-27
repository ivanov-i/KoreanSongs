#include <Core/Song.h>
#include <gtest/gtest.h>

namespace {

    TEST(Song, FromString) {
//        037 사랑과 평화['78]A01 한동안 뜸 했었지2:01:11★
        auto song = Song(" 024 Two Ace(금과은)['75]A01 빗속을 둘이서(1:15:36)");
        EXPECT_EQ(24, song.Number());
        EXPECT_EQ("Two Ace(금과은)", song.Name());
        EXPECT_EQ(75, song.Year());
    }

}