#pragma once

#include "Writer.hpp"

class PPMWriter : public Writer
{
public:
    PPMWriter(const ImageFormat& image, const std::filesystem::path& path);

    ~PPMWriter() override = default;

    void Write() const noexcept(false) override;
};