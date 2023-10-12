#pragma once
#include "Entity.h"
class GlutEntity abstract:
    public Entity
{
private:
    float _red;
    float _green;
    float _blue;

protected:
    float _modelSize = 1.0f;
    virtual void PushGlutEntity() = 0;

public:
    void SetColor(float r, float g, float b);
    GlutEntity(float size);
    void Render(RenderEventArgs* args) override;
};

