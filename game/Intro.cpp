#include "Intro.h"

#include "Menu.h"	// 크로스 컴파일 사용 -> 클래스를 서로 참조하려고 할때
#include <stdio.h>
//Menu* menu;

int a;

void loadIntro()
{
	a = 0;
}

void freeIntro()
{
}

void drawIntro(float dt)
{
	printf("Intro.cpp a = %d\n", a);
}
