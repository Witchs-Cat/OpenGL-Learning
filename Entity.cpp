#include "Entity.h"

void Entity::setPosition(
	float x,
	float y,
	float z) {
	this->x = x;
	this->y = y;
	this->z = z;

	model[12] = x;
	model[13] = y;
	model[14] = z;
}

void Entity::translate(
	float x,
	float y,
	float z) {
	translateX = x;
	translateY = y;
	translateZ = z;
}

void Entity::getModel() {
	glutWireTeapot(1);
}

void Entity::render() {
	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix();
	glMultMatrixf(model);
	getModel();
	glPopMatrix();
}

void Entity::rotateXY(float angle) {
	float rad = angle / 180 * 3.14159f;

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	model[12] = x * sin - y * cos;
	model[13] = x * cos + y * sin;
	model[14] = z;
}

void Entity::rotateXZ(float angle) {
	float rad = angle / 180 * 3.14159f;

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	model[12] = this->translateX + x * cos + z * sin;
	model[13] = this->translateY + y;
	model[14] = this->translateZ + x * sin - z * cos;
}

void Entity::setAngle(float angle) {
	float rad = angle / 180 * 3.14159f; //По приколу 5 поставил)

	float sin = std::sin(rad);
	float cos = std::cos(rad);

	model[0] = cos;
	model[2] = sin;
	model[8] = -sin;
	model[10] = cos;
	
}