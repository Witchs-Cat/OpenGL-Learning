#pragma once

#include "..\GlutEntity.h"

class Teapot: public GlutEntity
{
private:
	void (*_renderFunc)(double size);
public:
	Teapot(float size);
	Teapot(float size, bool isSolid );
protected:
	void PushGlutEntity();

public:
	void Update(double elapsed);
};