#pragma once
#include <iostream>
#include <vector>
#include <exception>

#include "Camera.h"

class Screen
{
public:
	using Resolution = std::int16_t;

public:
	Screen() = delete;
	Screen(const Screen&) = default;

	Screen(const Resolution height, const Resolution width, float distance, const Camera& camera);

	~Screen() = default;

	inline const Resolution& GetHeigth() const noexcept { return m_Height; }
	inline const Resolution& GetWidth() const noexcept { return m_Width; }
	
	inline float GetPixelSize() const noexcept { return m_PixelSize; }
	inline float GetDistance() const noexcept { return m_Distance; }

private:
	const Resolution m_Height;
	const Resolution m_Width;

	float m_PixelSize;
	float m_Distance;
};