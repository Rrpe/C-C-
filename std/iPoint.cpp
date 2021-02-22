#include "iPoint.h"
#include "iStd.h"

//iPoint::iPoint()
//{
//	printf("생성자()~\n");
//}
//
//iPoint::iPoint(const iPoint& p)
//{
//	printf("iPoint 생성자2(%f, %f)\n", x, y);
//	this->x = p.x;
//	this->y = p.y;
//}
//
//iPoint::iPoint(float x, float y)
//{
//	printf("iPoint 생성자(%f ,%f)\n", x, y);
//	this->x = x;
//	this->y = y;
//}
//
//iPoint::~iPoint()
//{
//	printf("파괴자(%f, %f)~\n", x, y);
//}
//void iPoint::insert(const iPoint& p)
//{
//	x = p.x;
//	y = p.y;
//}
//
//iPoint& iPoint::operator = (const iPoint& p)
//{
//	x = p.x;
//	y = p.y;
//	return *this;
//}

iPoint iPointMake(float x, float y)
{
	iPoint p;
	p.x = x;
	p.y = y;
	return p;
}

iPoint iPointRotate(iPoint p, iPoint t, float degree)
{


	return p;
}

iPoint iPoint::operator + (const iPoint& p)
{
	iPoint r;
	r.x = x + p.x;
	r.y = y + p.y;
	return r;	
}
iPoint iPoint::operator - (const iPoint& p)
{
	iPoint r;
	r.x = x - p.x;
	r.y = y - p.y;
	return r;
}
iPoint iPoint::operator * (const iPoint & p)
{
	iPoint r;
	r.x = x * p.x;
	r.y = y * p.y;
	return r;
}
iPoint iPoint::operator / (const iPoint & p)
{
	iPoint r;
	r.x = x / p.x;
	r.y = y / p.y;
	return r;
}

iPoint& iPoint:: operator += (const iPoint& p)
{
	x += p.x;
	y += p.y;
	return *this;
}
iPoint& iPoint:: operator -= (const iPoint& p)
{
	x -= p.x;
	y -= p.y;
	return *this;
}
iPoint& iPoint:: operator *= (const iPoint & p)
{
	x *= p.x;
	y *= p.y;
	return *this;
}
iPoint& iPoint:: operator /= (const iPoint & p)
{
	x /= p.x;
	y /= p.y;
	return *this;
}

iPoint iPoint::operator + (const float s)
{
	iPoint r;
	r.x = x + s;
	r.y = y + s;
	return r;
}
iPoint iPoint::operator - (const float s)
{
	iPoint r;
	r.x = x - s;
	r.y = y - s;
	return r;
}
iPoint iPoint::operator * (const float s)
{
	iPoint r;
	r.x = x * s;
	r.y = y * s;
	return r;
}
iPoint iPoint::operator / (const float s)
{
	iPoint r;
	r.x = x / s;
	r.y = y / s;
	return r;
}

iPoint& iPoint:: operator += (const float s)
{
	x += s;
	y += s;
	return *this;
}
iPoint& iPoint:: operator -= (const float s)
{
	x -= s;
	y -= s;
	return *this;
}
iPoint& iPoint:: operator *= (const float s)
{
	x *= s;
	y *= s;
	return *this;
}
iPoint& iPoint:: operator /= (const float s)
{
	x /= s;
	y /= s;
	return *this;
}