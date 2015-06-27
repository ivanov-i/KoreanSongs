#include <gtest/gtest.h>
#include <fstream>
#include "fileInput.h"
#include "CharInput.h"

namespace {

    class testCharInput : public CharInput
    {

    public:
        testCharInput(std::string &actual) : str(actual) { }

        virtual void OnChar(char c) override {
            str += c;
        };
        std::string& str;
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
        auto input = fileInput();
        input.ProcessFile("songs.txt", testSink);
        EXPECT_EQ(expected, actual);
    }

}
