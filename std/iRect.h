#pragma once

#include "iPoint.h"
#include "iSize.h"

struct iRect
{
	iPoint origin;
	iSize size;
};

#define iRectZero iSizeMake(0, 0, 0, 0)
#define iRectOne iSizeMake(1, 1, 1, 1)
iRect iRectMake(float x, float y, float width, float height);