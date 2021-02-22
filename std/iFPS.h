#pragma once

#define DISPLAY_FPS

class iFPS
{
public:
	static iFPS* instance();	// 반환하는 함수, 싱글턴 패턴
private:
	iFPS();		// 싱글턴 패턴 -> 생성자를 호출할려면 instance를 사용해야함
public:
	virtual ~iFPS();

	float update();		// float -> 0.n초, 

	void setSlowTime(float duration);

#ifdef DISPLAY_FPS
	int fps(bool apply = false);	// 초당 프레임 구하기
#endif // DISPLAY_FPS

public:
	unsigned long now;
#ifdef DISPLAY_FPS
	int frame;
	float tickDt;
	int count;
#endif // DISPLAY_FPS
};