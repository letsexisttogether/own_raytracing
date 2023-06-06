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

#include "Geometry/Intersectables/BVH.hpp"

std::int32_t main(std::uint32_t argc, const char* argv[])
{
    try
    {
        // CmdParser parser{ argc, argv };
        // 
        // if (parser.GetSourceFormat() != "obj")
        // {
        //     throw std::invalid_argument{ "The format you are trying to open is not .obj" };
        // }

        FabricSelector selector{ "ImageProcessors" };
        selector.FindDlls();
        
        WriterFabric& writerFabric = selector.GetWriterFabric("bmp");
        writerFabric.LoadDll();
        
        FileReader reader{ "Test.obj" };
        ObjReader objReader{ reader.ReadFile() };
        
        Vector3d light{ 0.f, 0.f, -1.f };
        light = light.Normalize();

        Camera camera{ { 0.f, 0.f, -100.f }, { 0.f, 0.f, 1.f }, 3.1415 / 6.f };

        const auto& matrix = TF::CreateMovingMatrix(Vector3d{ 0.f, 5.f, 0.f });
        camera.TransformLocation(matrix);
        
        const auto& matrix1 = TF::CreateMovingMatrix(Vector3d{ 5.f, 0.f, 0.f });
        camera.TransformDirection(matrix1);

        Screen screen{ 2000, 2000, 100.f, camera };

        //Triangle tr = { {0.f}, {0.f, 0.f, 1.f}, {0.f, 1.f, 1.f} };
        //Triangle tr1 = { {0.f}, {0.f, 0.f, 1.f}, {1.f, 1.f, 1.f} };
        //AABB3 box = { tr.GetMin(), tr.GetMax() };
        ////box += tr1.BuildBox();
        //auto var = box.Divide();
        //AABB3 box1 = { tr.GetMin(), tr.GetMax() };

        
        auto& content = objReader.Read();

        std::vector<Triangle> triangles;

        const auto& rotationMatrix = TF::CreateRotationMatrixY(-3.1415 / 2.f) * TF::CreateScalingMatrix(Vector3d{ 3.f });
        for (auto ptr : content)
        {
            auto& triangle = *(dynamic_cast<Triangle*>(ptr));
            triangle = triangle * rotationMatrix;
            triangles.push_back(triangle);
        }

        BVHTree tree = { std::move(triangles), 0 };

        RayTracer RT
        {
            new ImageRenderHandler
            {
                screen,
                writerFabric.GetWriter("cow.bmp")
            }
        };

        Scene scene{ /*camera, light*/ };
        scene.AddToScene(content);
        // scene.AddToScene(new Sphere{ { 0.8f, 1.f, 0.f }, 0.5f });

        auto startTime = std::chrono::high_resolution_clock::now();

        //RT.Trace(scene, camera, light);
        RT.Trace(tree, camera, light);

        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

        std::cout << "Render time: " << duration.count() << "sec" << std::endl;

        //std::cout << counter << std::endl;

        RT.GetRenderHandler().ExecuteRenderResult();
    }
    catch (const std::exception& exp)
    {
        std::cerr << exp.what() << std::endl;

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
