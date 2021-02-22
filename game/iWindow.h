#include <windows.h>

#include <gdiplus.h>	// gdiplus 사용하려면 #define을 해제해야함
#pragma comment(lib, "gdiplus.lib")
using namespace Gdiplus;

#include "../resource.h"

#if _DEBUG
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#define xprintf printf
#else
#define xprintf (void*)
#endif

#if 0
// imme or gdiplus를 사용할 경우, WIN32_LEAN_AND_MEAN 정의하지 않는다
GDIPVER = 0x0110	// 최소 1.1 버전 이상을 사용
_CRT_SECURE_NO_WARNINGS		// 예전 함수 사용방법
#endif

extern Graphics* graphics;     // 동적할당

ULONG_PTR startApp(HDC hdc);
void endApp(ULONG_PTR token);
void drawApp();		// 뿌리는 영역

wchar_t* utf8_to_utf16(const char* szFormat, ...);
char* utf16_to_utf8(const wchar_t* str);

