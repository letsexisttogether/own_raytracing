#include <iostream>
#include <memory>

#include "Tools/CmdParser/CmdParser.hpp"
#include "Tools/FileReader/FileReader.hpp"

#include "Geometry/Primitives/Matrix.hpp"

#include "Fabrics/FabricSelector/FabricSelector.hpp"

#include "Graphics/Geometry/Intersectables/Sphere.hpp"
#include "Graphics/RenderHandler/ImageRenderHandler.hpp" 
#include "Graphics/Render/Scene.h"
#include "Graphics/Render/Tracer.h"
#include "ObjReader/ObjReader.hpp"


std::int32_t main(std::uint32_t argc, const char* argv[])
{
	try
	{
		FileReader reader{ "Test.obj" };
		
		ObjReader objReader{ reader.ReadFile() };
		auto m_Intersectables = objReader.Read();

		std::cout << "Success";
		
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << std::endl;

		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}
