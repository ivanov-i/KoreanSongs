#include <sstream>
#include "Song.h"
#include <string>


Song::Song()
        :number(0),
        year(0),
        hour(0),
        minute(0),
        second(0)
{

}

std::string Song::ToCueString() const {
    auto oss = std::ostringstream();
    oss << "TRACK "<< Number() << " AUDIO" << std::endl << 
                   "TITLE \"" << Title() << "\"" << std::endl <<
                   "PERFORMER \"" << Artist() << "\"" << std::endl <<
                   "INDEX 01 " << Hour()*60 + Minute() << ':' << Second() << ":00";
    return oss.str();
}

#include <iostream>
Song::Song(std::string str)
:line(str)
{
    Parse();
}
void Song::Parse() {
    auto str = line;

    size_t artistOffset = 0;
    number = std::stoi(line, &artistOffset);
    str = str.substr(artistOffset);

    auto artistBeginIt = std::find_if_not(std::begin(str), std::end(str), [](char c){return std::isspace(c);});
    auto artistBegin = std::distance(std::begin(str), artistBeginIt);
    str = str.substr(artistBegin);

    auto artistEnd = str.find('[');
    artist = str.substr(0, artistEnd);
    str = str.substr(artistEnd, std::string::npos);

    auto yearBeginit = std::find_if(std::begin(str), std::end(str), [](char c){return c == '\'' || c == '`';});
    auto yearBegin = std::distance(std::begin(str), yearBeginit)  + 1;
    str = str.substr(yearBegin);

    size_t yearEnd = 0;
    year = std::stoi(str, &yearEnd);
    str = str.substr(yearEnd + 5);

    auto titleEnd = str.find_last_of('(');
    auto noBrackets = line[line.length() - 1] != ')';
    if(noBrackets)
    {
        for(titleEnd = str.length() - 1 - 7; titleEnd > 0u; titleEnd--)
        {
            auto c = str[titleEnd];
            if(!std::isdigit(c) && c != ':')
                break;
        }
        titleEnd++;
    }
    title = str.substr(0, titleEnd);

    str = str.substr(titleEnd);

    if(!noBrackets)
        str = str.substr(1);
    size_t hourEnd = 0;
    hour = std::stoi(str, &hourEnd);

    str = str.substr(hourEnd+1);
    size_t minuteEnd = 0;
    minute = std::stoi(str, &minuteEnd);

    str = str.substr(minuteEnd+1);
    second = std::stoi(str);
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

int Song::Hour() const {
    return hour;
}

int Song::Minute() const {
    return minute;
}

int Song::Second() const {
    return second;
}
