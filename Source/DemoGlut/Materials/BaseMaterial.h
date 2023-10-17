#pragma once
#include "..\IDisplayedObject.h"

using namespace YAML;

class BaseMaterial
{
private:
	// фоновая составляющая
	vec4 _ambient;
	// диффузная составляющая
	vec4 _diffuse;
	// зеркальная составляющая
	vec4 _specular;
	// самосвечение
	vec4 _emission;
	// степень отполированности
	float _shininess;

public:
	// конструктор по умолчанию
	BaseMaterial();
	BaseMaterial(
		vec4 ambient,vec4 diffuse,
		vec4 specular,vec4 emission,
		float shininess);

	// загрузка параметров материала из внешнего текстового файла
	static shared_ptr<BaseMaterial> LoadFromYaml(std::string filename);
	// задание параметров материала
	void SetAmbient(vec4 color);
	void SetDiffuse(vec4 color);
	void SetSpecular(vec4 color);
	void SetEmission(vec4 color);
	void SetShininess(float p);
	// установка всех параметров материала
	void Apply();
};

