#pragma once
#include <string>

class Lines2Songs;

class Characters2Lines {
public:
    Characters2Lines(Lines2Songs *sink);
    virtual void OnChar(char c);
    virtual void Flush();
private:
    Lines2Songs * output;
    std::string currentLine;
};
