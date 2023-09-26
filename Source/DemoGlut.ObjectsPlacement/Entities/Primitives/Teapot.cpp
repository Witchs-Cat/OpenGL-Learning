#include "Teapot.h"

Teapot::Teapot(float size): Teapot(size, 0,0,0)
{ }

Teapot::Teapot(float size, float x, float y, float z): Scalar(size)
{
	setPosition(x, y, z);
}

void Teapot::getSpaceModel()
{
	glutWireTeapot(mSize);
}

void Teapot::update(double elapsed)
{
}
