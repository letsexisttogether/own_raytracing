#include <iostream>
#include <memory>

#include "Tools/CmdParser/CmdParser.hpp"
#include "Tools/FileReader/FileReader.hpp"

// #include "Geometry/Primitives/Matrix.hpp"

#include "Fabrics/FabricSelector/FabricSelector.hpp"

#include "Graphics/Geometry/Intersectables/Sphere.hpp"
#include "Graphics/RenderHandler/CmdRenderHandler.hpp" 
#include "Graphics/Render/Scene.h"
#include "Graphics/Geometry/Intersectables/Triangle.hpp"
#include "Graphics/Render/Tracer.h"
#include "ObjReader/ObjReader.hpp"


std::int32_t main(std::uint32_t argc, const char* argv[])
{
    Vector3d light{ 0.f, 1.f, 0.f };
    light = light.Normalize();

    Camera camera{ { 0.f, 0.f, 0.f }, { 0.f, 0.f, 1.f }, 3.1415 / 6.f };
    Screen screen{ 100u, 100u, 10.f, camera };

    RayTracer RT
    {
        new CmdRenderHandler
        {
            screen
        }
    };

    Scene scene{ camera, light };
    scene.AddToScene(new Sphere{ Vector3d{ 0.f, 0.f, 0.7f }, 0.15f });

    RT.Trace(scene);

    RT.GetRenderHandler().ExecuteRenderResult();

    return EXIT_SUCCESS;
}
