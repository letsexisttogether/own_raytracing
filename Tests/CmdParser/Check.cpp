#include <gtest/gtest.h>

#include "CmdParser/CmdParser.hpp"

TEST(CmdParserCheck, ArgumenmtCheck)
{
    try 
    {
        char const* arr[3] = { "Program.exe", "--source=alex.ppm", "--goal-format=" };
        CmdParser parser{ 3,  arr };
    }
    catch (const std::exception& exp)
    {
        FAIL() << exp.what();
    }

    SUCCEED();
}

TEST(CmdParserCheck, ArgumenmtFalseCheck)
{
    try
    {
        char const* arr[2] = { "--source=alex.ppm", "--goal-format=" };
        CmdParser parser{ 2,  arr };

        FAIL() << "The exeption was not thrown";
    }
    catch (const std::invalid_argument& exp)
    {
        EXPECT_EQ(std::string{ "The count of current arguments does not satisfy the needed amount" }, exp.what());
    }
}

TEST(CmdParserCheck, SourceCheck)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=", "--goal-format=" };
        CmdParser parser{ 3,  arr };
    }
    catch (const std::exception& exp)
    {
        FAIL() << exp.what();
    }

    SUCCEED();
}

TEST(CmdParserCheck, SourceFalseCheck)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--sour", "--goal-format=" };
        CmdParser parser{ 3,  arr };
        
        FAIL() << "The exeption was not thrown";
    }
    catch (const std::exception& exp)
    {
        EXPECT_EQ(std::string{ "The command \"--source=\" was written incorrectly" }, exp.what());
    }
}

TEST(CmdParserCheck, GoalFormatCheck)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=", "--goal-format=" };
        CmdParser parser{ 3,  arr };

    }
    catch (const std::exception& exp)
    {
        FAIL() << exp.what();
    }

    SUCCEED();
}

TEST(CmdParserCheck, GoalFormatFalseCheck)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=", "--goal-for=" };
        CmdParser parser{ 3,  arr };

        FAIL() << "The exeption was not thrown";
    }
    catch (const std::exception& exp)
    {
        EXPECT_EQ(std::string{ "The command \"--goal-format=\" was written incorrectly" }, exp.what());
    }
}

TEST(CmdParserCheck, SourceNameEmptyCheck)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=.png", "--goal-format=" };
        CmdParser parser{ 3,  arr };

        const std::string& str = parser.GetSourceName();

        FAIL() << "The exeption was not thrown";
    }
    catch (const std::exception& exp)
    {
        EXPECT_EQ(std::string{ "The source name was passed incorrectly" }, exp.what());
    }
}

TEST(CmdParserCheck, SourceFormatEmptyCheck)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=alex", "--goal-format=" };
        CmdParser parser{ 3,  arr };

        const std::string& str = parser.GetSourceFormat();

        FAIL() << "The exeption was not thrown";
    }
    catch (const std::exception& exp)
    {
        EXPECT_EQ(std::string{ "The source format was passed incorrectly" }, exp.what());
    }
}
