#include <windows.h>

#include <iostream>
#include <vector>

#include <chrono>

#include "Entity.h"
#include "Cup.h"
#include "Teapot.h"
#include "Cube.h"
#include "Camera.h"

using namespace std;
using namespace glm;

const int mSIMULATION_TIME = 20;

int mCurrentTick = 0;

vector<Entity*> mEntities;

Camera mCamera;

long getCurrentTimeInMillis() {
	return std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
}

// функция, вызываемая при изменении размеров окна
void reshape(int w, int h)
{
	// установить новую область просмотра, равную всей области окна
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// установить матрицу проекции с правильным аспектом
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 70.0);
};

// функция вызывается при перерисовке окна
// в том числе и принудительно, по командам glutPostRedisplay
void display(void)
{
	// отчищаем буфер цвета и буфер глубины
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	float r = sin(mCurrentTick / 180.0f * 3.14159f);

	// включаем тест глубины
	glEnable(GL_DEPTH_TEST);
	// устанавливаем камеру
	mCamera.requestLayout();
	//gluLookAt(10, 15, 17.5, 0, 0, 0, 0, 1, 0);

	for (Entity* en : mEntities) {
		//en->setAngle(mCurrentTick * 3.0f);
		//en->translate(r * 10, 0,0);
		//en->rotateXZ(mCurrentTick);
		en->render();
	}

	// смена переднего и заднего буферов
	glutSwapBuffers();

	mCurrentTick++;
};

// функция вызывается каждые 20 мс
void simulation(int value) {
	// устанавливаем признак того, что окно нуждается в перерисовке
	glutPostRedisplay();
	// эта же функция будет вызвана еще раз через 20 мс
	glutTimerFunc(mSIMULATION_TIME, simulation, 0);
};

// Функция обработки нажатия клавиш
void keyboardFunc(unsigned char key, int x, int y) {
	//printf("Key code is %i\n", key);
	
	switch (key) {
		case 'w':
			break;
		case 'a':
			break;
		case 's':
			break;
		case 'd':
			break;
	}
};


void main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");

	// инициализация библиотеки GLUT
	glutInit(&argc, argv);
	// инициализация дисплея (формат вывода)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// СОЗДАНИЕ ОКНА:
	// 1. устанавливаем верхний левый угол окна
	glutInitWindowPosition(0, 0);
	// 2. устанавливаем размер окна
	glutInitWindowSize(1280, 720);
	// 3. создаем окно
	glutCreateWindow("Teapot");

	mCamera.setPosition(50,0,0);

	mEntities.push_back(new Teapot(2.0f));
	mEntities.push_back(new Cube(1.5f));
	mEntities.push_back(new Cup(2.5f));
	mEntities.push_back(new Teapot(1.5f));

	mEntities[0]->setPosition(5, 0, 0);
	mEntities[1]->setPosition(-5, 0, 0);
	mEntities[2]->setPosition(0, 0, 5);
	mEntities[3]->setPosition(0, 0, -5);

	// УСТАНОВКА ФУНКЦИЙ ОБРАТНОГО ВЫЗОВА
	// устанавливаем функцию, которая будет вызываться для перерисовки окна
	glutDisplayFunc(display);
	// устанавливаем функцию, которая будет вызываться при изменении размеров окна
	glutReshapeFunc(reshape);
	// устанавливаем функцию, которая будет вызвана через 20 мс
	glutTimerFunc(mSIMULATION_TIME, simulation, 0);
	// устанавливаем функцию, которая будет вызываться при нажатии на клавишу
	glutKeyboardFunc(keyboardFunc);

	// основной цикл обработки сообщений ОС
	glutMainLoop();


};