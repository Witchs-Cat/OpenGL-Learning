#pragma once

#include "Scalar.h"

class Cube : public Scalar {
public:
	Cube(float size) : Scalar(size) {};
protected:
	void getModel();
};