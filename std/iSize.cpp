#include "iSize.h"
#include "iStd.h"

iSize iSizeMake(float w, float h)
{
	iSize p;
	p.width = w;
	p.height = h;
	return p;
}

iSize iSize::operator + (const iSize& p)
{
	iSize r;
	r.width = width + p.width;
	r.height = height + p.height;
	return r;	
}
iSize iSize::operator - (const iSize& p)
{
	iSize r;
	r.width = width - p.width;
	r.height = height - p.height;
	return r;
}
iSize iSize::operator * (const iSize & p)
{
	iSize r;
	r.width = width * p.width;
	r.height = height * p.height;
	return r;
}
iSize iSize::operator / (const iSize & p)
{
	iSize r;
	r.width = width / p.width;
	r.height = height / p.height;
	return r;
}

iSize& iSize:: operator += (const iSize& p)
{
	width += p.width;
	height += p.height;
	return *this;
}
iSize& iSize:: operator -= (const iSize& p)
{
	width -= p.width;
	height -= p.height;
	return *this;
}
iSize& iSize:: operator *= (const iSize & p)
{
	width *= p.width;
	height *= p.height;
	return *this;
}
iSize& iSize:: operator /= (const iSize & p)
{
	width /= p.width;
	height /= p.height;
	return *this;
}

iSize iSize::operator + (const float s)
{
	iSize r;
	r.width = width + s;
	r.height = height + s;
	return r;
}
iSize iSize::operator - (const float s)
{
	iSize r;
	r.width = width - s;
	r.height = height - s;
	return r;
}
iSize iSize::operator * (const float s)
{
	iSize r;
	r.width = width * s;
	r.height = height * s;
	return r;
}
iSize iSize::operator / (const float s)
{
	iSize r;
	r.width = width / s;
	r.height = height / s;
	return r;
}

iSize& iSize:: operator += (const float s)
{
	width += s;
	height += s;
	return *this;
}
iSize& iSize:: operator -= (const float s)
{
	width -= s;
	height -= s;
	return *this;
}
iSize& iSize:: operator *= (const float s)
{
	width *= s;
	height *= s;
	return *this;
}
iSize& iSize:: operator /= (const float s)
{
	width /= s;
	height /= s;
	return *this;
}