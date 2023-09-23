#pragma once

#include "Scalar.h"

class Cup : public Scalar {
public:
	Cup(float size) : Scalar(size) {}
protected:
	void getModel();
};