#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(SphereTest)
	{
	public:
		
		TEST_METHOD(IntersectionFalse)
		{
			Sphere sphere = Sphere(Vector3d{ 50.f, 50.f, 60.f }, 40.f);
			Ray ray = Ray(Vector3d{ 5, 7, 8 }, Vector3d{ 5, -1, 3 });

			bool intersected = sphere.IntersectedWithRay(ray, nullptr).has_value();

			Assert::AreEqual(intersected, false);
		}

		TEST_METHOD(IntersectionTrue)
		{
			Sphere sphere = Sphere(Vector3d{ 1.13f, -0.4f, 3.1f }, 4.f);
			Ray ray = Ray(Vector3d{ -2.08f, 2.59f, 0.f }, Vector3d{ 6.02f, -3.53f, 5.9f });

			bool intersected = sphere.IntersectedWithRay(ray, nullptr).has_value();

			Assert::AreEqual(intersected, true);
		}

		TEST_METHOD(ComplexIntersectionTrue)
		{
			Sphere sphere = Sphere(Vector3d{ 0.112f, 0.121f, 0.f }, 1.536);
			Ray ray = Ray(Vector3d{ 7.985f,-3.484f, 0.f }, Vector3d{ 5.62f,-2.76f, 0.f });
		
			bool intersected = sphere.IntersectedWithRay(ray, nullptr).has_value();

			Assert::AreEqual(intersected, true);
		}
	};

	TEST_CLASS(DiskTest)
	{
	public:
		TEST_METHOD(IntersectionTrue)
		{
			Plane plane = Plane(Vector3d{ 4.f, -9.f, 4.f }, Vector3d{ 2.f, -3.f, -4.f });
			Ray ray = Ray(Vector3d{ 0.f, 3.f, 0.f }, Vector3d{ 9.f, -8.f, 4.f });
			Disk disk = Disk(plane, 10.f);

			bool intersected = disk.IntersectedWithRay(ray, nullptr).has_value();

			Assert::AreEqual(intersected, true);
		}

		TEST_METHOD(IntersecionFalse)
		{
			Plane plane = Plane(Vector3d{ 4.f, -9.f, 4.f }, Vector3d{ 2.f, -3.f, -4.f });
			Ray ray = Ray(Vector3d{ 0.f, 3.f, 0.f }, Vector3d{ 12.f, -2.f, 4.f });
			Disk disk = Disk(plane, 10.f);

			bool intersected = disk.IntersectedWithRay(ray, nullptr).has_value();

			Assert::AreEqual(intersected, false);
		}
	};

	TEST_CLASS(Vector3dTest)
	{
	public:
		TEST_METHOD(LengthCheck)
		{
			Vector3d vec = { 45.f, 200.f, -11.f };

			float lenght = vec.GetLength();
			bool isCorrect = lenght <= 205.294f + 0.01f && lenght >= 205.294f - 0.01f;

			Assert::AreEqual(isCorrect, true);
		}

		TEST_METHOD(ComplexLenghtCheck)
		{
			Vector3d vec = { 0.31212f, -0.121121f, 0.121f };

			float length = vec.GetLength();
			bool isCorrect = length <= 0.35599 + 0.0001 && length <= 0.35599 - 0.0001;

			Assert::AreEqual(isCorrect, true);
		}
	};
}
