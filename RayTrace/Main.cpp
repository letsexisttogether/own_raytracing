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
	Vector3d light = { 5.f, -10.f, 15.f };
	RayTracer RT{ screen, camera, light.Normalize() }; //normal { 0.f, 0.f, 1.f}
	
	/*Sphere sphere = { {0.f, 0.f, 30.f}, 25 };
	RT.Tracing(sphere);

	Plane plane = { {-5.f, 0.f, 40.f}, {10.f, 10.f, 10.f} };
	RT.Tracing(plane);
	
	Disk disk = { plane, 15 };	
	RT.Tracing(disk);*/
	Plane plane = { {-5.f, 0.f, 40.f}, {10.f, 10.f, 10.f} };

	Scene scene = { RT };
	scene.AddToScene(new Sphere({ 0.f, 0.f, 30.f }, 25));
	scene.AddToScene(new Plane({ -5.f, 0.f, 40.f }, { 10.f, 10.f, 10.f }));
	scene.AddToScene(new Disk(plane, 15));
	scene.Trace();
}