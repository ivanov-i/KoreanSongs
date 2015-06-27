#include "Lines2Songs.h"
#include <string>
#include "Songs2Cue.h"
#include <Core/Song.h>
#include <gtest/gtest.h>

namespace {

    class SongsSink : public Songs2Cue {
    public:
        virtual void Flush() override
        {
            flushCalled = true;
        }

        SongsSink()
                : Songs2Cue(oss),
                flushCalled(false)
        {

        }

        virtual void ProcessSong(Song song) override {
            songs.push_back(song);
        }
        std::vector<Song> songs;
        std::ostringstream oss;
        bool flushCalled;
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
        Lines2SongsTest()
            :processor(&sink)
        {

        };
        SongsSink sink;
        Lines2SongsUnderTest processor;
    };

    TEST_F(Lines2SongsTest, converts_to_songs) {
        auto line =   std::string(" some kind of line");
        processor.ProcessLine(line);
        ASSERT_EQ(1, sink.songs.size());
    }

    TEST_F(Lines2SongsTest, calls_flush)
    {
        processor.Flush();
        EXPECT_TRUE(sink.flushCalled);
    }
}