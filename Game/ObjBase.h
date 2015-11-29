
#pragma once
//--------------------------------------
// インクルード
#include <list>

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
class ObjBase {
private:

	static std::list<ObjBase*> ObjectList;

	enum STATE :short {
		NOTINIT,
		READY,
		DELETE,
		END,
	}State;
	void operator-=(STATE Var) {
		this->State = Var;
	}

public:
	virtual int Init() = 0;
	virtual int Update() = 0;
	virtual int Draw() = 0;
	virtual int Release() = 0;

	ObjBase() {
		State = STATE::NOTINIT;
		ObjectList.push_back(this);
	};

	~ObjBase() {
		ObjectList.remove(this);
	};

	static void DeleteAll() {
		for each (ObjBase* it in ObjectList)
		{
			if ((*it)() == STATE::READY || (*it)() == STATE::DELETE) {
				it->Release();
			}
		}
	}

	static int AllUpdateAndDraw() {
		int ret = 0;
		for each (auto it in ObjectList)
		{
			if ((*it)() == STATE::NOTINIT) {
				if (it->Init() >= 0) {
					it -= STATE::READY;
				}
			}
			else if ((*it)() == STATE::DELETE) {
				it->Release();
				it -= STATE::END;
			}
		}
		for each (auto it in ObjectList)
		{
			if ((*it)() != STATE::READY) { continue; }
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