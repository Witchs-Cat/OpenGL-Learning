#include "RenderWindow.h"

RenderWindow::RenderWindow(WindowSettings* settings)
{
	displayMode = settings->displayMode;
	positionX = settings->positionX;
	positionY = settings->positionY;
	width = settings->width;
	height = settings->height;
	updateTime = settings->updateTime;
	title = settings->title;
}

void RenderWindow::resize(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
	glutPostRedisplay();
}

void RenderWindow::update(double elapsed)
{
	for (Entity* entity : renderedEntities)
	{
		entity->update(elapsed);
	}
}

void RenderWindow::render(double elapsed)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10, 15, 17.5, 0, 0, 0, 0, 1, 0);


	for (Entity* entity : renderedEntities)
	{
		entity->render(elapsed);
	}

	glutSwapBuffers();
}

void RenderWindow::display(void)
{
	auto now = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed = now - this->lastRenderingTime;
	
	this->lastRenderingTime = now;

	update(elapsed.count());
	render(elapsed.count());
}

int RenderWindow::getUpdateTime()
{
	return this->updateTime;
}

void RenderWindow::addEntity(Entity* entity)
{
	this->renderedEntities.push_back(entity);
}

void RenderWindow::init()
{
	// инициализация дисплея (формат вывода)
	glutInitDisplayMode(this->displayMode);

	// СОЗДАНИЕ ОКНА:
	// 1. устанавливаем верхний левый угол окна
	glutInitWindowPosition(this->positionX, this->positionY);
	// 2. устанавливаем размер окна
	glutInitWindowSize(this->width, this->height);
	// 3. создаем окно
	glutCreateWindow(this->title.c_str());

	//Включаем один раз тест глубины и не праимся.
	glEnable(GL_DEPTH_TEST);
}