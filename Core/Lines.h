#pragma once
#include <string>

class Songs;

class Lines {
public:
    Lines(Songs &sink);
    virtual void OnChar(char c);
    virtual void Flush();
private:
    Songs & output;
    std::string currentLine;
};
