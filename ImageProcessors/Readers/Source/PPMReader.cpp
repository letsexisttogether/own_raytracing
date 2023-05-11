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

    byte_number++;

    // зчитуємо дані
    for (std::uint32_t height = 0; height < m_UnformattedStruct.Height; ++height, byte_number--)
    {
        for (std::uint32_t width = 0; width < m_UnformattedStruct.Width; ++width, byte_number += 2)
        {
            m_UnformattedStruct.Data.push_back(get_int_number(byte_number, m_Bytes));
            m_UnformattedStruct.Data.push_back(get_int_number(byte_number, m_Bytes));
            m_UnformattedStruct.Data.push_back(get_int_number(byte_number, m_Bytes));
        }
    }
}
 
