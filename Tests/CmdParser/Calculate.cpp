#include <gtest/gtest.h>

#include "CmdParser/CmdParser.hpp"

TEST(CmdParserCheck, ArgumenmtCheck)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=a", "--goal-format=" };
        CmdParser parser{ 3,  arr };

        const std::string& str = parser.GetSourceFormat();

        FAIL() << "The exeption was not thrown";
    }
    catch (const std::exception& exp)
    {
        EXPECT_EQ(std::string{ "The argument passed as a source is incorrect" }, exp.what());
    }
}