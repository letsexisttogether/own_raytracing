#include "../PPMReader.hpp"

PPMReader::PPMReader(std::vector<std::byte>&& bytes)
	: Reader<PPM>(std::move(bytes))
{}

int get_int_number(int& byte_number, const std::vector<std::byte>& m_Bytes)
{
    std::string number;

    while (isdigit((char)m_Bytes[byte_number]) && (char)m_Bytes[byte_number] != ' ' && 
        (char)m_Bytes[byte_number] != '\r' && (char)m_Bytes[byte_number + 1] != '\n')
        number += (char)m_Bytes[byte_number++];
   
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
    std::string comment;
    if ((char)m_Bytes[byte_number] == '#')
        do
        {
            comment.clear();
            while ((char)m_Bytes[byte_number] != '\r' && (char)m_Bytes[byte_number + 1] != '\n')
                comment += (char)m_Bytes[byte_number++];

            byte_number++;
            m_UnformattedStruct.Comments.push_back(comment);

        } while ((char)m_Bytes[++byte_number] == '#');

        // зчитуємо висоту, ширину та градацію кольорів
        m_UnformattedStruct.Width = get_int_number(byte_number, m_Bytes);
        m_UnformattedStruct.Height = get_int_number(byte_number, m_Bytes);
        m_UnformattedStruct.PixelMaxValue = get_int_number(byte_number, m_Bytes);

        // зчитуємо пікселі зображення
        if ((char)m_Bytes[byte_number] == '\r') byte_number += 2;
        else if ((char)m_Bytes[byte_number] == '\n') byte_number++;

        while (size > byte_number)
        {
            m_UnformattedStruct.Data.push_back(get_int_number(byte_number, m_Bytes));
        }

}

