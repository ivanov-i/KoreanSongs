#include "Lines2Songs.h"
#include <string>
#include "Songs2Cue.h"
#include <Core/Song.h>
#include <gtest/gtest.h>

namespace {

    class SongsSink : public Songs2Cue {
    public:
        SongsSink()
                : Songs2Cue()
        {

        }

        virtual void ProcessSong(Song song) override {
            songs.push_back(song);
        }
        std::vector<Song> songs;
    };

    class Lines2SongsUnderTest : public Lines2Songs{
    public:
        virtual Song Str2Song(std::string str) override
        {
            return Song::GetNull();
        }

        Lines2SongsUnderTest(Songs2Cue *songs2Cue) : Lines2Songs(songs2Cue) { }
    };

    class Lines2SongsTest : public ::testing::Test
    {
    public:
        Lines2SongsTest(){};
    };

    TEST_F(Lines2SongsTest, converts_to_songs) {
        auto line =   std::string(" some kind of line");
        auto testSink = SongsSink();
        auto processor = Lines2SongsUnderTest(&testSink);
        processor.ProcessLine(line);
        ASSERT_EQ(1, testSink.songs.size());
    }
}

