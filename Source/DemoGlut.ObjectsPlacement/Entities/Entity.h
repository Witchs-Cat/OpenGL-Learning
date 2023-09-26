#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "GL/freeglut.h"
#include <GL/gl.h>
#include <GL/glu.h>

class Entity
{
private:
	float x = 0;
	float y = 0;
	float z = 0;

	float translateX = 0;
	float translateY = 0;
	float translateZ = 0;

	GLfloat spaceModel[16] = {
		 1,  0,  0,  0, // ось Ox
		 0,  1,  0,  0, // ось Oy
		 0,  0,  1,  0, // ось Oz
		 0,  0,  0,  1  // позиция объекта (начало системы координат)
	};

protected:
	virtual void getSpaceModel() = 0;

public:
	void setPosition(float x, float y, float z);
	void setAngle(float angle);
	void rotateXY(float angle);
	void rotateXZ(float angle);
	void translate(float x, float y, float z);

	virtual void update(double elapsed);
	virtual void render(double elapsed);
};

