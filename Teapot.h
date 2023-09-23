#pragma once

#include "Scalar.h"

class Teapot : public Scalar {
public:
	Teapot(float size) : Scalar(size) {};
protected:
	void getModel();
};