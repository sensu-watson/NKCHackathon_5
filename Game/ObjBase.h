
#ifndef _OBJBASE
#define _OBJBASE

//--------------------------------------
// �C���N���[�h
#include <bitset>

//--------------------------------------
// �ϐ��錾

//--------------------------------------
// �萔�錾

//==============================================================================
//	Class
//		Info
//==============================================================================

//--------------------------------------
// FncName
//		Info
class ObjBase {

private:
	static std::list<ObjBase*> ObjectList;

public:
	virtual int Init() = 0;
	virtual int Update() = 0;
	virtual int Draw() = 0;
	virtual int Release() = 0;

	ObjBase() {
		ObjectList.push_back(this);
		// Init();
	};

	~ObjBase() {
		ObjectList.remove(this);
	};

	static void DeleteAll() {
		for each (auto it in ObjectList)
		{
			it->Release();
			delete (it);
		}
	}

	static int AllUpdateAndDraw() {
		int ret = 0;
		for each (auto it in ObjectList)
		{
			ret = it->Update();
			if (ret != 0) { return ret; }
		}
		for each (auto it in ObjectList) {
			ret = it->Draw();
			if (ret != 0) { return ret; }
		}
		return 0;
	}

};



#endif _OBJBASE
// EOF