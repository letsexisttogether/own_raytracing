#pragma once 

#include <string>

#include "Render/Scene.h"

class SceneFabric
{
public:
	virtual const Scene& GetScene() noexcept(false) = 0;
};