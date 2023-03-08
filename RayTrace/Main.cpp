#include <iostream>
#include <array>

#include "Render/Tracer.h"
#include "Scene.h"

int main()
{
	float pi = 3.1415926535;
	Camera camera = { {0.f, 0.f, 0.f}, {0.f, 0.f, 1.f}, 1.37340077 * 2.f };
	Screen screen{ 100u, 100u, 10, camera };

	//Vector3d light = { 5.f, -10.f, 15.f };
	Vector3d light = { -10.f, -20.f, 5.f };
	RayTracer RT{ screen, camera, light.Normalize() }; //normal { 0.f, 0.f, 1.f}
	
	Plane plane = { {-5.f, 0.f, 40.f}, {10.f, 10.f, 10.f} };

	Scene scene = { RT };
	scene.AddToScene(new Sphere({ 0.f, 0.f, 30.f }, 27));
	scene.AddToScene(new Plane({ -5.f, 0.f, 40.f }, { 10.f, 10.f, 10.f }));
	scene.AddToScene(new Disk(plane, 10));
	scene.Trace();
}