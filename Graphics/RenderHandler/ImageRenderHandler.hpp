#pragma once

#include "RenderHandler.hpp"
#include "Writers/Writer.hpp"

class ImageRenderHandler : public RenderHandler
{
public:
	ImageRenderHandler(Writer* writer);

	~ImageRenderHandler();

	void Handle(const std::vector<std::vector<Vector3d>>& colors) noexcept override;

	void ExecuteRenderResult() const noexcept(false) override;

private:
	void HandlePixel(const Screen::Resolution i, const Screen::Resolution j, const Vector3d& color) noexcept(false);

private:
	Writer* m_Writer;
	ImageFormat m_Image;
};