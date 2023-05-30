#include <iostream>
#include <memory>

#include "Tools/CmdParser/CmdParser.hpp"
#include "Tools/FileReader/FileReader.hpp"

#include "Fabrics/FabricSelector/FabricSelector.hpp"

#include "Graphics/Geometry/Intersectables/Sphere.hpp"
#include "Graphics/RenderHandler/ImageRenderHandler.hpp" 
#include "Graphics/Render/Scene.h"
#include "Graphics/Render/Tracer.h"


std::int32_t main(std::uint32_t argc, const char* argv[])
{
	Vector3d light{ 0.f, 1.f, 0.f };
	light = light.Normalize();

	Camera camera{ { 0.f, 0.f, 0.f }, { 0.f, 0.f, 1.f }, 3.1415 / 6.f };
	Screen screen{ 400, 560u, 10.f, camera };

	FabricSelector selector{ "ImageProcessors" };
	selector.FindDlls();

	WriterFabric& writerFabric = selector.GetWriterFabric("bmp");
	writerFabric.LoadDll();

	RayTracer RT
	{
		new ImageRenderHandler
		{
			screen,
			writerFabric.GetWriter("some_file.bmp")
		},
		camera, 
		light
	};

	Scene scene{ RT };
	
	scene.AddToScene(new Sphere(Vector3d{ 0.f, 0.f, 0.7 }, 0.15f));
	
	RT.Trace(scene);
	
	RT.GetRenderHandler().ExecuteRenderResult();

	return EXIT_SUCCESS;
}
