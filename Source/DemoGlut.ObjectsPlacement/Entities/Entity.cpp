#include "Entity.h"

void Entity::update(double elapsed)
{ }

void Entity::render(double elapsed) 
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glMultMatrixf(spaceModel);
	this->getSpaceModel();
	glPopMatrix();
}

void Entity::setPosition(float x,float y,float z) 
{
	this->x = x;
	this->y = y;
	this->z = z;

	spaceModel[12] = x;
	spaceModel[13] = y;
	spaceModel[14] = z;
}

void Entity::translate(float x, float y, float z) 
{
	translateX = x;
	translateY = y;
	translateZ = z;
}

void Entity::getSpaceModel() 
{
	glutWireTeapot(1);
}

void Entity::rotateXY(float angle) 
{
	float rad = angle / 180 * 3.14159f;

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	spaceModel[12] = x * sin - y * cos;
	spaceModel[13] = x * cos + y * sin;
	spaceModel[14] = z;
}

void Entity::rotateXZ(float angle) 
{
	float rad = angle / 180 * 3.14159f;

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	spaceModel[12] = this->translateX + x * cos + z * sin;
	spaceModel[13] = this->translateY + y;
	spaceModel[14] = this->translateZ + x * sin - z * cos;
}

void Entity::setAngle(float angle) 
{
	float rad = angle / 180 * 3.14159f;

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	spaceModel[0] = cos;
	spaceModel[2] = sin;
	spaceModel[8] = -sin;
	spaceModel[10] = cos;

}