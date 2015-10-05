#include "stdafx.h"
//#include "Game.h"

CGame::CGame(void)
{
	m_eventQueue = NULL;
	m_eventTimer = NULL;
	m_screen = NULL;
		
	m_FPS = 60;
}

CGame::~CGame(void)
{
}

int CGame::initGame(void)
{
	int iRet = RET_OKAY;

	m_screen = new CScreen();
	if (!m_screen) {
		fprintf(stderr, "Error: CGAME::initGame - Error while creating screen object");
		return RET_ERR;
	}

	iRet = m_screen->initDisplay();
	if (RET_ERR == iRet) {
		fprintf(stderr, "Error: CGAME::initGame - Error while initializing screen display");
		return RET_ERR;
	}

	m_data.initData();

	m_screen->initScreen(&m_data);

 	m_eventTimer = al_create_timer(1.0 / m_FPS);
	if(!m_eventTimer) {
		fprintf(stderr, "failed to create timer!\n");
		return RET_ERR;
	}

	m_eventQueue = al_create_event_queue();
	if(!m_eventQueue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_timer(m_eventTimer);
		return RET_ERR;
	}

	al_register_event_source(m_eventQueue, al_get_display_event_source(m_screen->getDisplay()));
	al_register_event_source(m_eventQueue, al_get_timer_event_source(m_eventTimer));
	al_register_event_source(m_eventQueue, al_get_mouse_event_source());
	al_register_event_source(m_eventQueue, al_get_keyboard_event_source());

    al_start_timer(m_eventTimer);

	return RET_OKAY;
}

void CGame::exitGame(void) {

	if (m_eventTimer)
		al_destroy_timer(m_eventTimer);

	if (m_eventQueue)
		al_destroy_event_queue(m_eventQueue);

	m_data.clearData();

	if (m_screen)
		m_screen->clearScreen();

}

void CGame::gameLoop(void) {

	bool needRedraw = true;
	bool mousebuttons[NUM_MOUSEBUTTONS] = {false};

	while(true)
	{
		ALLEGRO_EVENT alEvent;
		CGameEvent gameEvent;
		al_wait_for_event(m_eventQueue, &alEvent);
 
		if(alEvent.type == ALLEGRO_EVENT_TIMER) {
			needRedraw = true;
		}
		else if(alEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (alEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (alEvent.mouse.button <= NUM_MOUSEBUTTONS) {
				mousebuttons[alEvent.mouse.button-1] = true;
				fprintf(stderr, "\nMouse button 1 or 2 pressed");

				gameEvent.setAlEvent(&alEvent);
				gameEvent.setEventType(MOUSEBUTTON_DOWN);
				m_screen->processEvent(&gameEvent);
			}
		}

		if(needRedraw && al_is_event_queue_empty(m_eventQueue)) {
			needRedraw = false;
			m_screen->draw(&m_data);
      }
	}

}