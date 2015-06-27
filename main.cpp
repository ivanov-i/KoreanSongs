#include <iostream>
#include "Core/Characters.h"
#include "Core/Songs.h"
#include "Core/Lines.h"

using namespace std;

class PrintSong : public Songs
{
public:
    virtual void ProcessLine(std::string line) override;
};

int main() {
    auto characters = Characters();
    auto printer = PrintSong();
    auto lines = Lines(printer);
    characters.ProcessFile("songs.txt", lines);
    return 0;
}

void PrintSong::ProcessLine(std::string line) {
    std::cout << line << std::endl;
}
