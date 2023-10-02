#pragma once

#include "Entity.h"

class Scalar : public Entity 
{
protected:
	float _modelSize = 1.0f;

public:
	Scalar(float size);
};