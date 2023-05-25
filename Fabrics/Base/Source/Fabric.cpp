#include "../Fabric.hpp"

#include <iostream>

Fabric::Fabric(const std::filesystem::path& dllPath)
	: m_DllPath{ dllPath }, m_Handler{ nullptr }
{
	CheckPath();
}

Fabric::~Fabric()
{
	FreeLibrary(m_Handler);
}	

void Fabric::LoadDll() noexcept(false)
{
	m_Handler = LoadLibraryA(m_DllPath.string().c_str());

	CheckHandler();
}

void Fabric::CheckPath() const noexcept(false)
{
	if (!std::filesystem::exists(m_DllPath))
	{
		std::cerr << "Path " << m_DllPath << " does not exist." << std::endl;
	}
}

void Fabric::CheckHandler() const noexcept(false)
{
	if (!m_Handler) 
	{
		throw std::runtime_error("Failed to load the DLL: " + m_DllPath.string());
	}
}
