#include <memory>

#include "ApplicationPrototype.hpp"

#include "Light/AmbientLight.hpp"
#include "Light/PointLight.hpp"
#include "Light/DirectionalLight.hpp"

#include "Fabrics/Scene/SceneFabricSelector/SceneFabricSelector.hpp"
#include "Fabrics/RenderHandler/Base/ImageRenderHandlerFabric.hpp"

std::int32_t main()
{
    try
    {
        std::uint32_t argc = 3;
        const char* argv[] = { "RayTracer.exe\0", "--source=Test.obj\0" , "--output=alex.bmp\0" };

        CmdParser parser{ argc, argv };

        std::unique_ptr<RenderHandlerFabric> renderHandlerFabric
        { 
            new ImageRenderHandlerFabric
            {                
                FabricSelector{ "ImageProcessors" },
                parser
            }
        };

        std::unique_ptr<SceneFabric> soloScene
        {
            new SceneLoader 
            {
                FileReader{ parser.GetSecondArgument() },
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
                        new AmbientLight{ { 255.f, 255.f, 0.f }, 300.f }
                    }
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
                }
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