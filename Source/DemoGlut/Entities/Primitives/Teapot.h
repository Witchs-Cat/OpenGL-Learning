#pragma once

#include "..\GlutEntity.h"

class Teapot: public GlutEntity
{
public:
	Teapot(float size);
	Teapot(float size, float positionX, float positionY, float positionZ);

protected:
	void GetViewProjectionMatrix();

public:
	void Update(double elapsed);
};