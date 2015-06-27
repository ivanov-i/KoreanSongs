#pragma once
#include <string>

class Song {
public:
    Song(std::string line);
    virtual std::string ToString() const;
    static Song GetNull();

    int Number() const;
    std::string Name() const;
    int Year() const;

private:
    void Parse();
    int number;
    std::string name;
    int year;

    std::string line;
    Song();
};
