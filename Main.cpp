#include <iostream>
#include <memory>

#include "Tools/CmdParser/CmdParser.hpp"
#include "Tools/FileReader/FileReader.hpp"

#include "Fabrics/FabricSelector/FabricSelector.hpp"

#include "Graphics/Geometry/Intersectables/Sphere.hpp"

std::int32_t main(std::uint32_t argc, const char* argv[])
{
	Sphere sphere{ Vector3d{ 3 }, 5.f };
	

	std::cout << sphere.GetRadius() << std::endl;

	return EXIT_SUCCESS;
}
