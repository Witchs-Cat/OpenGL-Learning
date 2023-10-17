#pragma once
#include "..\IDisplayedObject.h"
#include "..\Materials\BaseMaterial.h"

class Entity : IDisplayedObject
{
private:
	float _x;
	float _y;
	float _z;
	float _size;

protected:
	shared_ptr<BaseMaterial> _material;

	GLfloat _modelMatrix[16] = {
		 1,  0,  0,  0, // ось Ox
		 0,  1,  0,  0, // ось Oy
		 0,  0,  1,  0, // ось Oz
		 0,  0,  0,  1  // позиция объекта (начало системы координат)
	};

public:

	Entity();

	void SetPosition(float x, float y, float z);
	void SetSize(float size);
	void RotateXZ(float angle);
	void SetMaterial(shared_ptr<BaseMaterial> material);

	void virtual Render(RenderEventArgs* args) override;
	void virtual Update(UpdateEventArgs* args) override;
};

