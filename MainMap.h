#pragma once

#include "stdafx.h"

//extern class CGameEvent;

class CMainMap
{

private:
	// map tiles & graphics
	vector <CTile*> m_mapTiles;
	long m_tileCounter;							// how much tiles we have in the game map
//	vector <ALLEGRO_BITMAP *> m_mapGraphics;	// list of all map graphics (not used yet)

	long m_activeTileID;
	CResGraphic* m_activeGraphic;

	int m_tileWidth, m_tileHeight;

	int m_mapLines;
	int m_mapCols;


public:
	CMainMap(void);
	~CMainMap(void);

	int initMap(ALLEGRO_DISPLAY *display, CData* gameData);

	void setActiveTile(long tileIndex);
	void clearMap(void);

	CTile* getTile(long);
	CTile* getTileFromScreen(long xScreen, long yScreen);
	CTile* getTileFromMap(int xMap, int yMap);

	void addTile(CResGraphic* graphic, int posLine, int posCol);

	void processEvent(CGameEvent* gameEvent);

	void draw(ALLEGRO_DISPLAY* display, CData *gameData);

};

