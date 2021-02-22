#pragma once
//#ifndef _Intro_h
//#define _Intro_h
// #include "Menu.h"		// Cross Compile

#if 0
class Intro
{
public:
	Intro() {}
	virtual ~Intro() {}
	void update(float dt) {}
};

class Menu;		// class type 정의
extern Menu* menu;
#endif

extern int a;

class III
{
public:
	III() {}
	virtual ~III() {}

	void iii() {}			// 멤버 함수 - 객체가 존재하면서 접근이 가능한 함수
	
	static void jjj() {}	// 객체가 존재하지 않아도, 독립적으로 구성된 함수 
							// III라는 네임스페이스를 가지고 있는 전역함수
	static int nnn;		// 존재하지만 쓰지않는 방식
};

void loadIntro();
void freeIntro();
void drawIntro(float dt);		// time animation (과거에는 flame animation)

//#endif // !_Intor_h