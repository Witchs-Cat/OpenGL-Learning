#pragma once

#include "WindowSettings.h"
#include "../Entities/Entity.h"
#include "../EventArgs/EventsFactory.h"
#include "../Camera/BaseCamera.h"

class RenderWindow : IDisplayedObject
{
private:
	EventsFactory* _eventsFactory;
	int _displayMode;
	int _positionX;
	int _positionY;
	int _width;
	int _height;
	int _updateTime;
	std::string _title;

	std::list<Entity*> _renderedEntities;

public:
	//Проблемка, как не допустить утечку памяти, 
	//но красиво убрать проверку на nullptr
	BaseCamera* Camera;

	RenderWindow(WindowSettings* settings);
	// функция инициализации окна
	void Init();
	// функция, вызываемая при изменении размеров окна
	void Resize(int w, int h);
	// функция вызывается для обновления состояния
	void Update(UpdateEventArgs* args) override;
	// для перерисовки
	void Render(RenderEventArgs* args) override;
	// функция вызывается каждые updateTime мс

	void AddEntity(Entity* entity);

	void SetCamera(BaseCamera* camera);

	void Display(void);

	int GetUpdateTime();
};

