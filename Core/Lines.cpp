#include "Lines.h"
#include "Songs.h"

Lines::Lines(Songs &sink) : output(sink) {

}

void Lines::OnChar(char c) {
    if (c == '\n') {
        output.ProcessLine(currentLine);
        currentLine = std::string();
    }
    else if(c != '\r')
        currentLine += c;

}

void Lines::Flush() {
    if(currentLine.length() > 0)
        output.ProcessLine(currentLine);
    currentLine = std::string();
}