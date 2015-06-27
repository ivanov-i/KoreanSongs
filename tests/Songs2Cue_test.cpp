#include <gtest/gtest.h>
#include <Core/Songs2Cue.h>

namespace {

    class Songs2CueUnderTest : public Songs2Cue
    {
    public:
        Songs2CueUnderTest(std::ostream &out) : Songs2Cue(out) { }

    private:
        virtual std::string ConvertSingleSong(Song song) override
        {
            return "song";
        }
    };

    TEST(Songs2Cue, test)
    {
        std::ostringstream oss;
        auto processor = Songs2CueUnderTest(oss);
        processor.ProcessSong(Song::GetNull());
        processor.Flush();
    }
}
