#pragma once

#include "..\Scalar.h"

class Teapot: public Scalar 
{
public:
	Teapot(float size);
	Teapot(float size, float positionX, float positionY, float positionZ);

protected:
	void GetViewProjectionMatrix();

public:
	void Update(double elapsed);
};