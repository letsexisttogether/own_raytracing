#pragma once

#include "SceneFabric.hpp"
#include "FileReader/FileReader.hpp"
#include "../ObjReader/ObjReader.hpp"

class SceneLoader : public SceneFabric
{
public:
	SceneLoader(const FileReader& fileReader, const ObjReader& objReader, const Scene& scenePrototype);
	SceneLoader(FileReader&& fileReader, ObjReader&& objReader, Scene&& scenePrototype);

	~SceneLoader() = default;

	const Scene& GetScene() noexcept(false);

private:
	ObjReader m_ObjReader;
	FileReader m_FileReader;
	Scene m_ScenePrototype;
};