#include "Core.h"

#include <gtest/gtest.h>

TEST(LinesSplitter, empty_returns_empty)
{
    auto lines = SplitLines(L"");
    ASSERT_EQ(0, lines.size());
}

using namespace std::literals::string_literals;
const auto expected = L"one single line"s;

TEST(LinesSplitter, one_line_returns_the_same)
{
    auto lines = SplitLines(expected);
    ASSERT_EQ(1, lines.size());
    ASSERT_EQ(expected, lines[0]);
}


TEST(LinesSplitter, two_lines_returns_two_strings)
{
    auto expected2 = L"one single line";
    auto lines = SplitLines(expected + L"\n" + expected2);
    ASSERT_EQ(2, lines.size());
    ASSERT_EQ(expected, lines[0]);
    ASSERT_EQ(expected2, lines[1]);
}

TEST(LinesSplitter, given_many_lines_returns_the_same_amount_of_strings)
{
    const auto N = 150u;
    auto lots = N;
    auto text = std::wstring();
    while(lots --> 0)
    {
        text += L"\n" + expected;
    }

    text += L'\n';

    auto lines = SplitLines(text);
    ASSERT_EQ(N, lines.size());
    std::for_each(std::begin(lines), std::end(lines),
                  [](const std::wstring& actual)
                  {
                      ASSERT_EQ(expected, actual);
                  });
}

//
//
//TEST(LinesSplitter, crlf_is_equal_to_cr)
//{
//    auto lots = 150u;
//    auto text = std::wstring();
//    while(lots --> 0)
//    {
//        text += L"\n" + expected + ;
//    }
//
//    text += L'\n';
//
//    auto lines = SplitLines(text);
//    ASSERT_EQ(151, lines.size());
//}