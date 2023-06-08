#pragma once

#include "Fabric.hpp"
#include "Writers/Writer.hpp"

class WriterFabric : public Fabric
{
public:
	WriterFabric(const std::filesystem::path& dllPath);

	~WriterFabric() override = default;

	Writer* GetWriter(const std::filesystem::path& path) const noexcept(false);
};