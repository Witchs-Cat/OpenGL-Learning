#include "Teapot.h"

Teapot::Teapot(float size): GlutEntity(size)
{ }

void Teapot::PushGlutEntity()
{
	glutWireTeapot(_modelSize);
}

void Teapot::Update(double elapsed)
{
}
