#include "MovingCamera.h"

void MovingCamera::Update(UpdateEventArgs* args)
{
	double elapsed = args->GetElapsedMilliseconds();

	//Позиция курсора не высчитывается 
	if (args->KeyIsPressed('W'))
		_targetX += elapsed / 500;
	if (args->KeyIsPressed('A'))
		_targetY += elapsed / 500;
	if (args->KeyIsPressed('S'))
		_targetX -= elapsed / 500;
	if (args->KeyIsPressed('D'))
		_targetY -= elapsed / 500;
}

void MovingCamera::setAngelO(float angel)
{
	if (angel < 0)
		_angleO = 360;
	else if (angel > 360)
		_angleO = 0;
	else
		_angleO = angel;
}

void MovingCamera::setAngelF(float angel)
{
	if (angel < 0)
		_angleF = 360;
	else if (angel > 360)
		_angleF = 0;
	else
		_angleF = angel;
}

void MovingCamera::setRadius(float radius)
{
	if (radius < 0)
		return;

	_radius = radius;
}
