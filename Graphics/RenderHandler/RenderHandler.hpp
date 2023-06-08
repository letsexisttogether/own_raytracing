#pragma once 

#include "Render/Screen.h"

class RenderHandler
{
public:
	virtual void Handle(const std::vector<std::vector<Vector3d>>& colors) noexcept = 0;

	virtual void ExecuteRenderResult() const noexcept(false) = 0;
};