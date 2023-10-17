#include "Teapot.h"

Teapot::Teapot(float size): Teapot(size, false)
{ }

Teapot::Teapot(float size, bool isSolid) : GlutEntity(size)
{
	_renderFunc = isSolid? glutSolidTeapot :glutWireTeapot;
}


void Teapot::PushGlutEntity()
{
	_renderFunc(_modelSize);
}

void Teapot::Update(double elapsed)
{
}
