#include "Loading.h"

int gameState = gs_intro, toGameState;
MethodLoad methodFree, methodLoad;
float loadingDt;
#define _loadingDt 0.5f

void setLoading(int gameState, MethodLoad free, MethodLoad load)
{
	toGameState = gameState;
	if (loadingDt)
		return;

	toGameState = gameState;
	methodFree = free;
	methodLoad = load;
	loadingDt = 0.000001f;
}

void drawLoading(float dt)
{
	if (loadingDt < _loadingDt)
	{
		// 점점 어두워진다.
	}
	else if (loadingDt == _loadingDt)
	{
		methodFree();
		MethodLoad();
		gameState = toGameState;
	}
	else if (loadingDt < _loadingDt * 2)
	{
		// 점점 밝아진다
	}
}

