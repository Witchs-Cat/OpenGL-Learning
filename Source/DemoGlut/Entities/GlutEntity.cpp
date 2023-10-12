#include "GlutEntity.h"

void GlutEntity::SetColor(float r, float g, float b)
{
	_red = (r < 1.0f)? r: 1.0f;
	_green = (g < 1.0f) ? g : 1.0f;
	_blue = (b < 1.0f) ? b : 1.0f;

}

GlutEntity::GlutEntity(float size)
{
	_modelSize = size;
	SetColor(1.0f, 1.0f, 1.0f);
}

void GlutEntity::PushGlutEntity()
{ }

void GlutEntity::Render(RenderEventArgs* args)
{
	glColor3f(_red, _green, _blue);
	glPushMatrix();
	glMultMatrixf(_modelMatrix);
	this->PushGlutEntity();
	glPopMatrix();
}
