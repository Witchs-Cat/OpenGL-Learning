// DemoGlut.Camera.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Windows/RenderWindow.h"
#include "Entities/Primitives/Teapot.h"
#include "Entities/Primitives/Grid.h"

RenderWindow* window;

void Display()
{	window->Display();}

void Reshape(int w, int h)
{	window->Resize(w, h);}

void FillWithEntities()
{
	shared_ptr<BaseMaterial> material1 = BaseMaterial::LoadFromYaml("Assets/Materials/Material1.yaml");
	shared_ptr<BaseMaterial> material2 = BaseMaterial::LoadFromYaml("Assets/Materials/Material2.yaml");
	shared_ptr<BaseMaterial> material3 = BaseMaterial::LoadFromYaml("Assets/Materials/Material3.yaml");
	shared_ptr<BaseMaterial> material4 = BaseMaterial::LoadFromYaml("Assets/Materials/Material4.yaml");

	shared_ptr<BaseCamera> camera = shared_ptr<BaseCamera>(new MovingCamera(30, 1, 1));
	camera->SetUpVector(0, 1, 0);
	window->SetCamera(camera);

	shared_ptr<BaseLight> ligth = shared_ptr<BaseLight>(new BaseLight(20,15,20));
	ligth->SetDiffuse(vec4(0.5, 0.5, 0.5, 1));
	ligth->SetAmbient(vec4(0.1, 0.1, 0.1, 1));
	ligth->SetSpecular(vec4(0.1, 0.1, 0.1, 1));
	window->SetLigth(ligth);

	shared_ptr<Teapot> entity = shared_ptr<Teapot>(new Teapot(1.0f, true));
	entity->SetColor(0.0, 1.0, 1.0);
	entity->SetMaterial(material1);
	entity->SetPosition(5.0f, 0.0f, 0.0f);
	entity->RotateXZ(180);
	window->AddEntity(entity);

	entity = shared_ptr<Teapot>(new Teapot(2.0f, true));
	entity->SetColor(1.0, 0.0, 0.0);
	entity->SetMaterial(material2);
	entity->SetPosition(0.0f, 0.0f, 5.0f);
	entity->RotateXZ(270);
	window->AddEntity(entity);

	entity = shared_ptr<Teapot>(new Teapot(1.0f, true));
	entity->SetColor(1.0, 0.0, 1.0);
	entity->SetMaterial(material3);
	entity->SetPosition(-5.0f, 0.0f, 0.0f);
	entity->RotateXZ(0);
	window->AddEntity(entity);

	entity = shared_ptr<Teapot>(new Teapot(1.0f, true));
	entity->SetColor(0.0, 0.0, 1.0);
	entity->SetMaterial(material4);
	entity->SetPosition(0.0f, 0.0f, -5.0f);
	entity->RotateXZ(90);
	window->AddEntity(entity);

	shared_ptr<Entity> entity2 = shared_ptr<Entity>(new Grid());
	entity->SetMaterial(material4);
	window->AddEntity(entity2);
}

int main(int argc, char** argv)
{	
	ShowWindow(GetConsoleWindow(), SW_HIDE);
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
	// устанавливаем функцию, которая будет вызваться по кд
	glutIdleFunc(glutPostRedisplay);
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
