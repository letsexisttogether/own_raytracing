#pragma once

#include <filesystem>
#include <windows.h>

class Fabric
{
public:
	Fabric(const std::filesystem::path& dllPath);

	virtual ~Fabric() = 0 {}

	void LoadDll() noexcept(false);

protected:
	void CheckHandler() const noexcept(false);

private:
	void CheckPath() const noexcept(false);

protected:
	HMODULE m_Handler;
	std::filesystem::path m_DllPath;
};