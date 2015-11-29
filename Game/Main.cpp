#include <Siv3D.hpp>
#include <Windows.h>
#include "ObjBase.h"

std::list<ObjBase*> ObjBase::ObjectList;
static int Score;
static int Time;

namespace Watson{
	class Light : ObjBase{
	private:
		Texture texture;
	public:
		Light(){
			Init();
		}
		virtual int Init(){
			Texture T(L"Image/lighth.png");

			if (!T){
				return -1;
			}

			texture = T;

			return 0;
		};

		virtual int Update(){
			return 0;
		};

		virtual int Draw(){
			if (Input::KeySpace.pressed)
			{
				texture.draw();
			}
			return 0;
		};

		virtual int Release(){
			delete (&texture);

			return 0;
		};
	};
}


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
