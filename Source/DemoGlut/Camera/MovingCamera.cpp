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
		setRadius(_radius + elapsed / 100);
	if (args->KeyIsPressed(VK_CONTROL))
		setRadius(_radius - elapsed / 100);

	if (args->KeyIsPressed(VK_LBUTTON))
	{
		POINT* cursorMove = args->GetCursorData()->GetMove();
		setAngelO(_angleO + cursorMove->y / 5.0f);
		setAngelF(_angleF + cursorMove->x / 5.0f);
		//std::cout << "F= " << _angleF << " O= " << _angleO << " R= " << _radius << std::endl;
		//std::cout << "X= " << _cameraX << " Y= " << _cameraY << " Z= " << _cameraZ << std::endl;
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
