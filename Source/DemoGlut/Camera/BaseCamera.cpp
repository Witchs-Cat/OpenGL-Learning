#include "BaseCamera.h"

BaseCamera::BaseCamera()
{
	_cameraX = 0; _cameraY = 0; _cameraZ = 0;
	_targetX = 0; _targetY = 0; _targetZ = 0;
	_upX = 0; _upY = 0; _upZ = 0;
}

void BaseCamera::Render(RenderEventArgs* args)
{
	gluLookAt(_cameraX, _cameraY, _cameraZ,
		_targetX, _targetY, _targetZ,
		_upX, _upY, _upZ);
}

void BaseCamera::Update(UpdateEventArgs* args)
{

}

void BaseCamera::SetCameraPosition(double x, double y, double z)
{
	_cameraX = x;
	_cameraY = y;
	_cameraZ = z;
}

void BaseCamera::SetTargetPosition(double x, double y, double z)
{
	_targetX = x;
	_targetY = y;
	_targetZ = z;
}

void BaseCamera::SetUpVector(double x, double y, double z)
{
	_upX = x;
	_upY = y;
	_upZ = z;
}
