//==============================================================================
//	Ship.h
//		船を制御するクラス
//==============================================================================
#pragma once
#ifndef ___SHIP_HEADER___
#define ___SHIP_HEADER___

#include"ObjBase.h"

class Ship : public ObjBase {

public:
	int Init();
	int Update();
	int Draw();
	int Release();

}




#endif
// EOF