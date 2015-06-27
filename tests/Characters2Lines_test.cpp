#include "Characters2Lines.h"
#include "Lines2Songs.h"

#include <gtest/gtest.h>

namespace {

    class LinesSink : public Lines2Songs {

    public:
        LinesSink() : Lines2Songs(nullptr)
        {
        }

        virtual void ProcessLine(std::string line) override {
            lines.push_back(line);
        }
        std::vector<std::string> lines;
    };

    class Characters2LinesTest : public ::testing::Test
    {
    public:
        Characters2LinesTest();
        void SendData(std::string data);
        LinesSink sink;
        Characters2Lines lines;
    };

    Characters2LinesTest::Characters2LinesTest() : lines(&sink) {

    }

    void Characters2LinesTest::SendData(std::string data)
    {
        for(auto c : data)
        {
            lines.OnChar(c);
        }
        lines.Flush();
    }

    TEST_F(Characters2LinesTest, when_no_crlf_then_single_line) {
        auto testData = std::string("asdfasdfasdfasf");
        SendData(testData);
        ASSERT_EQ(1, sink.lines.size());
        EXPECT_EQ(testData, sink.lines[0]);
    }

    TEST_F(Characters2LinesTest, when_one_crlf_then_two_lines) {
        auto line1 = "eklmnoprst";
        auto line2 = "128942lsdkjcxhdva";
        auto testData = std::string(line1) +"\r\n"+ line2;
        SendData(testData);
        ASSERT_EQ(2, sink.lines.size());
        EXPECT_EQ(line1, sink.lines[0]);
        EXPECT_EQ(line2, sink.lines[1]);
    }
}