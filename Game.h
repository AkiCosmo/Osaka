#pragma once

#include "stdafx.h"

class CGame
{

private:
	CScreen				*m_screen;
	CData				m_data;

	float				m_FPS;

	ALLEGRO_EVENT_QUEUE *m_eventQueue;
	ALLEGRO_TIMER		*m_eventTimer;

public:
	CGame(void);
	~CGame(void);

	int initGame(void);
	void gameLoop(void);
	void exitGame(void);


};

