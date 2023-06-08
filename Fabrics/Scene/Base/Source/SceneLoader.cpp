#include "../SceneLoader.hpp"

#include "Geometry/Intersectables/BVH.hpp"

SceneLoader::SceneLoader(const FileReader& fileReader, const ObjReader& objReader, const Scene& scenePrototype)
	: m_FileReader{ fileReader }, m_ObjReader{ objReader }, m_ScenePrototype{ scenePrototype }
{}

SceneLoader::SceneLoader(FileReader&& fileReader, ObjReader&& objReader, Scene&& scenePrototype)
	: m_FileReader{ std::move(fileReader) }, m_ObjReader{ std::move(objReader) }, m_ScenePrototype{ std::move(scenePrototype) }
{}

const Scene& SceneLoader::GetScene() noexcept(false)
{	
	if (!m_FileReader.GetFilePath().empty())
	{
		std::vector<Triangle> triangles{};
		
		const auto& content = m_ObjReader.Read(m_FileReader.ReadFile());
		for (auto ptr : content)
		{
			auto& triangle = *(dynamic_cast<Triangle*>(ptr));
			triangles.push_back(triangle);
		}

		m_ScenePrototype.AddToScene(new BVHTree{ std::move(triangles), 0 });
	}

	return m_ScenePrototype;
}
