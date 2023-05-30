#include "../ObjReader.hpp"


ObjReader::ObjReader(std::vector<std::byte>&& bytes)
	: m_Bytes{ std::move(bytes) }
{}

std::vector<Intersectable*>& ObjReader::Read() noexcept(false)
{
    std::istringstream iss(reinterpret_cast<const char*>(m_Bytes.data()));

    for (std::string line{}; std::getline(iss, line); )
    {
        std::istringstream lineStream(line);

        Parse(lineStream);
    }

    return m_Intersectables;
}

void ObjReader::Parse(std::istringstream& lineStream) noexcept(false)
{
    std::string prefix;
    lineStream >> prefix;

    if (prefix == "v")
    {
        ExtractVertices(lineStream);
    }
    else if (prefix == "f")
    {
        ExtractIndices(lineStream);
    }
}

void ObjReader::ExtractVertices(std::istringstream& lineStream) noexcept(false)
{
    float x, y, z;
    lineStream >> x >> y >> z;

    m_Vertices.push_back(Point3d{ x, y, z });
}

void ObjReader::ExtractIndices(std::istringstream& lineStream) noexcept(false)
{
    std::size_t v1, v2, v3;
    lineStream >> v1 >> v2 >> v3;

    m_Intersectables.push_back(new Triangle{ m_Vertices.at(--v1), m_Vertices.at(--v2), m_Vertices.at(--v3) });
}