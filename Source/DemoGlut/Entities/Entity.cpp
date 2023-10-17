#include "Entity.h"

void Entity::Update(UpdateEventArgs* args)
{ }

void Entity::SetMaterial(shared_ptr<BaseMaterial> material)
{
	_material = material;
}


void Entity::Render(RenderEventArgs* args) 
{ }

Entity::Entity()
{
	_x = 0;
	_y = 0;
	_z = 0;
	_size = 1;
	_material = nullptr;
}

void Entity::SetPosition(float x,float y,float z)
{
	_x = x;
	_y = y;
	_z = z;

	_modelMatrix[12] = x;
	_modelMatrix[13] = y;
	_modelMatrix[14] = z;
}

void Entity::SetSize(float size)
{
	if (size < 0)
		_size = 0;
	else
		_size = size;
}

void Entity::RotateXZ(float angle)
{
	float rad = angle / 180 * 3.14159f;

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	_modelMatrix[0] = cos;
	_modelMatrix[2] = sin;
	_modelMatrix[8] = -sin;
	_modelMatrix[10] = cos;
}
