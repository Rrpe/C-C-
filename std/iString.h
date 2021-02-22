#pragma once
#include <stdio.h>
#include <string.h>

class iString
{
public:
	iString();
	iString(const char* szFormat, ...);
	iString(const iString& s);
	virtual ~iString();

	iString& operator =(const char* str);
	iString& operator =(const iString& str);

	const char* operator +(const char* s);
	const char* operator +(const iString& s);

	iString& operator +=(const char* s);
	iString& operator +=(const iString& s);

	//iString& operator = (const iString& s);
	//iString& operator + (const iString& s);

	// iString s;
	// s.set(...);
	void set(const char* szFormat, ...);
	void add(const char* szFormat, ...);


	static char** getStringLine(const char* str, int& lineNum, int d='\n');
	static void freeStringLine(char** line, int lineNum);

#if 1
	static void MEMCPY(void* dst, const void* src, int size);	// 메모리 복사
	static void MEMSET(void* dst, unsigned char v, int size);	// 메모리 초기화

	static void STRCPY(char* dst, const char* src);		// 문자열 복사 dst에 src복사
	static void STRCAT(char* dst, const char* src);		// 문자열 연결
	static int STRCMP(const char* s0, const char* s1);	// 문자열 비교(value 비교)
#endif

public:
	char* str;	// 16자
	int strLength;
};
