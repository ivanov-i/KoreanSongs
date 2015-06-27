#pragma once

#include <string>

class Songs2Cue;

class Lines2Songs {
public:
    Lines2Songs(Songs2Cue *songs2Cue);
    virtual void ProcessLine(std::string line);
private:
    Songs2Cue* output;
};