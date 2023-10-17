#include "MovingCamera.h"

void MovingCamera::UpdateCameraPosition()
{
	float radF = _angleF / 180 * 3.14159f;
	float radO = _angleO / 180 * 3.14159f;

	_cameraX = _radius * sin(radO) * cos(radF) + _targetX;
	_cameraY = _radius * cos(radO) + _targetY; 
	_cameraZ = _radius * sin(radO) * sin(radF) + _targetZ;

}

MovingCamera::MovingCamera(float radius, float angelO, float angelF)
{
	_radius = radius;
	_angleO = angelO;
	_angleF = angelF;

	UpdateCameraPosition();
}

void MovingCamera::Update(UpdateEventArgs* args)
{
	double elapsed = args->GetElapsedMilliseconds();

	if (args->KeyIsPressed('W'))
		_targetZ += elapsed / 500;
	if (args->KeyIsPressed('A'))
		_targetX -= elapsed / 500;
	if (args->KeyIsPressed('S'))
		_targetZ -= elapsed / 500;
	if (args->KeyIsPressed('D'))
		_targetX += elapsed / 500;

	if (args->KeyIsPressed(VK_SHIFT))
		setRadius(_radius + elapsed / 100);
	if (args->KeyIsPressed(VK_CONTROL))
		setRadius(_radius - elapsed / 100);

	if (args->KeyIsPressed(VK_LBUTTON))
	{
		POINT* cursorMove = args->GetCursorData()->GetMove();
		setAngelO(_angleO - cursorMove->y / 5.0f);
		setAngelF(_angleF + cursorMove->x / 5.0f);
	}

	UpdateCameraPosition();
}

void MovingCamera::setAngelO(float angle)
{
	if (angle > 85) angle = 85;
	else if (angle < 5) angle = 5;

	_angleO = angle;
}

void MovingCamera::setAngelF(float angle)
{

	if (angle > 360) angle -= 360;
	else if (angle < -360) angle += 360;

	_angleF = angle;
}

void MovingCamera::setRadius(float radius)
{
	if (radius < 0)
		return;

	_radius = radius;
}
