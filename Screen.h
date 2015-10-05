#pragma once

#include "stdafx.h"

//extern CGameEvent;

//extern class CGame;

class CScreen
{

private:
	ALLEGRO_DISPLAY *m_display;
	CMainMap m_mainMap;
//	CData *m_gameData;

public:
	CScreen(void);
	~CScreen(void);

	int initDisplay(void);
	int initScreen(CData *gameData);
	void clearScreen(void);

	CGameEvent* processEvent(CGameEvent* gameEvent);

	ALLEGRO_DISPLAY *getDisplay(void);
	void draw(CData *gameData);

};

