#pragma once

#include "..\Entity.h"

class Grid : public Entity
{
public:
	void virtual Render(RenderEventArgs* args) override;
};

