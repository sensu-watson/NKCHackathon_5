//==============================================================================
//	Word.h
//		タイピングする文字列データを制御
//==============================================================================
#pragma once
#ifndef ___WORD_HEADER___
#define ___WORD_HEADER___
#include"ObjBase.h"
#include <Windows.h>
#include <map>
#include <vector>
#include <bitset>
#include "Morse.hpp"

typedef std::pair<std::string, std::string> WORDTYPE;

class Word : public ObjBase {
public:
	static std::vector<WORDTYPE> List;

	WORDTYPE Question;
	Morse MorseDat;
	int Init();
	int Update();
	int Draw();
	int Release();
};




#endif
// EOF