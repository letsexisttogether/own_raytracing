#include <iostream>
#include <memory>

#include "Tools/CmdParser/CmdParser.hpp"
#include "Tools/FileReader/FileReader.hpp"

// #include "Geometry/Primitives/Matrix4.hpp"

#include "Fabrics/FabricSelector/FabricSelector.hpp"

#include "Graphics/Geometry/Intersectables/Sphere.hpp"
#include "Graphics/RenderHandler/CmdRenderHandler.hpp" 
#include "Graphics/Render/Scene.h"
#include "Graphics/Geometry/Intersectables/Triangle.hpp"
#include "Graphics/Render/Tracer.h"
#include "ObjReader/ObjReader.hpp"
#include "Geometry/Primitives/TransformFactory.hpp"
#include "Geometry/Intersectables/Triangle.hpp"


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

    Vector3d vec = { 12.f, 15.f, 20.f };

    Vector4 transformation_vector = { vec };

    Vector4 new_vector = transformation_vector * TF::CreateScalingMatrix({ 2.f, 1.f, 1.f }) * TF::CreateMovingMatrix({ 1.f, 1.f, 1.f })
       /* TF::CreateRotationMatrix({3.1415/4.f, 0.f, 0.f})*/;

    Vector3d new_vec = { new_vector };

    //matrix.AddMoving({ 1.f, 1.f, 1.f });

    //matrix.AddScale({ 2.f, 1.f, 1.f });

    Triangle tri = { {0.f, 0.f, 0.f}, {0.f, 0.f, 5.f}, {0.f, 5.f, 5.f} };

    tri.ApplyTransformation(/*TF::CreateScalingMatrix({ 2.f, 1.f, 1.f }) * TF::CreateMovingMatrix({ 1.f, 1.f, 1.f })*/ 
        TF::CreateRotationMatrix({0.f, 3.1415 / 4.f, 0.f }));

    return EXIT_SUCCESS;
}
