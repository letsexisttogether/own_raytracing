#include <gtest/gtest.h>

#include "Readers/PPMReader.hpp"
#include "FileReader/FileReader.hpp"

class PPMReadTest : public testing::Test
{
protected:
	PPMReadTest()
		: m_FileReader{ "file.ppm" }, m_PPMReader{ m_FileReader.ReadFile() }
	{
		m_PPMReader.Read();
	}

	void SetUp()
	{
		m_PPM = m_PPMReader.GetFormatedStruct();
	}

protected:
	PPM m_PPM;

private:
	const FileReader m_FileReader;
	PPMReader m_PPMReader;
};

TEST_F(PPMReadTest, HeaderRead)
{
	EXPECT_EQ(std::string{ "P3" }, m_PPM.Format) << "Incorrect format";
	
	EXPECT_EQ(std::string{ "Image with width 3 and height 2" }, m_PPM.Comments[0]) << "First comment is wrong";
	EXPECT_EQ(std::string{ "using 0 or 1 per color (red, green, blue)" }, m_PPM.Comments[1]) << "Second comment is wrong";

	EXPECT_EQ(3, m_PPM.Width);
	EXPECT_EQ(2, m_PPM.Height);
	EXPECT_EQ(1, m_PPM.PixelMaxValue);
}
