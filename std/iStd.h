#pragma once

#include "iType.h"

#include "iPoint.h"
#include "iSize.h"
#include "iRect.h"
#include "iColor.h"
#include "iString.h"

#include "iFPS.h"
#include "iSort.h"
// add...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>

// macro
#define va_start_end(szText, szFormat) \
va_list args;	\
va_start(args, szFormat);	\
vsnprintf(szText, sizeof(szText), szFormat, args);	\
va_end(args) \

void appInitialize();
void runLotto();

#ifdef WIN32

int random();

#else

#endif // WIN32

float _cos(float degree);
float _sin(float degree);

float uint8ToFloat(uint8 c);
uint8 floatToUint8(float c);

void setRGBA(iColor4f c);
void setRGBA(iColor4b c);
void setRGBA(float r, float g, float b, float a);
void getRGBA(float& r, float& g, float& b, float& a);	// 리턴값은 인자값으로 받아야 하므로 & 사용

void setLineWidth(float width);		// 선굵기
float getLineWidth();

void clearRect();

//void drawLine(const iPoint& sp, const iPoint& ep);	// 속도빠름, 최적화
void drawLine(iPoint sp, iPoint ep);	// 구현 쉬움
void drawLine(float x0, float y0, float x1, float y1);

//void drawRect(const iRect& rt, float radius = 0.0f);	// 최적화
void drawRect(iRect rt, float radius = 0.0f);	// 사각형 선
void drawRect(float x, float y, float width, float height, float radius = 0.0f);

//void fillRect(const iRect& rt, float radius = 0.0f);	// 최적화
void fillRect(iRect rt, float radius = 0.0f);	// 색채운 사각
void fillRect(float x, float y, float width, float height, float radius = 0.0f);

// createImage("assets/intro/pop/menu%d.png", i);
// assets/intro/pop/menu1.png
// assets/intro/pop/menu2.png
// assets/intro/pop/menu3.png

typedef void igImage;
igImage* createImage(const char* szFormat, ...);		// 생성자, 받아올 type을 몰라서 *붙임
void freeImage(igImage* img);	// 파괴자
void drawImage(igImage* img, float x, float y, int anc,	// anchor - 가로정렬, 세로정렬 
	float ix, float iy, float iw, float ih,
	float rx, float ry,
	int xyz, float degree);					// degree 각도
void drawImage(igImage* img, float x, float y, int anc);

