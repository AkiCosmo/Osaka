
#include "stdafx.h"

CMainMap::CMainMap(void)
{
	m_tileCounter = 0;			// every tile gets an ID
	
	m_tileWidth = 0;
	m_tileHeight = 0;
	
	m_mapLines = 7;				// numer of lines in the map
	m_mapCols = 10;				// numer of columns in the map

	m_activeTileID = 0;
	m_activeGraphic = NULL;


	m_mapTiles.reserve(m_mapLines * m_mapCols);	// line * cols = num tiles in the map -> allocate the whole vector memory at once
}


CMainMap::~CMainMap(void)
{
}

void CMainMap::clearMap(void) {

	// kills the tilemap and frees memory
	vector <CTile*>::iterator it;
	for (it = m_mapTiles.begin() ; it != m_mapTiles.end(); ++it) {
		if (*it) {
			delete *it;
		}
	}
}

int CMainMap::initMap(ALLEGRO_DISPLAY *display, CData* gameData) {
	
	int iRet = RET_OKAY;
	int line=0, col=0;

	ALLEGRO_BITMAP* image = NULL;
	
	// check, if display is valid
	if (!display) {
		return RET_ERR;
	}

	image = gameData->getResources()->getGraphic(RESG_MAPTILE)->getImage(RESG_IMG_STYLE_STD);
	if (image) {
		m_tileWidth	= al_get_bitmap_width(image);
		m_tileHeight = al_get_bitmap_height(image);
	}
	else {
		return RET_ERR;
	}

	m_activeGraphic = gameData->getResources()->getGraphic(RESG_MAPTILEACTIVE);


	// load tile graphic and build a tile map
	if (iRet == RET_OKAY){
		for (line=0; line < m_mapLines; line++) {
			for (col=0; col < m_mapCols; col++) {
				addTile(gameData->getGraphic(RESG_MAPTILE), line, col);	// hier müsste eigentlich eine MAP geladen werden, so sind alle MAP-Grafiken gleich
			}
		}
	}

	setActiveTile(0);

	return iRet;
}

void CMainMap::setActiveTile(long tileIndex) {
	
	if (tileIndex < m_tileCounter) {	

		m_mapTiles[m_activeTileID]->setInactive();

		m_activeTileID = tileIndex;
		m_mapTiles[tileIndex]->setActive();					
	}
}

CTile* CMainMap::getTile(long index) {

	CTile* seekTile = NULL;
	unsigned long l = index;

	if (m_mapTiles.size() > l) {

		seekTile = m_mapTiles[index];
	}

	return seekTile;
}

CTile* CMainMap::getTileFromScreen(long xScreen, long yScreen) {
	
	CTile* retTile = NULL;
	long tx, ty;

	if (xScreen >= 0 && yScreen >= 0) {
		
		ldiv_t ldivresult;

		ldivresult = ldiv(xScreen+1, m_tileWidth);
		tx = ldivresult.quot;

		ldivresult = ldiv(yScreen+1, m_tileHeight);
		ty = ldivresult.quot;

		ostringstream ostr;
		ostr << "\ntx: " << tx << ", ty: " << ty << "\n";
		fprintf(stderr, ostr.str().c_str());

		retTile = getTileFromMap(tx, ty);
	}
	else {
		fprintf(stderr, "DataErr: CTile::getTile - x or y value <0!!\n");
	}

	return retTile;
}

CTile* CMainMap::getTileFromMap(int xMap, int yMap) {
	
	CTile* retTile = NULL;

	vector <CTile*>::iterator it;
	for (it = m_mapTiles.begin() ; it != m_mapTiles.end(); ++it) {
		if (*it) {
			if ((*it)->m_idX ==  xMap && (*it)->m_idY == yMap) {
				retTile = *it;
			}
		}
	}

	return retTile;
}

void CMainMap::addTile(CResGraphic* graphic, int posLine, int posCol)
{
	CTile *tile = new CTile;

	tile->setGraphic(graphic);
	
	tile->setPos(posLine, posCol);
	
	tile->m_index = m_tileCounter;
	m_tileCounter++;

	m_mapTiles.push_back(tile);

}

void CMainMap::draw(ALLEGRO_DISPLAY* display, CData *gameData) {

	ALLEGRO_BITMAP* image = NULL;
	long xTilePos, yTilePos;
	ALLEGRO_FONT* font = NULL;

	// draw all map tiles as map background
	vector <CTile*>::iterator it;
	CTile* tile = NULL;

	image =	gameData->getResources()->getGraphic(RESG_MAPTILE)->getImage(RESG_IMG_STYLE_STD);
	font = gameData->getFont(RESFONT_STD);
	ALLEGRO_COLOR color =  al_map_rgb(255,255,255);
	al_set_target_bitmap(al_get_backbuffer(display));

	for (it = m_mapTiles.begin() ; it != m_mapTiles.end(); ++it) {
		ostringstream ostr;
		if (tile = *it) {

			//image = tile->getImage();	// eigentlich richtig, wenn die Tiles unterschiedlich sind

			xTilePos = m_tileWidth * tile->m_idX;
			yTilePos = m_tileHeight * tile->m_idY;
			al_draw_bitmap(image,  xTilePos, yTilePos, 0);
			ostr << "[" << tile->m_idX << "," << tile->m_idY << "]";
			al_draw_text(font,color, xTilePos + 45, yTilePos + 45 ,ALLEGRO_ALIGN_CENTRE, ostr.str().c_str());
		}
	}

	image = m_activeGraphic->getImage(RESG_IMG_STYLE_STD);
	al_draw_bitmap(image,  m_tileWidth * m_mapTiles[m_activeTileID]->m_idX, m_tileHeight * m_mapTiles[m_activeTileID]->m_idY, 0);


	// draw menu
	// a) use menu icons
	// b) catch mouse
	// c) show menu popup
	// d) select build tile and place it on the map
}

void CMainMap::processEvent(CGameEvent *gameEvent) {
	if (false == gameEvent->isFinished()) {
		if (MOUSEBUTTON_DOWN == gameEvent->getEventType()) {
			
			CTile* tile = NULL;
			ALLEGRO_EVENT *alEvent = NULL;
			
			if (alEvent = gameEvent->getAlEvent()) {

				if (MOUSEBUTTONLEFT == alEvent->mouse.button) {		// left mousebotton in map selects a tile
					ostringstream ostr;
					//ostr << "\nKoords - x: " << alEvent->mouse.x << ", y: " << alEvent->mouse.y;
					//fprintf(stderr, ostr.str().c_str());

					if (tile = getTileFromScreen(alEvent->mouse.x, alEvent->mouse.y)) {
						ostr << "\ntile index: " << tile->m_index << ", x: " << tile->m_idX << " / y: " << tile->m_idY;
						fprintf(stderr, ostr.str().c_str());

						setActiveTile(tile->m_index);
					}
				}
			}
		}
	}
}
