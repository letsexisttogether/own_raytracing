#include <iostream>
#include <memory>

#include "Tools/CmdParser/CmdParser.hpp"
#include "Tools/FileReader/FileReader.hpp"

#include "Fabrics/FabricSelector/FabricSelector.hpp"

#include "Graphics/Geometry/Intersectables/Sphere.hpp"
#include "Graphics/RenderHandler/CmdRenderHandler.hpp" 
#include "Graphics/Render/Scene.h"
#include "Graphics/Render/Tracer.h"


std::int32_t main(std::uint32_t argc, const char* argv[])
{
	Sphere sphere{ Vector3d{ 0.f, 0.f, 50.f }, 15.f };

	Vector3d light{ 0.f, 1.f, 0.f };
	light = light.Normalize();

	Camera camera{ { 0.f, 0.f, 0.f }, { 0.f, 0.f, 1.f }, 3.1415 / 6.f };
	Screen screen{ 100u, 100u, 10.f, camera };

	RayTracer RT
	{ 
		new CmdRenderHandler
		{
			screen
		}, 
		camera, 
		light
	};

	Scene scene{ RT };
	
	scene.AddToScene(new Sphere(Vector3d{ 0.f, 0.f, 0.7 }, 0.15));
	
	RT.Trace(scene);
	
	RT.GetRenderHandler().ExecuteRenderResult();

	return EXIT_SUCCESS;
}
