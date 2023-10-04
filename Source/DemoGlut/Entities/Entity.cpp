#include "Entity.h"

void Entity::Update(UpdateEventArgs* args)
{ }


void Entity::Render(RenderEventArgs* args) 
{ }

void Entity::SetPosition(float x,float y,float z) 
{
	_x = x;
	_y = y;
	_z = z;

	_viewProjectionMatrix[12] = x;
	_viewProjectionMatrix[13] = y;
	_viewProjectionMatrix[14] = z;
}

void Entity::Translate(float x, float y, float z) 
{
	_translateX = x;
	_translateY = y;
	_translateZ = z;
}


void Entity::RotateXY(float angle) 
{
	float rad = angle / 180 * 3.14159f;

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	_viewProjectionMatrix[12] = _x * sin - _y * cos;
	_viewProjectionMatrix[13] = _x * cos + _y * sin;
	_viewProjectionMatrix[14] = _z;
}

void Entity::RotateXZ(float angle) 
{
	float rad = angle / 180 * 3.14159f;

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	_viewProjectionMatrix[12] = this->_translateX + _x * cos + _z * sin;
	_viewProjectionMatrix[13] = this->_translateY + _y;
	_viewProjectionMatrix[14] = this->_translateZ + _x * sin - _z * cos;
}

void Entity::SetAngle(float angle) 
{
	float rad = angle / 180 * 3.14159f;

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	_viewProjectionMatrix[0] = cos;
	_viewProjectionMatrix[2] = sin;
	_viewProjectionMatrix[8] = -sin;
	_viewProjectionMatrix[10] = cos;

}