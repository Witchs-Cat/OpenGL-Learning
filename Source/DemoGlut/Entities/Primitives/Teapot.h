#pragma once

#include "..\GlutEntity.h"

class Teapot: public GlutEntity
{
public:
	Teapot(float size);
protected:
	void PushGlutEntity();

public:
	void Update(double elapsed);
};