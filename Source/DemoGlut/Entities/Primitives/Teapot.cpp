#include "Teapot.h"

Teapot::Teapot(float size): Teapot(size, 0,0,0)
{ }

Teapot::Teapot(float size, float x, float y, float z): Scalar(size)
{
	SetPosition(x, y, z);
}

void Teapot::GetViewProjectionMatrix()
{
	glutWireTeapot(_modelSize);
}

void Teapot::Update(double elapsed)
{
}
