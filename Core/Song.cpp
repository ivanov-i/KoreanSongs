#include "Song.h"


Song::Song()
        :number(0),
        year(0)
{

}

std::string Song::ToString() const {
    return 0;
}

Song::Song(std::string str)
:line(str)
{
    Parse();
}

void Song::Parse() {
    size_t artistOffset = 0;
    number = std::stoi(line, &artistOffset);
    auto artistBegin = std::next(std::begin(line), artistOffset);
    artistBegin = std::find_if_not(artistBegin, std::end(line), std::isspace);
    auto artistEnd = std::find(artistBegin, std::end(line), '[');
    artist.assign(artistBegin, artistEnd);
    auto yearBegin = std::find_if(artistEnd, std::end(line), [](char c){return c == '\'';});
    yearBegin++;
    size_t yearEndOffset = 0;
    auto yearStr = std::string(yearBegin, std::end(line));
    year = std::stoi(yearStr, &yearEndOffset);
    auto titleBegin = std::distance(std::begin(line), yearBegin) + yearEndOffset + 5;
    auto titleEnd = line.find_last_of('(');
    if(line[line.length() - 1] != ')')
    {
        for(titleEnd = line.length() - 1 - 7; titleEnd >= titleBegin; titleEnd--)
        {
            auto c = line[titleEnd];
            if(!std::isdigit(c) && c != ':')
                break;
        }
        titleEnd++;
    }
    title = line.substr(titleBegin, titleEnd - titleBegin);
}

int Song::Number() const {
    return number;
}

std::string Song::Artist() const {
    return artist;
}

Song Song::GetNull() {
    return Song();
}

int Song::Year() const {
    return year;
}

std::string Song::Title() const{
    return title;
}