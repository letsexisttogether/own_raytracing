#include <iostream>
#include <array>

#include "Render/Tracer.h"

int main()
{
	Screen<100, 100> screen;
	Vector3d light = { 5.f, 10.f, 15.f };
	RayTracer RT = { {50.f, 50.f, 0.f}, light.Normalize(), 10}; //normal { 0.f, 0.f, 1.f}
	Sphere sphere = { {50.f, 50.f, 60.f}, 50 };
	RT.Tracing(screen, sphere);
	Plane plane = { {50.f, 50.f, 15.f}, {50.f, 40.f, 5.f} };
	screen.Print();
	RT.Tracing(screen, plane);
	screen.Print();
	Disk disk = { plane, 15 };	
	RT.Tracing(screen, disk);
	screen.Print();
}