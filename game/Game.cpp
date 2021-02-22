#include "Game.h"

#include "Loading.h"

#include "Intro.h"
#include "Map.h"
#include "Proc.h"
#include "Menu.h"
#include "Ending.h"

void loadGame()
{
	loadIntro();
	gameState = gs_intro;
}

void freeGame()
{
	switch (gameState)
	{
	case gs_intro: freeIntro(); break;
	case gs_menu: freeMenu(); break;
	case gs_map: freeMap(); break;
	case gs_proc: freeProc(); break;
	case gs_ending: freeEnding(); break;

	}
}

void drawGame(float dt)
{
	switch (gameState)	
	{
	case gs_intro: drawIntro(dt); break;
	case gs_menu: drawMenu(dt); break;
	case gs_map: drawMap(dt); break;
	case gs_proc: drawProc(dt); break;
	case gs_ending: drawEnding(dt); break;

	}

	drawLoading(dt);
}
