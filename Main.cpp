#include <iostream>
#include <memory>
#include <chrono>

#include "Tools/CmdParser/CmdParser.hpp"
#include "Tools/FileReader/FileReader.hpp"

#include "Fabrics/FabricSelector/FabricSelector.hpp"
#include "ObjReader/ObjReader.hpp"

#include "Graphics/Render/Tracer.h"
#include "Graphics/Render/Scene.h"

#include "Graphics/Geometry/Intersectables/Sphere.hpp"
#include "Graphics/Geometry/Intersectables/Triangle.hpp"
#include "Graphics/Geometry/Primitives/TransformFactory.hpp"

#include "Graphics/RenderHandler/CmdRenderHandler.hpp" 
#include "Graphics/RenderHandler/ImageRenderHandler.hpp" 








std::int32_t main(std::uint32_t argc, const char* argv[])
{
    try
    {
        CmdParser parser{ argc, argv };

        if (parser.GetSourceFormat() != "obj")
        {
            throw std::invalid_argument{ "The format you are trying to open is not .obj" };
        }

        FabricSelector selector{ "ImageProcessors" };
        selector.FindDlls();

        WriterFabric& writerFabric = selector.GetWriterFabric(parser.GetGoalFormat());
        writerFabric.LoadDll();

        FileReader reader{ parser.GetSourceName() + '.' + parser.GetSourceFormat()};
        ObjReader objReader{ reader.ReadFile() };

        Vector3d light{ 0.f, 0.f, -1.f };
        light = light.Normalize();

        Camera camera{ { 0.f, 0.f, -100.f }, { 0.f, 0.f, 1.f }, 3.1415 / 6.f };
        Screen screen{ 200, 200, 100.f, camera };
        
        auto& content = objReader.Read();

        const auto& rotationMatrix = TF::CreateRotationMatrixY(90.f);
        for (auto ptr : content)
        {
            auto& triangle = *(dynamic_cast<Triangle*>(ptr));
            triangle = triangle * rotationMatrix;
        }

        RayTracer RT
        {
            new ImageRenderHandler
            {
                screen,
                writerFabric.GetWriter(parser.GetOutput() + '.' + parser.GetGoalFormat())
            }
        };

        Scene scene{ camera, light };
        scene.AddToScene(content);
        scene.AddToScene(new Sphere{ { 0.8f, 1.f, 0.f }, 0.5f });

        auto startTime = std::chrono::high_resolution_clock::now();

        RT.Trace(scene);

        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

        std::cout << "Render time: " << duration.count() << "sec" << std::endl;

        RT.GetRenderHandler().ExecuteRenderResult();
    }
    catch (const std::exception& exp)
    {
        std::cerr << exp.what() << std::endl;

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
