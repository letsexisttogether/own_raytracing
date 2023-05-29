#include "../WriterFabric.hpp"

WriterFabric::WriterFabric(const std::filesystem::path& dllPath)
	: Fabric{ dllPath }
{}

Writer* WriterFabric::GetWriter(const std::filesystem::path& path) const noexcept(false)
{
	CheckHandler();

	typedef Writer* (*CreateWriterFunc)(const std::filesystem::path&);
	CreateWriterFunc createReader = reinterpret_cast<CreateWriterFunc>(GetProcAddress(m_Handler, "CreateWriter"));

	if (!createReader)
	{
		throw std::runtime_error("Failed to retrieve the CreateReader function from the DLL");
	}

	return createReader(path);
}