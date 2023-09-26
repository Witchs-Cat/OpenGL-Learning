// DemoGlut.Camera.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 

#include "GL/freeglut.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include "Windows/RenderWindow.h"
#include "Entities/Primitives/Teapot.h"

RenderWindow* window;

void display()
{	window->display();}

void reshape(int w, int h)
{	window->resize(w, h);}

void simulation(int value)
{
	glutPostRedisplay();
	// эта же функция будет вызвана еще раз спустя время
	glutTimerFunc(window->getUpdateTime() , simulation, 0);
}

void fillWithEntities()
{
	window->addEntity(new Teapot(1.0f, 5.0f, 0.0f, 0.0f));
	window->addEntity(new Teapot(1.0f, 0.0f, 0.0f, 5.0f));
	window->addEntity(new Teapot(1.0f, -5.0f, 0.0f, 0.0f));
	window->addEntity(new Teapot(1.0f, 0.0f, 0.0f, -5.0f));
}

int main(int argc, char** argv)
{	
	auto settings = new WindowSettings();
	settings->displayMode = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE;
	settings->height = 300;
	settings->width = 300;
	settings->updateTime = 20;

	window = new RenderWindow(settings);

	// инициализация библиотеки GLUT
	glutInit(&argc, argv);

	// инициализируем окно
	window->init();
	// заполняем окно сущностями
	fillWithEntities();

	// устанавливаем функцию отрисовки окна
	glutDisplayFunc(display);
	// устанавливаем функцию, которая будет вызываться при изменении размеров окна
	glutReshapeFunc(reshape);
	// устанавливаем функцию, которая будет вызвана через 0 мс
	glutTimerFunc(0, simulation, 2);
	// основной цикл обработки сообщений ОС
	glutMainLoop();

    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
