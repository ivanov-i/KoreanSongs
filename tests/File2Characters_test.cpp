#include <gtest/gtest.h>
#include <fstream>
#include "Lines2Songs.h"
#include "CharactersFromFile.h"
#include "Characters2Lines.h"

namespace {

    class testCharInput : public Characters2Lines
    {

    public:
        testCharInput(std::string &actual)
                : Characters2Lines(sink),
                  str(actual),
                  flushCalled(false)
        {
        }

        virtual void OnChar(char c) override {
            str += c;
        };

        virtual void Flush() override {
            flushCalled = true;
        }

        std::string& str;
        Lines2Songs sink;
        bool flushCalled;
    };

    std::string ReadFile() {
        std::ifstream t("songs.txt");
        t.seekg(0, std::ios::end);
        auto result = std::string();
        result.reserve(t.tellg());
        t.seekg(0, std::ios::beg);

        result.assign((std::istreambuf_iterator<char>(t)),
                        std::istreambuf_iterator<char>());

        return result;
    }

    TEST(FileInput, reads_file){
        auto actual = std::string();
        auto expected = ReadFile();
        auto testSink = testCharInput(actual);
        auto input = CharactersFromFile(testSink);
        input.ProcessFile("songs.txt");
        EXPECT_EQ(expected, actual);
        EXPECT_TRUE(testSink.flushCalled);
    }

}
