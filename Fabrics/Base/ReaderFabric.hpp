#pragma once

#include "Fabric.hpp"
#include "Readers/Reader.hpp"

class ReaderFabric : public Fabric
{
public:
	ReaderFabric(const std::filesystem::path& dllPath);

	~ReaderFabric() override = default;

	Reader* GetReader(std::vector<std::byte>&& bytes) const noexcept(false);
};