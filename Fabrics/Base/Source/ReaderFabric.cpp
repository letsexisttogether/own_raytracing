#include "../ReaderFabric.hpp"

ReaderFabric::ReaderFabric(const std::filesystem::path& dllPath)
	: Fabric{ dllPath }
{}

Reader* ReaderFabric::GetReader(std::vector<std::byte>&& bytes) const noexcept(false)
{
	typedef Reader* (*CreateReaderFunc)(std::vector<std::byte>&&);
	CreateReaderFunc createReader = reinterpret_cast<CreateReaderFunc>(GetProcAddress(m_Handler, "CreateReader"));

	if (!createReader)
	{
		throw std::runtime_error("Failed to retrieve the CreateReader function from the DLL");
	}

	return createReader(std::move(bytes));
}