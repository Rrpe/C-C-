// 메뉴창
#include "Menu.h"

#include "Intro.h"		// 크로스 컴파일 사용
#include <stdio.h>
//Intro* intro;

// 외부 변수(동일이름) a와 다른 변수선언
// Menu.cpp 파일 외에는 접근 x
//static int a;	//  폐쇄적 private이랑 비슷함

void loadMenu()
{
	a = 8;	// Intro.cpp a
	drawIntro(0.0f);

	int a = 2;	
	a = 5;	// Menu.cpp -> loadMenu() a // loadMenu()가 끝나면 사라짐
	drawIntro(0.0f);
}

static int a;		// 공동작업시 내코드가 중복선언 되었을 시 중복선언을 막기위해

void freeMenu()
{
	a = 2; // Menu.cpp a
}

#include "Loading.h"
void drawMenu(float dt)
{
	static int a = 3;	// 게임 제작시는 사용 금지, 테스트 시 사용하는 코드
	a++;	// static은 벗어나더라도 값을 유지하고있음
	printf("a = %d\n", a);

	III* i = new III();
	//MethodLoad m = i->iii;
	MethodLoad m = III::jjj;

	i->iii();
	i->jjj();	// VS에서는 문제가 안됨 / 추천하지않는 방식

	//III::iii();
	III::jjj();
}
