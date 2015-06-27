#pragma once

#include <string>

class Lines;

class Characters {
public:
    void ProcessFile(std::string file, Lines &nextHandler);
};
