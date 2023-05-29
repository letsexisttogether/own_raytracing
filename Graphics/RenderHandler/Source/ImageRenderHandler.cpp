#include "../ImageRenderHandler.hpp"

ImageRenderHandler::ImageRenderHandler(const Screen& screen, Writer* writer)
	: RenderHandler{ screen }, m_Writer{ writer }, m_Image{ screen.GetHeigth(), screen.GetWidth() }
{
	m_Image.Data = std::vector<std::byte>{ m_Image.Height * m_Image.Width };
}

ImageRenderHandler::~ImageRenderHandler()
{
	delete m_Writer;
}

void ImageRenderHandler::HandlePixel(const Screen::Resolution i, const Screen::Resolution j, const float pixelResult) noexcept(false)
{
}

void ImageRenderHandler::ExecuteRenderResult() const noexcept(false)
{

}	