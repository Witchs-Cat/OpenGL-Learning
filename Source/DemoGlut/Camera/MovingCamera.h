#pragma once
#include "BaseCamera.h"

class MovingCamera :
    public BaseCamera
{
private:
    //Z ~ XY
    float _angleO;
    //X ~ Y
    float _angleF;
    float _radius = 30;

    
    void UpdateCameraPosition();
public:
    void Update(UpdateEventArgs* args) override;

    void setAngelO(float angel);
    void setAngelF(float angel);
    void setRadius(float radius);
};

