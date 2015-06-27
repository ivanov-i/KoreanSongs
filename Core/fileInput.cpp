#include <fstream>
#include "fileInput.h"
#include "CharInput.h"

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

void fileInput::ProcessFile(std::string file, CharInput &output) {
    auto ifs = std::ifstream(file);
    auto it = std::istreambuf_iterator<char>(ifs >> std::noskipws);
    for(auto c : irange<char>(ifs))
    {
        char expected = c;
        output.OnChar(c);
    }
}
