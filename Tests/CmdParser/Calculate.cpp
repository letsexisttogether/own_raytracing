#include <gtest/gtest.h>

#include "CmdParser/CmdParser.hpp"

TEST(CmdParserCalculate, SourceCalculate)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=alex.png", "--goal-format=" };
        CmdParser parser{ 3,  arr };

        const std::string& name = parser.GetSourceName();
        const std::string& format = parser.GetSourceFormat();

        EXPECT_EQ(name, "alex") << "The current name is " << name;
        EXPECT_EQ(format, "png") << "The current format is " << format;
    }
    catch (std::exception& exp)
    {
        FAIL() << exp.what();
    }
}