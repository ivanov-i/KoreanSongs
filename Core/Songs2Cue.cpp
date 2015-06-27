#include "Songs2Cue.h"

Songs2Cue::Songs2Cue(std::ostream &out)
        : output(out),
        headerPrinted(false)
{
};

void Songs2Cue::ProcessSong(Song song) {
    PrintHeaderIfNeeded();
    output << ConvertSingleSong(song) << std::endl;
}

std::string Songs2Cue::ConvertSingleSong(Song song) {
    return song.ToCueString();
}

void Songs2Cue::Flush() {
}

void Songs2Cue::PrintHeaderIfNeeded() {
    if(headerPrinted)
        return;

    output << "REM GENRE Pop\nTITLE \"Korean pop music before K-pop\"\n";
    headerPrinted = true;
}
