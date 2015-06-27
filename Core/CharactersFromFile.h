#pragma once

#include <string>

class Characters2Lines;

class CharactersFromFile {
public:
    CharactersFromFile(Characters2Lines* charactersProcessor);

    void ProcessFile(std::string file);

    Characters2Lines* output;
};
