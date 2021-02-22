#pragma once

// #define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#include "iWindow.h"
#include "iStd.h"



// a/A left
// d/D right
// w/W up
// s/S down
extern int keys;	   // 0000 0000
#define keysA		1  // 0000 0001
#define keysD		2  // 0000 0010
#define keysW		4  // 0000 0100
#define keysS		8  // 0000 1000
#define keysSpace	16 // 0001 0000

/*
	glut -> openGL 입문 공부 정도
	glfw
*/

//	더블 버퍼링
//	개발 사이즈 (후면버퍼, 백버퍼)
//	해상도 가용화면 (viewport) == 실제 사이즈(전면버퍼, 프론티어버퍼)

// 개발 사이즈 100x50
// 단말 사이즈 200x120		200x100(높이 위 아래 +- 10 암전 처리)

// devSize (100, 50)
// viewport (0, 10, 200, 100) (vertical, horzontal, width, height)


