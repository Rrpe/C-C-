#include "iStd.h"
#include "iWindow.h"

void appInitialize()
{
	srand((unsigned long long)time(NULL));
}

int random()
{
	return rand();
}

float _cos(float degree)
{
	//return cos(180 / M_PI * degree);
	//return cos(M_PI / 180 * degree);

	return cos(degree / 180 * M_PI);
}
float _sin(float degree)
{
	return sin(degree / 180 * M_PI);
}

static float _r = 1.0f, _g = 1.0f, _b = 1.0f, _a = 1.0f;

// _ -> private
float uint8ToFloat(uint8 c)
{
	return c / 255.0f;
}
uint8 floatToUint8(float c)
{
	return (uint8)(c * 0xFF);
}

void setRGBA(iColor4f c)
{
	_r = c.r; _g = c.g;	_b = c.b; _a = c.a;
}

void setRGBA(iColor4b c)
{
	_r = uint8ToFloat(c.r);	_g = uint8ToFloat(c.g);	_b = uint8ToFloat(c.b);	_a = uint8ToFloat(c.a);
}

void setRGBA(float r, float g, float b, float a)
{
	_r = r;	_g = g;	_b = b;	_a = a;
}

void getRGBA(float& r, float& g, float& b, float& a)
{
	r = _r;	g = _g;	b = _b;	a = _a;
}

static float _lineWidth = 1.0f;
void setLineWidth(float width)
{
	_lineWidth = width;
}
float getLineWidth()
{
	return _lineWidth;
}

void clearRect()
{
	graphics->Clear(Color(  floatToUint8(_a),
							floatToUint8(_r),
							floatToUint8(_g),
							floatToUint8(_b)));
}

void drawLine(iPoint sp, iPoint ep)
{
	Pen      pen(Color(floatToUint8(_a), 
		floatToUint8(_r), 
		floatToUint8(_g), 
		floatToUint8(_b)));
	pen.SetWidth(_lineWidth);
	graphics->DrawLine(&pen, sp.x, sp.y, ep.x, ep.y);
}
void drawLine(float x0, float y0, float x1, float y1)
{
	Pen      pen(Color(floatToUint8(_a),
		floatToUint8(_r),
		floatToUint8(_g),
		floatToUint8(_b)));
	pen.SetWidth(_lineWidth);
	graphics->DrawLine(&pen, x0, y0, x1, y1);
}

void drawRect(iRect rt, float radius)
{
	drawRect(rt.origin.x, rt.origin.y, rt.size.width, rt.size.height);
	//Pen pen(Color(_a, _r, _g, _b));
	//GraphicsPath path;
	//graphics->DrawPath(&pen, &path);
}

void drawRect(float x, float y, float width, float height, float radius)
{
	Pen      pen(Color(floatToUint8(_a),
		floatToUint8(_r),
		floatToUint8(_g),
		floatToUint8(_b)));
	pen.SetWidth(_lineWidth);

	GraphicsPath path;
	path.AddLine(x + radius, y, x + width - (radius * 2), y);
	path.AddArc(x + width - (radius * 2), y, radius * 2, radius * 2, 270, 90);
	path.AddLine(x + width, y + radius, x + width, y + height - (radius * 2));
	path.AddArc(x + width - (radius * 2), y + height - (radius * 2), radius * 2, radius * 2, 0, 90);
	path.AddLine(x + width - (radius * 2), y + height, x + radius, y + height);
	path.AddArc(x, y + height - (radius * 2), radius * 2, radius * 2, 90, 90);
	path.AddLine(x, y + height - (radius * 2), x, y + radius);
	path.AddArc(x, y, radius * 2, radius * 2, 180, 90);
	//path.AddLine(x, y, x + width, y);
	//path.AddLine(x + width, y, x + width, y + height);
	//path.AddLine(x, y + height, x + width, y + height);
	//path.AddLine(x, y, x, y + height);

	graphics->DrawPath(&pen, &path);
}

void fillRect(iRect rt, float radius)
{
}

