#pragma once
#include <windows.h>

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 

#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"


class Entity {
private:
	
	float x = 0;
	float y = 0;
	float z = 0;

	float translateX = 0;
	float translateY = 0;
	float translateZ = 0;

	GLfloat model[16] = {
		 1,  0,  0,  0,
		 0,  1,  0,  0,
		 0,  0,  1,  0,
		 0,  0,  0,  1 // default position (x,y,z)
	};



protected:
	virtual void getModel()=0;
public:

	void recalculateMatrix();

	void setPosition(float x, float y, float z);
	void setAngle(float angle);
	void rotateXY(float angle);
	void rotateXZ(float angle);
	void translate(float x, float y, float z);
	void render();
};