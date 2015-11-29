
# include <Siv3D.hpp>
#include "ObjBase.h"
#include <Windows.h>

std::list<ObjBase*> ObjBase::ObjectList;
int Score;
int Time;


void Main()
{
	// const Font font(30);
	// font(L"ようこそ、Siv3D の世界へ！").draw();
	// Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });

	while (System::Update())
	{
		if (GetAsyncKeyState(VK_ESCAPE)) { break; }

		ObjBase::AllUpdateAndDraw();
	}
	ObjBase::DeleteAll();
}
