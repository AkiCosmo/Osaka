#pragma once

// STANDRD LIBS
#include <stdio.h>

// ALLEGRO LIBS
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// TEMPLATE LIBS
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

// GAME DECLARATIONS
#include "ResGraphics.h" // graphic resources
#include "Resource.h"	// graphics management [and sounds in the future]
#include "GObject.h"
#include "GObjMovable.h"
#include "Data.h"
#include "Tile.h"		// Map tiles
#include "GameEvent.h"	// to mamange events
#include "MainMap.h"	// Main map
#include "Screen.h"		// Game screen
#include "Game.h"		// central game control, startup

// RETRUN STATUS
#define RET_OKAY 0
#define RET_ERR -1

// MOUSE EVENTS
#define NUM_MOUSEBUTTONS 2
#define MOUSEBUTTON_DOWN	1
#define MOUSEBUTTON_UP		2
#define MOUSEBUTTONLEFT 1
#define MOUSEBUTTONRIGHT 2

// GRAPHIC IDs
#define RESG_MAPTILE		0
#define RESG_MAPTILEACTIVE	1
#define RESG_PLAYERICON		2

#define RESG_IMG_STYLE_STD	0

// FONT IDs
#define RESFONT_STD		0

