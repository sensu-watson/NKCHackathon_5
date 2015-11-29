#include <Siv3D.hpp>
#include "Light.h"
#include "ObjBase.h"

namespace Watson{
	int Light::Init(){
		Texture T(L"Image/lighth.png");

		if (!T){
			return -1;
		}

		texture = T;

		return 0;
	};

	int Light::Update(){
		return 0;
	};

	int Light::Draw(){
		if (Input::KeySpace.pressed)
		{
			texture.draw();
		}
		return 0;
	};

	int Light::Release(){
		delete (&texture);

		return 0;
	};
}