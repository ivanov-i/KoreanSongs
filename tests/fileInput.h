#pragma once

#include <string>

class CharInput;

class fileInput {
public:
    void ProcessFile(std::string file, CharInput &nextHandler);
};
