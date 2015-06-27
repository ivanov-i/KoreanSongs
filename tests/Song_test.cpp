#include <Core/Song.h>
#include <gtest/gtest.h>

namespace {

    TEST(Song, FromString_no_star) {
        auto song = Song(" 024 Two Ace(금과은)['75]A01 빗속을 둘이서(1:15:36)");
        EXPECT_EQ(24, song.Number());
        EXPECT_EQ("Two Ace(금과은)", song.Artist());
        EXPECT_EQ(75, song.Year());
        EXPECT_EQ("빗속을 둘이서", song.Title());
        EXPECT_EQ(1, song.Hour());
        EXPECT_EQ(15, song.Minute());
        EXPECT_EQ(36, song.Second());
    }

    TEST(Song, FromString_with_star) {
        auto song = Song("    037 사랑과 평화['78]A01 한동안 뜸 했었지2:01:11★");
        EXPECT_EQ(37, song.Number());
        EXPECT_EQ("사랑과 평화", song.Artist());
        EXPECT_EQ(78, song.Year());
        EXPECT_EQ("한동안 뜸 했었지", song.Title());
        EXPECT_EQ(2, song.Hour());
        EXPECT_EQ(1, song.Minute());
        EXPECT_EQ(11, song.Second());
    }

    TEST(Song, to_cue)
    {
        auto song = Song("24 artist name['2182]A01 the song has a title(3:01:25)");
        auto actual = song.ToCueString();
        auto expected = "TRACK 24 AUDIO\n"
                        "TITLE \"the song has a title\"\n"
                        "PERFORMER \"artist name\"\n"
                        "INDEX 01 181:25:00";
        EXPECT_EQ(expected, actual);
    }

}