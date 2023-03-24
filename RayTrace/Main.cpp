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
	
	scene.AddToScene(new Sphere({ -50.f, 50.f, 60.f }, 50.f));
	scene.AddToScene(new Sphere({ 70.f, 0.f, 31.f }, 30.f));
	scene.AddToScene(new Sphere({ 0.f, 0.f, 40.f }, 30.f));
	RT.Tracing(scene);
	RT.GetScreen().Print();
	//screen.Print();
	/*scene.AddToScene(new Plane({ -5.f, 0.f, 40.f }, { 10.f, 10.f, 10.f }));
	scene.AddToScene(new Disk(plane, 10));*/
	//scene.Trace();
	//scene.PrintScreen();
}