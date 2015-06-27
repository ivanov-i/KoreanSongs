#include "Songs2Cue.h"
#include "Song.h"

Songs2Cue::Songs2Cue(std::ostream &out)
        : output(out)
{
};

void Songs2Cue::ProcessSong(Song song) {

}

std::string Songs2Cue::ConvertSingleSong(Song song) {
    return song.ToCueString();
}

void Songs2Cue::Flush() {

}
