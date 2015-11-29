<<<<<<< HEAD
﻿# include <Siv3D.hpp>
# include "ObjBase.h"


class Light : ObjBase{

};

void Main()
{
	while (System::Update())
	{
		Println(L"test");
=======
﻿
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
>>>>>>> refs/remotes/0Delta/master
	}
	ObjBase::DeleteAll();
}
