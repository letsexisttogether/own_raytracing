#include "../BMP.hpp"

void BMP::CheckHeader() const noexcept(false)
{

}

void BMP::AddPadding() noexcept
{
    int padding = (4 - Width % 4) % 4;
    int newWidth = Width * 4 + padding;
    long numPixels = Data.size();
    int numRows = Height;

    int newNumPixels = numRows * newWidth;

    std::vector<std::uint8_t> newPixels;
    newPixels.reserve(newNumPixels);

    for (int y = Height - 1; y >= 0; y--)
    {
        int tempY = y * Width * 3;
        int tempWidth = Width * 3 + y * Width * 3;
        for (long i = tempY; i < tempWidth; i += 3)
        {
            newPixels.push_back(Data[i + 2]);
            newPixels.push_back(Data[i + 1]);
            newPixels.push_back(Data[i]);
            newPixels.push_back(static_cast <std::uint8_t>(0));

        }
    }

    Data = std::move(newPixels);
}

void BMP::RemovePadding() noexcept
{
    int padding = (4 - (Width * sizeof(std::uint8_t) * 4) % 4) % 4;
    int newWidth = Width * sizeof(std::uint8_t) * 4 + padding;
    long numPixels = Data.size();

    std::vector<std::uint8_t> newPixels;
    newPixels.reserve(numPixels);

    int rowIndex = 0;
    for (int y = Height - 1; y >= 0; y--)
    {
        int tempY = y * Width * 4;
        int tempWidth = newWidth + y * Width * 4;
        for (long i = tempY; i < tempWidth; i += 4)
        {
            newPixels.push_back(Data[i + 2]);
            newPixels.push_back(Data[i + 1]);
            newPixels.push_back(Data[i]);
            rowIndex++;

            if (rowIndex == Width)
            {
                i += padding;
                rowIndex = 0;
            }
        }
    }

    Data = std::move(newPixels);
}