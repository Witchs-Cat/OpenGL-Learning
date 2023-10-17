#pragma once
#include "..\IDisplayedObject.h"

class BaseLight
{
private:
	// позиция источника света
	vec4 _position;
	// фоновая составляющая источника света
	vec4 _ambient;
	// диффузная составляющая
	vec4 _diffuse;
	// зеркальная составляющая
	vec4 _specular;

public:
	// конструкторы
	BaseLight();
	BaseLight(vec3 position);
	BaseLight(float x, float y, float z);
	// задание различных параметров источника света
	void SetPosition(vec3 position);
	void SetAmbient(vec4 color);
	void SetDiffuse(vec4 color);
	void SetSpecular(vec4 color);
	// установка всех параметров источника света с заданным номером
	// данная функция должна вызываться после установки камеры,
	// т.к. здесь устанавливается позиция источника света
	void Apply(GLenum LightNumber = GL_LIGHT0);
};

