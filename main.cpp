#include <iostream>
#include <Core/Song.h>
#include "Core/CharactersFromFile.h"
#include "Core/Lines2Songs.h"
#include "Core/Characters2Lines.h"
#include "Core/Songs2Cue.h"

class Printer : public Songs2Cue
{
public:
    virtual void ProcessSong(Song & song) override
    {
        auto line = song.ToString();
        std::cout << line << std::endl;
    }
};

int main() {
    auto printer = Printer();
    auto songs = Lines2Songs(&printer);
    auto lines = Characters2Lines(&songs);
    auto characters = CharactersFromFile(&lines);
    characters.ProcessFile("songs.txt");
    return 0;
}
