#include <Siv3D.hpp>
#include "ObjBase.h"

namespace Watson{
	class Light : ObjBase{
	private:
		Texture texture;
	public:
		virtual int Init();
		virtual int Update();
		virtual int Draw();
		virtual int Release();
	};
}