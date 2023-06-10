#include <memory>

#include "ApplicationPrototype.hpp"

#include "Light/AmbientLight.hpp"
#include "Light/PointLight.hpp"
#include "Light/DirectionalLight.hpp"

#include "Fabrics/Scene/SceneFabricSelector/SceneFabricSelector.hpp"

#include "Fabrics/RenderHandler/Base/ImageRenderHandlerFabric.hpp"

std::int32_t main(std::uint32_t argc, const char* argv[])
{
    try
    {
        CmdParser parser{ argc, argv };

        std::unique_ptr<RenderHandlerFabric> renderHandlerFabric
        { 
            new ImageRenderHandlerFabric
            {                
                FabricSelector{ "ImageProcessors" },
                parser
            }
        };

        Camera camera = { { 0.f, 0.f, -100.f }, { 0.f, 0.f, 1.f }, 3.1415 / 6.f };
        const auto& matrix = TF::CreateMovingMatrix(Vector3d{ 0.f, 0.f, 50.f });
        camera.TransformLocation(matrix);

        Scene sceneForSolo
        {
            Screen
            {
                1000, 1000, 1000.f,
                Camera{ { 0.f, 0.f, -1000.f }, { 0.f, 0.f, 1.f }, 3.1415 / 6.f }
            },
            std::vector<Light*>
            {
                new AmbientLight{ { 0.f, 0.f, 0.f }, 100.f },
                new DirectionalLight{ { 0.f, 0.f, -1.f },  { 40.f, 0.f, 20.f }, 50.f },
                new PointLight{ { -5.f, -5.f, 0.f },  { 255.f, 255.f, 0.f }, 80.f }
            }
        };

        sceneForSolo.AddToScene(new Sphere{ { -5.f, -5.f, 0.f }, 10.f });

        std::unique_ptr<SceneFabric> soloScene
        {
            new SceneLoader 
            {
                FileReader{ parser.GetSecondArgument() },
                ObjReader{},
                sceneForSolo,
            }
        };
        
        const auto& matrix1 = TF::CreateMovingMatrix(Vector3d{ 5.f, 0.f, 0.f });
        camera.TransformDirection(matrix1);

        std::unique_ptr<SceneFabric> ambientScene
        {
            new SceneLoader
            {
                FileReader{ "Test.obj" },
                ObjReader{},
                Scene
                {
                    Screen
                    {
                        1000, 1000, 100.f,
                        Camera{ { 0.f, 0.f, -100.f }, { 0.f, 0.f, 1.f }, 3.1415 / 6.f }
                    },
                    std::vector<Light*>
                    {
                        new AmbientLight{ { 0.f, 255.f, 250.f }, 500.f }
                        // new AmbientLight{ { 100.f, 0.f, 250.f }, 500.f }
                    }
                }
            }
        };

        std::unique_ptr<SceneFabric> pointScene
        {
            new SceneLoader
            {
                FileReader{ "Teapot.obj" },
                ObjReader{},
                Scene
                {
                    Screen
                    {
                        1000, 1000, 100.f,
                        camera
                        //Camera{ { 0.f, 0.f, -100.f }, { 0.f, 0.f, 1.f }, 3.1415 / 6.f }
                    },
                    std::vector<Light*>
                    {
                        new PointLight{ { 2.f, 2.f, -1.f }, { 150.f, 150.f, 0.f }, 50.f }
                    }
                }
             }
        };

        std::unique_ptr<SceneFabric> multipleFabric
        {
            new SceneSelector
            {
                parser.GetSecondArgument(),
                SceneSelector::ScenesMap
                {
                    SceneSelector::ScenesMapPair{ "ambient", ambientScene.get() },
                    SceneSelector::ScenesMapPair{ "point", pointScene.get() }
                }
            }
        };

        SceneFabricSelector selector
        {
            SceneFabricSelector::SceneFabricsMap
            {
                SceneFabricSelector::SceneFabricsPair
                {
                    parser.GetCorrectSource(),
                    soloScene.get()
                },
                SceneFabricSelector::SceneFabricsPair
                {
                    parser.GetCorrectScene(),
                    multipleFabric.get()
                },
            }
        };

        RayTracer tracer{};

        ApplicationPrototype app { parser, selector, tracer, renderHandlerFabric.get() };

        app.Run();
    }
    catch (const std::exception& exp)
    {
        std::cerr << exp.what() << std::endl;

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}