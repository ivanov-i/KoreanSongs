#pragma once
#include <string>

class Song {
public:
    Song(std::string basic_string);

    virtual std::string ToString() const;
};
