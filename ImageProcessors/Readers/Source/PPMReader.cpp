#include "../PPMReader.hpp"

#include <stdexcept>
#include <iostream>

PPMReader::PPMReader(std::vector<std::byte>&& bytes)
	: Reader(std::move(bytes), "PPM")
{}

int get_int_number(int& byte_number, const std::vector<std::byte>& m_Bytes)
{
    std::string number;

    while (byte_number < m_Bytes.size() && isdigit((char)m_Bytes[byte_number]))
    {
        number += (char)m_Bytes[byte_number++];
    }

    byte_number++;

    return atoi(number.c_str());
}

ImageFormat PPMReader::Read() noexcept(false)
{
    int byte_number = 0;
    int size = m_Bytes.size();

    // Зчитатуємо формат PPM файлу
    while ((char)m_Bytes[byte_number] != '\r' && (char)m_Bytes[byte_number + 1] != '\n')
    {
        m_Header.Format += (char)m_Bytes[byte_number++];
    }

    byte_number += 2;

    // Пропускаємо зчитування коментарів
    while ((char)m_Bytes[byte_number] == '#')
    {
        while ((char)m_Bytes[++byte_number] != '\r' && (char)m_Bytes[byte_number + 1] != '\n');

        byte_number += 2;
    }

    // Зчитуємо висоту, ширину та градацію кольорів
    m_Header.Width = get_int_number(byte_number, m_Bytes);
    m_Header.Height = get_int_number(byte_number, m_Bytes);
    m_Header.PixelMaxValue = get_int_number(byte_number, m_Bytes);
    
    byte_number++;
    
    CheckHeader();
    
    ImageFormat image = { m_Header.Width, m_Header.Height };

    // Зчитуємо дані
    for (ImageFormat::ResolutionType height = 0; height < image.Height; ++height, byte_number--)
    {
        for (ImageFormat::ResolutionType width = 0; width < image.Width; ++width, byte_number += 2)
        {
            for (std::uint8_t i = 0; i < 3; ++i)
            {
                const auto value = static_cast<std::byte>(get_int_number(byte_number, m_Bytes));
                image.Data.push_back(value);
            }
        } 
    }

    return image;
}

void PPMReader::CheckHeader() const noexcept(false)
{
    PPMHeader header;

    if (m_Header.Format != header.Format)
    {
        throw std::invalid_argument{ "The format you are trying to open is"
            + m_Header.Format
            + ". However, we only support " + header.Format + " PPM format"};
    }
    
    if (!m_Header.Height || !m_Header.Width)
    {
        throw std::invalid_argument{ "A resolution of an image cannot be 0" };
    }
}
 
