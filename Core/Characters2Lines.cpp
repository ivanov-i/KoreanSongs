#include "Characters2Lines.h"
#include "Lines2Songs.h"

Characters2Lines::Characters2Lines(Lines2Songs &sink) : output(sink) {

}

void Characters2Lines::OnChar(char c) {
    if (c == '\n') {
        output.ProcessLine(currentLine);
        currentLine = std::string();
    }
    else if(c != '\r')
        currentLine += c;

}

void Characters2Lines::Flush() {
    if(currentLine.length() > 0)
        output.ProcessLine(currentLine);
    currentLine = std::string();
}