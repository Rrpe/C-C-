﻿#pragma once

#define gs_intro	0
#define gs_menu		1
#define gs_map		2
#define gs_proc		3
#define gs_ending	4

#define gs_loading	oxff	// ox00, short - oxffff, int - oxffffff, unsigned - oxffffffff

extern int gameState;

typedef void (*MethodLoad)();
void setLoading(int gameState, MethodLoad free, MethodLoad load);
void drawLoading(float dt);

