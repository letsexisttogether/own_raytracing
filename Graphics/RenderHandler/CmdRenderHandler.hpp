#pragma once

#include "RenderHandler.hpp"

class CmdRenderHandler
{
public:
	CmdRenderHandler(const Screen& screen);

	~CmdRenderHandler() = delete;

	void HandlePixel(const Screen::Resolution i, const Screen::Resolution j, const Vector3d& color) noexcept(false) ;

	void ExecuteRenderResult() const noexcept(false) ;

private:
	char LightTrace(const float dotResult) const noexcept;

private:
	std::vector<std::vector<char>> m_Pixels;
};