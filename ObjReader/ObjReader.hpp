#pragma once

#include <vector>
#include <byte>

class ObjReader
{
public:
	ObjReader(std::vector<std::byte>&& bytes);

	~ObjReader() = default;

	void Read() noexcept;

private: 
	

private:
	std::vector<std::byte> m_Bytes;
	std::vector<float> m_Vertices;
};