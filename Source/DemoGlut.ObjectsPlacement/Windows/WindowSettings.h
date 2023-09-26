#pragma once
#include <string>

class WindowSettings
{
public:
	int displayMode;
	int positionX;
	int positionY;
	int width;
	int height;
	unsigned int updateTime;
	std::string title;

	WindowSettings();
};

