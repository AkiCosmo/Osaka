#include "GameEvent.h"

#include "stdafx.h"

CGameEvent::CGameEvent(void)
{
	m_eventType = 0;
	m_al_event = NULL;
	m_finished = false;			// if true, event is finally processed, no further doing
}


CGameEvent::~CGameEvent(void)
{
}

void CGameEvent::setAlEvent(ALLEGRO_EVENT *al_event)
{
	m_al_event = al_event;
}

ALLEGRO_EVENT* CGameEvent::getAlEvent(void) {
	return m_al_event;
}

bool CGameEvent::isFinished(void) {
	return m_finished;
}

void CGameEvent::setFinished(void) {
	m_finished = true;
}

void CGameEvent::setEventType(int type) {
	m_eventType = type;
}

int CGameEvent::getEventType(void) {
	return m_eventType;
}
