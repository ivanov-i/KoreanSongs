#pragma once
#include <string>

class Song {
public:
    Song(std::string line);
    virtual std::string ToString() const;
    static Song GetNull();

    int Number() const;
    std::string Name() const;

private:
    void Parse();
    int number;
    std::string name;
    std::string line;

    Song();
};
