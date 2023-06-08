#pragma once

#include <iostream>
#include <vector>
#include <exception>

#include "Camera.h"

class Screen
{
public:
	using Resolution = std::int32_t;

public:
	Screen() = delete;
	Screen(const Screen&) = default;

	Screen::Screen(Screen&& other) noexcept	: m_Height(other.m_Height), m_Width(other.m_Width), m_Camera(std::move(other.m_Camera)),
		m_PixelSize(other.m_PixelSize),	m_Distance(other.m_Distance)
	{} ///added


	Screen(const Resolution height, const Resolution width, float distance, const Camera& camera);

	~Screen() = default;

	inline const Resolution& GetHeigth() const noexcept { return m_Height; }
	inline const Resolution& GetWidth() const noexcept { return m_Width; }

	inline const Camera& GetCamera() const noexcept { return m_Camera; }
	
	inline float GetPixelSize() const noexcept { return m_PixelSize; }
	inline float GetDistance() const noexcept { return m_Distance; }

private:
	const Resolution m_Height;
	const Resolution m_Width;

	//const Camera m_Camera;
	Camera m_Camera;

	float m_PixelSize;
	float m_Distance;
};