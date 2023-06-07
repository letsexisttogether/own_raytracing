#include "../Triangle.hpp"

Triangle::Triangle(const Vector3d& v0, const Vector3d& v1, const Vector3d& v2)
	: m_V0{ v0 }, m_V1(v1), m_V2(v2)
{}

std::optional<Intersection> Triangle::IntersectedWithRay(const Ray & ray, float* parametr) const noexcept
{
    const float eps = 0.000001f;

    Vector3d edge1 = m_V1 - m_V0;
    Vector3d edge2 = m_V2 - m_V0;

    Vector3d rayDirection = ray.GetDirection();
    Vector3d rayOrigin = ray.GetOrigin();

    Vector3d h = rayDirection.Cross(edge2);
    float a = edge1.Dot(h);

    if (std::abs(a) < eps)
    {
        return std::nullopt;
    }

    float f = 1.0f / a;
    Vector3d s = rayOrigin - m_V0;
    float u = f * s.Dot(h);

    if (u < 0.0f || u > 1.0f)
    {
        return std::nullopt;
    }

    Vector3d q = s.Cross(edge1);
    float v = f * rayDirection.Dot(q);

    if (v < 0.0f || u + v > 1.0f)
    {
        return std::nullopt;
    }

    float t = f * edge2.Dot(q);

    if (t > eps)
    {
        Vector3d intersectionPoint = rayOrigin + rayDirection * t;
        Vector3d normal = edge1.Cross(edge2).Normalize();

        return Intersection{ intersectionPoint, normal, (intersectionPoint - rayOrigin).GetLength() };
    }

    return std::nullopt;
}

Vector3d Triangle::GetMax()
{
    return { std::max(std::max(m_V0.GetX(),m_V1.GetX()),m_V2.GetX()), std::max(std::max(m_V0.GetY(),m_V1.GetY()),m_V2.GetY()),
        std::max(std::max(m_V0.GetZ(),m_V1.GetZ()),m_V2.GetZ()) };
}

Vector3d Triangle::GetMin()
{
    return { std::min(std::min(m_V0.GetX(),m_V1.GetX()),m_V2.GetX()), std::min(std::min(m_V0.GetY(),m_V1.GetY()),m_V2.GetY()),
        std::min(std::min(m_V0.GetZ(),m_V1.GetZ()),m_V2.GetZ()) };
}

Triangle Triangle::operator * (const Matrix4& transformMatrix) noexcept
{
    Triangle triangle{ *this };

    triangle.m_V0 = Vector4{ m_V0 } * transformMatrix;
    triangle.m_V1 = Vector4{ m_V1 } * transformMatrix;
    triangle.m_V2 = Vector4{ m_V2 } * transformMatrix;

    return triangle;
}


AABB3 Triangle::BuildBox() { return { GetMin(), GetMax() }; }

Vector3d Triangle::GetCenter() const
{
    return (m_V0 + m_V1 + m_V2) * (1.f / 3.f);
}

