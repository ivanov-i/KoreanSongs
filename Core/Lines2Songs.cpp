#include "Lines2Songs.h"
#include "Song.h"
#include "Songs2Cue.h"

Lines2Songs::Lines2Songs(Songs2Cue *songs2Cue)
        : output(songs2Cue)
{
}

void Lines2Songs::ProcessLine(std::string line) {
    auto song = Str2Song(line);
    output->ProcessSong(song);
}

Song Lines2Songs::Str2Song(std::string str) {
    return Song(str);
}

void Lines2Songs::Flush() {
    output->Flush();
}
