#include "iFPS.h"
#include "iWindow.h"

iFPS* iFPS::instance()
{
	static iFPS* ins = new iFPS();
	return ins;
}

iFPS::iFPS()
{
	now = GetTickCount64();	// 현재시간

#ifdef DISPLAY_FPS
	frame = 0;
	tickDt = 0.0f;		// 모은 시간
	count = 0;	// 실행 횟수
#endif // DISPLAY_FPS
}

iFPS::~iFPS()
{
}

float iFPS::update()
{
#ifdef DISPLAY_FPS
	fps(true);
#endif
	unsigned long n = GetTickCount64();	// 흐른 시간
	float dt = (n - now) / 1000.f;	// 1000당 1초
	now = n;
	return dt;
}

void iFPS::setSlowTime(float duration)
{
}

#ifdef DISPLAY_FPS
int iFPS::fps(bool apply)
{
	if (apply == false)
	{
		return frame;
	}

	unsigned long n = GetTickCount64();	// 흐른 시간
	float dt = (n - now) / 1000.f;	// dt = 마지막 시간 - 시작 시간 // 1000당 1초	
	
	tickDt += dt;	// 0 += 0.001 * 300
	count++;		// ++ 1 * 300
	if (tickDt > 0.3f)
	{
		frame = count / tickDt;		// 1000 = 300 / 0.3
	
		tickDt = 0.0f;
		count = 0;
	}

	return frame;
}
#endif // DISPLAY_FPS
