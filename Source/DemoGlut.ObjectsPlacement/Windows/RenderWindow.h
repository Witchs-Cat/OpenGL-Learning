#pragma once
#include <functional>
#include <ctime>   
#include <chrono>
#include <list>

#include "WindowSettings.h"
#include "../Entities/Entity.h"
class RenderWindow
{
private:
	int displayMode;
	int positionX;
	int positionY;
	int width;
	int height;
	int updateTime;
	std::string title;
	
	std::chrono::system_clock::time_point lastRenderingTime;

	std::list<Entity*> renderedEntities;

public:
	RenderWindow(WindowSettings* settings);
	// функция инициализации окна
	void init();
	// функция, вызываемая при изменении размеров окна
	void resize(int w, int h);
	// функция вызывается для обновления состояния
	void update(double elapsed);
	// для перерисовки
	void render(double elapsed);
	// функция вызывается каждые updateTime мс

	void addEntity(Entity* entity);

	void display(void);

	int getUpdateTime();
};

