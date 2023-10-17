#include "BaseLight.h"

BaseLight::BaseLight() : BaseLight(0,0,0)
{
}

BaseLight::BaseLight(vec3 position)
{
	SetPosition(position);
}

BaseLight::BaseLight(float x, float y, float z) : BaseLight(vec3(x,y,z))
{
}

void BaseLight::SetPosition(vec3 position)
{
	_position = vec4(position, 1);
}

void BaseLight::SetAmbient(vec4 color)
{
	_ambient = color;
}

void BaseLight::SetDiffuse(vec4 color)
{
	_diffuse = color;
}

void BaseLight::SetSpecular(vec4 color)
{
	_specular = color;
}

void BaseLight::Apply(GLenum lightNumber)
{
	glLightfv(lightNumber, GL_AMBIENT, value_ptr(_ambient));
	glLightfv(lightNumber, GL_DIFFUSE, value_ptr(_diffuse));
	glLightfv(lightNumber, GL_SPECULAR, value_ptr(_specular));	
	glLightfv(lightNumber, GL_POSITION, value_ptr(_position));
}

