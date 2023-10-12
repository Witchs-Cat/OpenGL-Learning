#include "RenderWindow.h"

RenderWindow::RenderWindow(WindowSettings* settings)
{
	Camera = nullptr;
	_eventsFactory = new EventsFactory();
	_displayMode = settings->DisplayMode;
	_positionX = settings->PositionX;
	_positionY = settings->PositionY;
	_width = settings->Width;
	_height = settings->Height;
	_updateTime = settings->UpdateTime;
	_title = settings->Title;
}

void RenderWindow::Resize(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
	glutPostRedisplay();
}

void RenderWindow::Update(UpdateEventArgs* args)
{
	if (args->KeyIsPressed(VK_ESCAPE))
		exit(0);

	if (Camera != nullptr)
		Camera->Update(args);

	for (Entity* entity : _renderedEntities)
		entity->Update(args);
}

void RenderWindow::Render(RenderEventArgs* args)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	double elapsed = args->GetElapsedMilliseconds();
	_elapsedMilliseconds += elapsed;
	_framesCount++;

	if (_elapsedMilliseconds > 1E3)
	{
		int fps = _framesCount / _elapsedMilliseconds * 1E3;
		glutSetWindowTitle(std::to_string(fps).c_str());

		_framesCount = 0;
		_elapsedMilliseconds = 0;
	}
	
	if (Camera != nullptr)
		Camera->Render(args);

	for (Entity* entity : _renderedEntities)
		entity->Render(args);

	glutSwapBuffers();
}

void RenderWindow::Display(void)
{
	UpdateEventArgs* updateArgs;
	RenderEventArgs* renderArgs;
	_eventsFactory->UpdateState();
	Update(_eventsFactory->GetUpdateArgs());
	Render(_eventsFactory->GetRenderArgs());
}

int RenderWindow::GetUpdateTime()
{
	return _updateTime;
}

void RenderWindow::AddEntity(Entity* entity)
{
	_renderedEntities.push_back(entity);
}

void RenderWindow::SetCamera(BaseCamera* camera)
{
	Camera = camera;
}

void RenderWindow::Init()
{
	// инициализация дисплея (формат вывода)
	glutInitDisplayMode(_displayMode);
	// СОЗДАНИЕ ОКНА:
	// 1. устанавливаем верхний левый угол окна
	glutInitWindowPosition(_positionX, _positionY);
	// 2. устанавливаем размер окна
	glutInitWindowSize(_width, _height);
	// 3. создаем окно
	glutCreateWindow(_title.c_str());

	//Включаем один раз тест глубины и не праимся.
	glEnable(GL_DEPTH_TEST);

	_eventsFactory->UpdateState();
}