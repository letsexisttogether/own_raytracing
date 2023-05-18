#include "../PPMReader.hpp"

PPMReader::PPMReader(std::vector<std::byte>&& bytes)
	: Reader<PPM>(std::move(bytes))
{}

int get_int_number(int& byte_number, const std::vector<std::byte>& m_Bytes)
{
    std::string number;

    while (isdigit((char)m_Bytes[byte_number]))
    {
        number += (char)m_Bytes[byte_number++];
    }

    byte_number++;

    return atoi(number.c_str());
}


void PPMReader::Read() noexcept(false)
{
    int byte_number = 0;
    int size = m_Bytes.size();

    // зчитати формат PPM файлу
    int j = 0;
    while ((char)m_Bytes[byte_number] != '\r' && (char)m_Bytes[byte_number + 1] != '\n')
    {
        m_UnformattedStruct.Format[j++] = (char)m_Bytes[byte_number++];
    }

    byte_number += 2;

    // зчитуємо коментарі, якщо вони там є
    while ((char)m_Bytes[byte_number] == '#')
    {
        std::string comment;
        while ((char)m_Bytes[++byte_number] != '\r' && (char)m_Bytes[byte_number + 1] != '\n')
        {
            comment += (char)m_Bytes[byte_number];
        }
        m_UnformattedStruct.Comments.push_back(comment);

        byte_number += 2;
    }

    // зчитуємо висоту, ширину та градацію кольорів
    m_UnformattedStruct.Width = get_int_number(byte_number, m_Bytes);
    m_UnformattedStruct.Height = get_int_number(byte_number, m_Bytes);
    m_UnformattedStruct.PixelMaxValue = get_int_number(byte_number, m_Bytes);

    m_UnformattedStruct.CheckHeader();

    byte_number++;

    // зчитуємо дані
    m_UnformattedStruct.GetData().resize(m_UnformattedStruct.Height, std::vector<std::byte>{ m_UnformattedStruct.Width * 3 });

    for (std::uint32_t height = 0; height < m_UnformattedStruct.Height; ++height, byte_number--)
    {
        auto& currentDataArray = m_UnformattedStruct.GetData()[height];
        for (std::uint32_t width = 0; width < currentDataArray.size(); width += 3, byte_number += 2)
        {
            currentDataArray[width] = (std::byte)get_int_number(byte_number, m_Bytes);
            currentDataArray[width + 1] = (std::byte)get_int_number(byte_number, m_Bytes);
            currentDataArray[width + 2] = (std::byte)get_int_number(byte_number, m_Bytes);
        }
    }
}
 
