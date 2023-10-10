#include "MovingCamera.h"

void MovingCamera::UpdateCameraPosition()
{
	_cameraX = _radius * sin(_angleO) * cos(_angleF) + _targetX;
	_cameraY = _radius * sin(_angleO) * sin(_angleF) + _targetY;
	_cameraZ = _radius * cos(_angleO) + _targetZ;

}

void MovingCamera::Update(UpdateEventArgs* args)
{
	double elapsed = args->GetElapsedMilliseconds();

	//Позиция курсора не высчитывается 
	if (args->KeyIsPressed('W'))
		_targetY += elapsed / 500;
	if (args->KeyIsPressed('A'))
		_targetX -= elapsed / 500;
	if (args->KeyIsPressed('S'))
		_targetY -= elapsed / 500;
	if (args->KeyIsPressed('D'))
		_targetX += elapsed / 500;

	if (args->KeyIsPressed(VK_SHIFT))
		_radius += elapsed / 100;
	if (args->KeyIsPressed(VK_CONTROL))
		_radius -= elapsed / 100;

	if (args->KeyIsPressed(VK_LBUTTON))
	{
		POINT* cursorMove = args->GetCursorMove();
		//setAngelF(_angleF + cursorMove->y / 500.0f);
		setAngelO(_angleO - cursorMove->x / 500.0f);
	}


	UpdateCameraPosition();
}

void MovingCamera::setAngelO(float angel)
{
		_angleO = angel;
}

void MovingCamera::setAngelF(float angel)
{
		_angleF = angel;
}

void MovingCamera::setRadius(float radius)
{
	if (radius < 0)
		return;

	_radius = radius;
}
