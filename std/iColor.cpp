#include "iColor.h"

iColor4f iColor4f::operator =(const iColor4b& c)
{
	iColor4f r;
	r.r = c.r / 255.f;	// c가 0~255이기 때문 255.f로 나누면 0~1값이 치환됨
	r.g = c.g / 255.f;
	r.b = c.b / 255.f;
	r.a = c.a / 255.f;

	return r;
}

iColor4b iColor4b::operator =(const iColor4f& c)
{
	iColor4b r;
	r.r = c.r / 0xFF;	// c가 0~1이기 때문 16진수로 나누면 0~255값이 치환됨
	r.g = c.g / 0xFF;
	r.b = c.b / 0xFF;
	r.a = c.a / 0xFF;

	return r;
}

iColor4f iColor4fMake(float r, float g, float b, float a)
{
	iColor4f c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;

	return c;
}

iColor4b iColor4bMake(uint8 r, uint8 g, uint8 b, uint8 a)
{
	iColor4b c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;

	return c;
}


