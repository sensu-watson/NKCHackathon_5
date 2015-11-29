
#pragma once
//--------------------------------------
// インクルード
#include <list>

#undef DELETE

//--------------------------------------
// 変数宣言

//--------------------------------------
// 定数宣言

//==============================================================================
//	Class
//		Info
//==============================================================================

//--------------------------------------
// FncName
//		Info
static enum STATE :short {
	OBJBASE_NOTINIT,
	OBJBASE_READY,
	OBJBASE_DELETE,
	OBJBASE_END,
};


class ObjBase {
private:

	static std::list<ObjBase*> ObjectList;
	STATE State;

	void SetState(STATE Var) {
		this->State = Var;
	}

public:
	virtual int Init() = 0;
	virtual int Update() = 0;
	virtual int Draw() = 0;
	virtual int Release() = 0;

	ObjBase() {
		State = STATE::OBJBASE_NOTINIT;
		ObjectList.push_back(this);
	};

	~ObjBase() {
		ObjectList.remove(this);
	};

	static void DeleteAll() {
		for each (ObjBase* it in ObjectList)
		{
			if ((*it)() == STATE::OBJBASE_READY || (*it)() == STATE::OBJBASE_DELETE) {
				it->Release();
			}
		}
	}

	static int AllUpdateAndDraw() {
		int ret = 0;
		for each (auto it in ObjectList)
		{
			if ((*it)() == STATE::OBJBASE_NOTINIT) {
				if (it->Init() >= 0) {
					it->SetState(STATE::OBJBASE_READY);
				}
			}
			else if ((*it)() == STATE::OBJBASE_DELETE) {
				it->Release();
				it->SetState(STATE::OBJBASE_END);
			}
		}
		for each (auto it in ObjectList)
		{
			if ((*it)() != STATE::OBJBASE_READY) { continue; }
			ret = it->Update();
			if (ret != 0) { return ret; }
		}
		for each (auto it in ObjectList) {
			ret = it->Draw();
			if (ret != 0) { return ret; }
		}
		return 0;
	}

	static void Clean() {
		for each (auto it in ObjectList)
			ObjectList.remove(it);
	}

	STATE operator()() {
		return this->State;
	}
};







// EOF