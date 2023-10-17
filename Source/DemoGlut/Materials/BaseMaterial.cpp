#include "BaseMaterial.h"

BaseMaterial::BaseMaterial(
	vec4 ambient, vec4 diffuse,
	vec4 specular, vec4 emission,
	float shininess)
{
	_ambient = ambient;
	_diffuse = diffuse;
	_specular = specular;
	_emission = emission;
	_shininess = shininess;
}

BaseMaterial::BaseMaterial() 
	:BaseMaterial(vec4(), vec4(), vec4(), vec4(), 0)
{ }


vec4 toVec4(vector<float> vec)
{
	return vec4(vec[0], vec[1], vec[2], vec[3]);
}

vec4 getVec4Field(Node yaml, string fieldName)
{
	return toVec4(yaml[fieldName].as<vector<float>>());
}

shared_ptr<BaseMaterial> BaseMaterial::LoadFromYaml(std::string filename)
{
	Node yaml = LoadFile(filename);

	vec4 ambient = getVec4Field(yaml, "ambient");
	vec4 diffuse = getVec4Field(yaml, "diffuse");	
	vec4 specular = getVec4Field(yaml, "specular");
	vec4 emission = getVec4Field(yaml, "emission");
	float shininess = yaml["shininess"].as<float>();

	return shared_ptr<BaseMaterial>(new BaseMaterial(ambient, diffuse, specular, emission, shininess));
}

void BaseMaterial::SetAmbient(vec4 color)
{
	_ambient = color;
}

void BaseMaterial::SetDiffuse(vec4 color)
{
	_diffuse = color;
}

void BaseMaterial::SetSpecular(vec4 color)
{
	_specular = color;
}

void BaseMaterial::SetEmission(vec4 color)
{
	_emission = color;
}

void BaseMaterial::SetShininess(float p)
{
	_shininess = p;
}

void BaseMaterial::Apply()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, value_ptr(_ambient));
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, value_ptr(_diffuse));
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, value_ptr(_specular));
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, value_ptr(_emission));
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, _shininess);
}
