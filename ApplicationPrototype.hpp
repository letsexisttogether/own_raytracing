#pragma once

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
#include "Graphics/Geometry/Intersectables/Plane.hpp"

#include "Graphics/Geometry/Intersectables/Triangle.hpp"
#include "Graphics/Geometry/Primitives/TransformFactory.hpp"

#include "Graphics/RenderHandler/ImageRenderHandler.hpp" 

#include "Fabrics/Scene/SceneFabricSelector/SceneFabricSelector.hpp"
#include "Fabrics/RenderHandler/Base/ImageRenderHandlerFabric.hpp"

#include "Geometry/Intersectables/BVH.hpp"

class ApplicationPrototype
{
public:
    ApplicationPrototype(const CmdParser& parser, const SceneFabricSelector& sceneFabricSelector, 
        const RayTracer& tracer, RenderHandlerFabric* renderHandlerFabric)
        : m_Parser{ parser }, m_SceneFabricSelector{ sceneFabricSelector }, 
            m_RT{ tracer }, m_RenderHandlerFabric{ renderHandlerFabric }
    {}

    ~ApplicationPrototype() = default;

    void Run() noexcept(false)
    {

        auto sceneFabric = m_SceneFabricSelector.GetFabric(m_Parser.GetSecondArgumentType());
        const auto& scene = sceneFabric->GetScene();

        auto startTime = std::chrono::high_resolution_clock::now();
        
        m_RT.Trace(scene);

        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

        auto renderHandler = m_RenderHandlerFabric->GetRenderHandler();
        renderHandler->Handle(m_RT.GetPixels());
        renderHandler->ExecuteRenderResult();

        std::cout << "Render time: " << duration.count() << "sec" << std::endl;
    }

private:
    CmdParser m_Parser;
    const SceneFabricSelector& m_SceneFabricSelector;
    RayTracer m_RT;
    RenderHandlerFabric* m_RenderHandlerFabric;
};