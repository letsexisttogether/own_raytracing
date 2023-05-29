#pragma once

#include "RenderHandler.hpp"
#include "Writers/Writer.hpp"

class ImageRenderHandler : public RenderHandler
{
public:
	ImageRenderHandler(const Screen& screen, Writer* writer);

	~ImageRenderHandler();

	void HandlePixel(const Screen::Resolution i, const Screen::Resolution j, const float pixelResult) noexcept(false) override;

	void ExecuteRenderResult() const noexcept(false) override;

private:
	Writer* m_Writer;
	ImageFormat m_Image;
};