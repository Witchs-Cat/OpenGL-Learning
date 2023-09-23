#include "Entity.h"

class Camera {
	float x;
	float y;
	float z;
public:
	void setPosition(float x, float y, float z);
	void requestLayout();
	float getX();
	float getY();
	float getZ();
};