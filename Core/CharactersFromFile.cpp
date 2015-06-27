#include <fstream>
#include "CharactersFromFile.h"
#include "Characters2Lines.h"

CharactersFromFile::CharactersFromFile(Characters2Lines *charactersProcessor)
        : output(charactersProcessor)
{
}

template <typename T>
struct irange
{
    irange(std::istream& in): d_in(in) {}
    std::istream& d_in;
};
template <typename T>
std::istream_iterator<T> begin(irange<T> r) {
    return std::istream_iterator<T>(r.d_in);
}
template <typename T>
std::istream_iterator<T> end(irange<T>) {
    return std::istream_iterator<T>();
}

void CharactersFromFile::ProcessFile(std::string file) {
    auto ifs = std::ifstream(file);
    auto it = std::istreambuf_iterator<char>(ifs >> std::noskipws);
    for(auto c : irange<char>(ifs))
    {
        char expected = c;
        output->OnChar(c);
    }
    output->Flush();
}
