#include <iostream>
#include <sstream>
#include <fstream>
#include "Core/CharactersFromFile.h"
#include "Core/Lines2Songs.h"
#include "Core/Characters2Lines.h"
#include "Core/Songs2Cue.h"

int main() {
    std::ofstream ofs("/Users/zesst/ofs");
    auto songs2cue = Songs2Cue(ofs);
    auto songs = Lines2Songs(&songs2cue);
    auto lines = Characters2Lines(&songs);
    auto characters = CharactersFromFile(&lines);
    characters.ProcessFile("songs.txt");
    return 0;
}
