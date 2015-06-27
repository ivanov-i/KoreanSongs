#include <iostream>
#include "Core/CharactersFromFile.h"
#include "Core/Lines2Songs.h"
#include "Core/Characters2Lines.h"

using namespace std;

class PrintSong : public Lines2Songs
{
public:
    virtual void ProcessLine(std::string line) override;
};

int main() {
    auto printer = PrintSong();
    auto lines = Characters2Lines(printer);
    auto characters = CharactersFromFile(lines);
    characters.ProcessFile("songs.txt");
    return 0;
}

void PrintSong::ProcessLine(std::string line) {
    std::cout << line << std::endl;
}
