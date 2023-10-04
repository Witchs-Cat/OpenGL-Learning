// DemoGlut.Camera.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Windows/RenderWindow.h"
#include "Entities/Primitives/Teapot.h"

RenderWindow* window;

void Display()
{	window->Display();}

void Reshape(int w, int h)
{	window->Resize(w, h);}

void Simulation(int value)
{
	glutPostRedisplay();
	// эта же функция будет вызвана еще раз спустя время
	glutTimerFunc(window->GetUpdateTime() , Simulation, 0);
}

void FillWithEntities()
{
	window->SetCamera(new MovingCamera());
	window->Camera->SetCameraPosition(0, 0, 55);
	window->Camera->SetUpVector(0, 1, 0);

	window->AddEntity(new Teapot(1.0f, 5.0f, 0.0f, 0.0f));
	window->AddEntity(new Teapot(2.0f, 0.0f, 5.0f, 0.0f));
	window->AddEntity(new Teapot(4.0f, -5.0f, 0.0f, 0.0f));
	window->AddEntity(new Teapot(6.0f, 0.0f, -5.0f, 0.0f));
}

int main(int argc, char** argv)
{	
	auto settings = new WindowSettings();
	settings->DisplayMode = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE;
	settings->Height = 300;
	settings->Width = 300;
	settings->UpdateTime = 20;

	window = new RenderWindow(settings);
	// заполняем окно сущностями
	FillWithEntities();

	// инициализация библиотеки GLUT
	glutInit(&argc, argv);

	// инициализируем окно
	window->Init();
	// устанавливаем функцию отрисовки окна
	glutDisplayFunc(Display);
	// устанавливаем функцию, которая будет вызываться при изменении размеров окна
	glutReshapeFunc(Reshape);
	// устанавливаем функцию, которая будет вызвана через 0 мс
	glutTimerFunc(0, Simulation, 0);
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
