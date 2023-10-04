#include "GlutEntity.h"

GlutEntity::GlutEntity(float size)
{
	_modelSize = size;
}

void GlutEntity::GetViewProjectionMatrix()
{ }

void GlutEntity::Render(RenderEventArgs* args)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glMultMatrixf(_viewProjectionMatrix);
	this->GetViewProjectionMatrix();
	glPopMatrix();
}
