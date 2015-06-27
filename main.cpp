#include <iostream>
#include <Core/Song.h>
#include "Core/CharactersFromFile.h"
#include "Core/Lines2Songs.h"
#include "Core/Characters2Lines.h"
#include "Core/Songs2Cue.h"

int main() {
    auto songs2cue = Songs2Cue(std::cout);
    auto songs = Lines2Songs(&songs2cue);
    auto lines = Characters2Lines(&songs);
    auto characters = CharactersFromFile(&lines);
    characters.ProcessFile("songs.txt");
    return 0;
}
