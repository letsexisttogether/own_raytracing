#pragma once 

#include "Render/Screen.h"

class RenderHandler
{
public:
	RenderHandler(const Screen& screen)
		: m_Screen{ screen }
	{}

	virtual void HandlePixel(const Screen::Resolution i, const Screen::Resolution j, const float pixelResult) noexcept(false) = 0;

	virtual void ExecuteRenderResult() const noexcept(false) = 0;

	inline const Screen& GetScreen() const noexcept { return m_Screen; }

protected:
	Screen m_Screen;
};