#pragma once

#include <stdio.h>
#include <string.h>

struct iPoint
{
	float x, y;

	//iPoint();
	//iPoint(const iPoint& p);
	//iPoint(float x, float y);
	//virtual ~iPoint();

	// operator = -> 함수이름
	//iPoint& operator = (const iPoint& p);

	// 나 자신을 계산할때 &
	iPoint operator + (const iPoint& p);
	iPoint operator - (const iPoint& p);
	iPoint operator * (const iPoint& p);
	iPoint operator / (const iPoint& p);

	iPoint& operator += (const iPoint& p);
	iPoint& operator -= (const iPoint& p);
	iPoint& operator *= (const iPoint& p);
	iPoint& operator /= (const iPoint& p);

	iPoint operator + (const float s);
	iPoint operator - (const float s);
	iPoint operator * (const float s);
	iPoint operator / (const float s);

	iPoint& operator += (const float s);
	iPoint& operator -= (const float s);
	iPoint& operator *= (const float s);
	iPoint& operator /= (const float s);
};

#define iPointZero iPointMake(0, 0)
#define iPointOne iPointMake(1, 1)
iPoint iPointMake(float x, float y);
iPoint iPointRotate(iPoint p, iPoint t, float degree);