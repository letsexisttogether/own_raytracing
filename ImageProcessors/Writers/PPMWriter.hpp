#pragma once

#include "Writer.hpp"
#include "Formats/PPM.hpp"

class PPMWriter : public Writer<PPM>
{
public:
    PPMWriter(const PPM& ppm, const std::filesystem::path& path);

    virtual ~PPMWriter() override = default;

    void Write() const noexcept(false) override;
};