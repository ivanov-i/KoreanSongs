#pragma once

#include "Song.h"

class Song;

class Songs2Cue {
public:
    Songs2Cue(std::ostream &out);
    virtual void ProcessSong(Song song);
    virtual void Flush();
private:
    virtual std::string ConvertSingleSong(Song song);
    std::ostream& output;
};
