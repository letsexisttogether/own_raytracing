#include <iostream>
#include "Tracer.h"
#include <array>

int main()
{
	Screen<100, 100> screen;
	RayTracer RT = { {50.f, 50.f, 0.f}, 10 };
	Sphere sphere = { {50.f, 50.f, 60.f}, 50 };
	RT.Tracing(screen, sphere);
	screen.Print();
}