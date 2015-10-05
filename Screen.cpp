#include "stdafx.h"
#include "Screen.h"


CScreen::CScreen(void)
{
	m_display = NULL;
//	m_gameData = NULL;
}


CScreen::~CScreen(void)
{
}

//	***** initScreen ********************
// initialising the screen and all members - should be called once at game start
//
// gameData -> pointer to central game data instance
// **************************************

int CScreen::initScreen(CData *gameData) {

	int iRet = RET_OKAY;

//	m_gameData = gameData;


	iRet = m_mainMap.initMap(m_display, gameData);

	return iRet;
}

int CScreen::initDisplay(void) {

	int iRet = RET_OKAY;

	m_display = al_create_display(1000, 700);
	
	if(!m_display) {
		fprintf(stderr, "failed to create display!\n");
		iRet = RET_ERR;
	}

	return iRet;
}

//	***** clearScreen ********************
// clear all local objects - should be called at game exit
//
// gameData -> pointer to central game data instance
// ***************************************
void CScreen::clearScreen(void) {

	m_mainMap.clearMap();

	if (m_display) {
		al_destroy_display(m_display);
	}

}

ALLEGRO_DISPLAY* CScreen::getDisplay(void) {
	return m_display;
}

void CScreen::draw(CData *gameData) {

    //al_set_target_bitmap(m_display);
	//al_set_target_backbuffer(m_display);

	al_set_target_bitmap(al_get_backbuffer(m_display));

	al_clear_to_color(al_map_rgb(0,0,0));

	m_mainMap.draw(m_display, gameData);

	al_flip_display();
}

CGameEvent* CScreen::processEvent(CGameEvent *gameEvent) {

	switch (gameEvent->getEventType()) {
	case MOUSEBUTTON_DOWN:
		// mousebutton pressed
		// curerntly we only have a map on the screen, so the map should hande it
		m_mainMap.processEvent(gameEvent);
		break;
	}
	return NULL;
}