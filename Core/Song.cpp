#include "Song.h"

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
    number = std::stoi(line, &nameOffset, 10);
    auto nameBegin = std::next(std::begin(line), nameOffset);
    nameBegin = std::find_if_not(nameBegin, std::end(line), std::isspace);
    auto nameEnd = std::find(nameBegin, std::end(line), '[');
    name.assign(nameBegin, nameEnd);
}

Song Song::GetNull() {
    return Song();
}

Song::Song()
:number(0)
{

}
