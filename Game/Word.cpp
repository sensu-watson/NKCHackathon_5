

//--------------------------------------
// �C���N���[�h
#include "Word.h"

//--------------------------------------
// �ϐ��錾

//--------------------------------------
// �萔�錾
using namespace std;

// �����񃊃X�g
vector<WORDTYPE>  Word::List =
{
	WORDTYPE("���H��","Ҳ���޲"),
	WORDTYPE("�n�b�J�\��","�¶��"),
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