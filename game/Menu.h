#pragma once

// #include "Intro.h"		// Cross Compile

#if 0
// Intro.h의 Intro class를 사용하고 싶음
class Intro;	// 어딘가에 정의함 - 타입만 정의함
extern Intro* intro;	// extern -> 정의

class Menu
{
public:
	Menu() {}
	virtual ~Menu() {}
	void update() {}
};
#endif

static int menuA = 3;

void loadMenu();
void freeMenu();
void drawMenu(float dt);