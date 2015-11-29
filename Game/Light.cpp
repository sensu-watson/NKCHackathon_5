#include <Siv3D.hpp>
#include "ObjBase.h"

namespace Watson{
	class Light : ObjBase{
	private:
		Texture texture;
	public:
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