void fillRect(float x, float y, float width, float height, float radius)
{
	SolidBrush      brush(Color(floatToUint8(_a),
		floatToUint8(_r),
		floatToUint8(_g),
		floatToUint8(_b)));

	GraphicsPath path;
	
	path.AddLine(x + radius, y, x + width - (radius * 2), y);
	path.AddArc(x + width - (radius * 2), y, radius * 2, radius * 2, 270, 90);
	path.AddLine(x + width, y + radius, x + width, y + height - (radius * 2));
	path.AddArc(x + width - (radius * 2), y + height - (radius * 2), radius * 2, radius * 2, 0, 90);
	path.AddLine(x + width - (radius * 2), y + height, x + radius, y+ height);
	path.AddArc(x, y + height - (radius * 2), radius * 2, radius * 2, 90, 90);
	path.AddLine(x, y + height - (radius * 2), x, y + radius);
	path.AddArc(x, y, radius * 2, radius * 2, 180, 90);
	graphics->FillPath(&brush, &path);
}

igImage* createImage(const char* szFormat, ...)
{
	char szText[1024];
	va_start_end(szText, szFormat);

	wchar_t* ws = utf8_to_utf16(szText);
	Image* img = Image::FromFile(ws, false);
	delete ws;

	return img;
}

void freeImage(igImage* img)
{
	delete img;
}

void drawImage(igImage* _img, float x, float y, int anc, 
	float ix, float iy, float iw, float ih, 
	float rx, float ry, 
	int xyz, float degree)
{
	Image* img = (Image*)_img;
	float w = img->GetWidth() * rx, h = img->GetHeight() * ry;

	switch (anc) {
	case TOP | LEFT:										break;
	case TOP | RIGHT:			x -= w;						break;
	case TOP | HORIZONTAL:		x -= w / 2;					break;

	case BOTTOM | LEFT:						y -= h;			break;
	case BOTTOM | RIGHT:		x -= w;		y -= h;			break;
	case BOTTOM | HORIZONTAL:	x -= w / 2;	y -= h;			break;

	case VERTICAL | LEFT:					y -= h / 2;		break;
	case VERTICAL | RIGHT:		x -= w;		y -= h / 2;		break;
	case VERTICAL | HORIZONTAL: x -= w / 2;	y -= h / 2;		break;
	}

#if 0
	RectF dstRect = { x, y, w, h };		// 뿌릴려고 하는 영역
	RectF srcRect = { ix, iy, iw, ih };	// 그릴려고 하는 영역
	graphics->DrawImage(img, dstRect, srcRect, UnitPixel);
#else
	iPoint dstPoint[3] = {
		{x, y}, {x + w, y},	{x , y + h}
	};
	iPoint t = iPointMake(x + w / 2, y + h / 2);
	if (xyz == 0) // x축
	{
		dstPoint[0].y =
		dstPoint[1].y = y + h / 2 - h / 2 * _cos(degree);
		dstPoint[2].y = y + h / 2 + h / 2 * _cos(degree);
	}
	else if (xyz == 1)	// y축
	{
		dstPoint[0].x =
		dstPoint[1].x = x + w / 2 - w / 2 * _cos(degree);
		dstPoint[2].x = x + w / 2 + w / 2 * _cos(degree);
	}
	else // if (xyz == 2)	// z축
	{
		for (int i = 0; i < 3; i++)
			dstPoint[i] = iPointRotate(dstPoint[i], t, degree);
	}

	ColorMatrix matrix = {
		1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,   _a, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f, 1.0f
	};
	ImageAttributes attr;
	attr.SetColorMatrix(&matrix, 
		ColorMatrixFlagsDefault, ColorAdjustTypeBitmap);

	graphics->DrawImage(img, (PointF*)dstPoint, 3, ix, iy ,iw ,ih, UnitPixel, &attr);
#endif
}

void drawImage(igImage* _img, float x, float y, int anc)
{
	Image* img = (Image*)_img;

	drawImage(img, x, y, anc,
		0, 0, img->GetWidth(), img->GetHeight(),
		1.0f, 1.0f,
		2, 0);
}
