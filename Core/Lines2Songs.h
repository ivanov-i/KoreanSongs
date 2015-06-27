#pragma once

#include <string>

class Songs2Cue;
class Song;

class Lines2Songs {
public:
    Lines2Songs(Songs2Cue *songs2Cue);
    virtual void ProcessLine(std::string line);
    virtual void Flush();
private:
    Songs2Cue* output;
    virtual Song Str2Song(std::string str);
};