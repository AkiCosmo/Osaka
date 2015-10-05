
#include "stdafx.h"
//#define NUM_MOUSEBUTTONS  2

//const float FPS = 60;

//ALLEGRO_EVENT_QUEUE *event_queue = NULL;
//ALLEGRO_TIMER *timer = NULL;

//CScreen screen;


//bool redraw = true;
//bool mousebuttons[NUM_MOUSEBUTTONS] = {false};

int main(int argc, char **argv)
{
	CGame game;

// init Allegro
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
//	if (!al_init_primitives_addon()) {
//		fprintf(stderr, "failed to initialize primitives!\n");
//		return -1;
//	}
//
	al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon

	// initialize Keyboard
	al_install_keyboard();
	// initialize mouse
	al_install_mouse();

	if (!al_init_image_addon()) {
		fprintf(stderr, "failed to initialize image addon!\n");
		return -1;
	}

	// init game class
	if (RET_ERR == game.initGame()) {
		return RET_ERR;
	}

	game.gameLoop();

	game.exitGame();

/*	
	screen.initScreen();

 	timer = al_create_timer(1.0 / FPS);
	if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(screen.getDisplay()));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

	while(true)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
 
		if(ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			fprintf(stderr, "Mouse button pressed\n");
			if (ev.mouse.button-1 < NUM_MOUSEBUTTONS) {
				mousebuttons[ev.mouse.button-1] = true;
			}
		}

		if(redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			screen.draw();
      }
	}


	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	screen.clearScreen();
	*/
	return 0;
}

