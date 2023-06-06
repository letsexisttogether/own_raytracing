#include "../ImageRenderHandler.hpp"

ImageRenderHandler::ImageRenderHandler(const Screen& screen, Writer* writer)
	: RenderHandler{ screen }, m_Writer{ writer }, m_Image{ screen.GetWidth(), screen.GetHeigth() }
{
    m_Image.Data = std::vector<std::byte>{ static_cast<std::size_t>(m_Image.Height * m_Image.Width * 3) };
}

ImageRenderHandler::~ImageRenderHandler()
{
	delete m_Writer;
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