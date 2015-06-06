#include "SplitLines.h"

static std::wstring RemoveCRs(std::wstring text) {
    text.erase(remove(begin(text), end(text), L'\r'), end(text));
    return text;
}

static size_t FindNextLineBreak(const std::wstring &text) {
    auto linebreak = text.find(L'\n');

    if (linebreak == text.npos)
        return text.length();
    else
        return linebreak;
}

static std::wstring Cut(const std::wstring &text, size_t linebreak) {
    if(linebreak+1 >= text.length())
        return std::wstring();
    else
        return text.substr(linebreak + 1, text.length() - linebreak + 1);
}

static void ProcessOneLine(std::wstring &text, std::vector<std::wstring> &result) {
    auto linebreak = FindNextLineBreak(text);

    const auto line = text.substr(0, linebreak);
    if(!line.empty())
        result.push_back(line);

    text = Cut(text, linebreak);
}

static std::vector<std::wstring> splitByLineFeeds(std::wstring text) {
    auto result = std::vector<std::wstring>();
    while(text.length() > 0)
        ProcessOneLine(text, result);
    return result;
}

std::vector<std::wstring> SplitLines(std::wstring text) {
    text = RemoveCRs(text);
    return splitByLineFeeds(text);
}