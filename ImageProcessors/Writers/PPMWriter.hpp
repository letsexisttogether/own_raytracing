#pragma once

#include "Writer.hpp"

class __declspec(dllexport) PPMWriter : public Writer
{
public:
    PPMWriter(const ImageFormat& image, const std::filesystem::path& path);

    ~PPMWriter() override = default;

    void Write() noexcept override;
};