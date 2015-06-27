#include <fstream>
#include "Characters.h"
#include "Lines.h"

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

void Characters::ProcessFile(std::string file, Lines &output) {
    auto ifs = std::ifstream(file);
    auto it = std::istreambuf_iterator<char>(ifs >> std::noskipws);
    for(auto c : irange<char>(ifs))
    {
        char expected = c;
        output.OnChar(c);
    }
    output.Flush();
}
