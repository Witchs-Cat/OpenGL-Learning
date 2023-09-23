#pragma once

#include "Entity.h"

class Scalar : public Entity {
protected:
	float mSize = 1.0f;
public:
	Scalar(float size);
};