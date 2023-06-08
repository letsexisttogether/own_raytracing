#include "../ImageRenderHandler.hpp"

ImageRenderHandler::ImageRenderHandler(Writer* writer)
	: m_Writer{ writer }
{}

ImageRenderHandler::~ImageRenderHandler()
{
	delete m_Writer;
}

void ImageRenderHandler::Handle(const std::vector<std::vector<Vector3d>>& colors) noexcept
{
    m_Image.Height = colors.size();

    if (!m_Image.Height)
    {
        return;
    }

    m_Image.Width = colors[0].size();

    m_Image.Data.reserve(m_Image.Height * m_Image.Width * 3); //added
    m_Image.Data.resize(m_Image.Height * m_Image.Width * 3);

    for (std::int32_t i = 0; i < m_Image.Height; ++i)
    {
        for (std::int32_t j = 0; j < m_Image.Width; ++j)
        {
            HandlePixel(i, j, colors[i][j]);
        }
    }

    
}

void ImageRenderHandler::HandlePixel(const Screen::Resolution i, const Screen::Resolution j, const Vector3d& color) noexcept(false)
{
    const Screen::Resolution invertedI = m_Image.Height - i - 1;

    const std::size_t pixelIndex = (invertedI * m_Image.Width + j) * 3;
    m_Image.Data[pixelIndex] = static_cast<std::byte>(color.GetX());
    m_Image.Data[pixelIndex + 1] = static_cast<std::byte>(color.GetY());
    m_Image.Data[pixelIndex + 2] = static_cast<std::byte>(color.GetZ());
}

void ImageRenderHandler::ExecuteRenderResult() const noexcept(false)
{
	m_Writer->Write(m_Image);
}	