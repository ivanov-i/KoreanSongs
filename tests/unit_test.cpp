#include "SplitLines.h"

#include <gtest/gtest.h>

TEST(LinesSplitter, empty_returns_empty)
{
    auto lines = SplitLines(L"");
    EXPECT_EQ(0, lines.size());
}

using namespace std::literals::string_literals;
const auto expected = L"one single line"s;
const auto N = 150u;

TEST(LinesSplitter, one_line_returns_the_same)
{
    auto lines = SplitLines(expected);
    ASSERT_EQ(1, lines.size());
    EXPECT_EQ(expected, lines[0]);
}

TEST(LinesSplitter, two_lines_returns_two_strings)
{
    const auto expected2 = L"one single line";
    auto lines = SplitLines(expected + L"\n" + expected2);
    ASSERT_EQ(2, lines.size());
    EXPECT_EQ(expected, lines[0]);
    EXPECT_EQ(expected2, lines[1]);
}

static std::wstring buildSampleText(std::wstring delimiter, size_t N) {
    auto text = std::wstring();
    auto lots = N;
    while(lots --> 0)
    {
        text += delimiter + expected;
    }

    text += delimiter;
    return text;
}

static void SplitAndVerify(std::wstring text) {
    auto lines = SplitLines(text);
    EXPECT_EQ(N, lines.size());
    for(auto actual : lines) {
        EXPECT_EQ(expected, actual);
    }
}

static void verifyDelimiter(std::wstring delimiter) {
    auto text = buildSampleText(delimiter, N);
    SplitAndVerify(text);
}

TEST(LinesSplitter, given_many_lines_returns_the_same_amount_of_strings)
{
    verifyDelimiter(L"\n");
    verifyDelimiter(L"\r\n");
}