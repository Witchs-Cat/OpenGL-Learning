#pragma once
#include "Entity.h"
class GlutEntity abstract:
    public Entity
{
protected:
    float _modelSize = 1.0f;
    virtual void GetViewProjectionMatrix() = 0;

public:
    GlutEntity(float size);
    void Render(RenderEventArgs* args) override;
};

