#include <Siv3D.hpp>
#include <Windows.h>
#include "ObjBase.h"
#include "Light.h"

std::list<ObjBase*> ObjBase::ObjectList;
static int Score;
static int Time;



void Main()
{
	// const Font font(30);
	// font(L"ようこそ、Siv3D の世界へ！").draw();
	// Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });

	Watson::Light *light = new Watson::Light();

	while (System::Update())
	{
		if (GetAsyncKeyState(VK_ESCAPE)) { break; }

		ObjBase::AllUpdateAndDraw();
	}
	ObjBase::DeleteAll();
}
