
#include "Entity.h"
#include "Camera.h"

void Camera::setPosition(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Camera::getX() {
	return x;
}

float Camera::getY() {
	return y;
}

float Camera::getZ() {
	return z;
}

void Camera::requestLayout() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z,
	    	0, 0, 0,
	       	0, 1, 0);
}