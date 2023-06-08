#pragma once

#include "RenderHandler\RenderHandler.hpp"

class RenderHandlerFabric
{
public:
	virtual RenderHandler* GetRenderHandler() noexcept(false) = 0;
};