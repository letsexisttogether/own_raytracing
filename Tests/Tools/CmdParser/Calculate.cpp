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

TEST(CmdParserCalculate, GoalFormatCalculate)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=alex.png", "--goal-format=ppm" };
        CmdParser parser{ 3,  arr };

        const std::string& goalFormat = parser.GetGoalFormat();

        EXPECT_EQ(goalFormat, "ppm");
    }
    catch (std::exception& exp)
    {
        FAIL() << exp.what();
    }
}

TEST(CmdParserCalculate, GoalFormatFalseCalculate)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=alex.png", "--goal-format=" };
        CmdParser parser{ 3,  arr };

        const std::string& goalFormat = parser.GetGoalFormat();
        
        FAIL() << "The exeption was not thrown";
    }
    catch (std::exception& exp)
    {
        EXPECT_EQ(std::string{ "The goal format was passed incorrectly" }, exp.what());
    }
}

TEST(CmdParserCalculate, OutputCalculate)
{
    try
    {
        char const* arr[4] = { "Program.exe", "--source=alex.png", "--goal-format=ppm", "--output=image"};
        CmdParser parser{ 4,  arr };

        const std::string& output = parser.GetOutput();

        EXPECT_EQ(output, "image");
    }
    catch (std::exception& exp)
    {
        FAIL() << exp.what();
    }
}

TEST(CmdParserCalculate, OutputFromSourceCalculate)
{
    try
    {
        char const* arr[3] = { "Program.exe", "--source=image.png", "--goal-format=ppm" };
        CmdParser parser{ 3,  arr };

        const std::string& output = parser.GetOutput();

        EXPECT_EQ(output, "image");
    }
    catch (std::exception& exp)
    {
        FAIL() << exp.what();
    }
}