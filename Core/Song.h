#pragma once
#include <string>

class Song {
public:
    Song(std::string line);
    virtual std::string ToString() const;
    static Song GetNull();

    int Number() const;
    std::string Artist() const;
    int Year() const;
    std::string Title() const;
    int Hour() const;
    int Minute() const;
    int Second() const;

private:
    void Parse();
    int number;
    std::string title;
    std::string artist;
    int year;
    int hour;
    int minute;
    int second;

    std::string line;
    Song();
};
