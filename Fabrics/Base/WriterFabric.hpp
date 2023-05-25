#pragma once

#include "Fabric.hpp"
#include "Writers/Writer.hpp"

class WriterFabric : public Fabric
{
public:
	WriterFabric(const std::filesystem::path& dllPath)
		: Fabric{ dllPath }
	{}

	~WriterFabric() override = default;

	Writer* GetReader(const ImageFormat& image, const std::filesystem::path& path) const noexcept(false)
	{
		typedef Writer* (*CreateWriterFunc)(const ImageFormat&, const std::filesystem::path&);
		CreateWriterFunc createReader = reinterpret_cast<CreateWriterFunc>(GetProcAddress(m_Handler, "CreateWriter"));

		if (!createReader)
		{
			throw std::runtime_error("Failed to retrieve the CreateReader function from the DLL");
		}

		return createReader(image, path);
	}
};