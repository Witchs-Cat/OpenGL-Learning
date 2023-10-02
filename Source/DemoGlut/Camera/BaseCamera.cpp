#include "BaseCamera.h"

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
