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

int Song::Number() const {
    return number;
}

std::string Song::Name() const {
    return name;
}

void Song::Parse() {
    size_t nameOffset = 0;
    number = std::stoi(line, &nameOffset);
    auto nameBegin = std::next(std::begin(line), nameOffset);
    nameBegin = std::find_if_not(nameBegin, std::end(line), std::isspace);
    auto nameEnd = std::find(nameBegin, std::end(line), '[');
    name.assign(nameBegin, nameEnd);
    auto yearBegin = std::find_if(nameEnd, std::end(line), [](char c){return c == '\'';});
    yearBegin++;
    size_t yearEndOffset = 0;
    auto yearStr = std::string(yearBegin, std::end(line));
    year = std::stoi(yearStr, &yearEndOffset);
}

Song Song::GetNull() {
    return Song();
}

int Song::Year() const {
    return year;
}
