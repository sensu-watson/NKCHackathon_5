

//--------------------------------------
// インクルード
#include "Word.h"

//--------------------------------------
// 変数宣言

//--------------------------------------
// 定数宣言
using namespace std;

// 文字列リスト
vector<WORDTYPE>  Word::List =
{
	WORDTYPE("名工大","ﾒｲｺｳﾀﾞｲ"),
	WORDTYPE("ハッカソン","ﾊﾂｶｿﾝ"),
//	WORDTYPE("HAL","HAL"),
};

//==============================================================================
//	Class
//		Info
//==============================================================================

//--------------------------------------
// FncName
//		Info
int Word::Init() {
	Question = List.at(rand() % Word::List.size());
	MorseDat.Init(Question.second);
	return 0;
}

int Word::Update() {

	return 0;
}

int Word::Draw() {

	return 0;
}

int Word::Release() {

	return 0;
}


// EOF