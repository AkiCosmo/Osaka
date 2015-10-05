#pragma once

#include "stdafx.h"

class CGameEvent
{
protected:
	int m_eventType;
	ALLEGRO_EVENT *m_al_event;
	bool m_finished;

public:
	CGameEvent(void);
	~CGameEvent(void);

	void setAlEvent(ALLEGRO_EVENT *al_event);
	ALLEGRO_EVENT* getAlEvent(void);

	void setEventType(int type);
	int getEventType(void);

	bool isFinished(void);
	void setFinished(void);

};

