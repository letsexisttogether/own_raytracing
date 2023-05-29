#pragma once

#include "Writer.hpp"

class __declspec(dllexport) PPMWriter : public Writer
{
public:
    PPMWriter(const std::filesystem::path& path);

    ~PPMWriter() override = default;

    void Write(const ImageFormat& image) const noexcept override;
};