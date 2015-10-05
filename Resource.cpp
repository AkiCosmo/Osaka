#include "stdafx.h"

CResources::CResources(void)
{
}


CResources::~CResources(void)
{
}

void CResources::clearResources(void)
{
	// free all CResGraphics and their bitmaps
	ALLEGRO_BITMAP* tBitmap = NULL;

	vector <CResGraphic*>::iterator it;
	for (it = m_graphics.begin() ; it != m_graphics.end(); ++it) {
		if (*it) {
			((CResGraphic*)*it)->clear();
			delete *it;
		}
	}
}

int CResources::initResources(void) {

	// load all graphics

	string str;
	//al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
	//al_set_new_bitmap_flags(

	str = "Tile.png";
	loadImage(str, RESG_MAPTILE);

	str = "ActiveFrame.png";
	loadImage(str, RESG_MAPTILEACTIVE);

	str = "worker-blue-th2t.png";
	loadImage(str, RESG_PLAYERICON);

	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_set_path_filename(path, "DejaVuSans.ttf");
	fprintf(stderr, al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP));
	m_fontStd = al_load_ttf_font(al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP), 12, 0);
	al_destroy_path(path);

	if(!m_fontStd) {
		ostringstream errTxt;
		errTxt << "Error: CResource::initResource - Error loading DejaVuSans.ttf" <<  "\n";
		fprintf(stderr, errTxt.str().c_str());
		return RET_ERR;
	}
	return RET_OKAY;
}

int CResources::loadImage(string& filename, int imageID)
{
	ALLEGRO_BITMAP* bitmap = NULL;
	CResGraphic* graphic = NULL;

	graphic = new CResGraphic();
	if (!graphic)
		return RET_ERR;

	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_set_path_filename(path, filename.c_str());
	fprintf(stderr, al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP));
	fprintf(stderr, "\n");
	bitmap = al_load_bitmap(al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP));
	al_destroy_path(path);

	if(!bitmap) {
		ostringstream errTxt;
		errTxt << "Error: CResource::loadImage - Error loading " << filename << "\n";
		fprintf(stderr, errTxt.str().c_str());
		return RET_ERR;
	}

	graphic->setImage(bitmap);
	graphic->setCode(imageID);
	m_graphics.push_back(graphic);

	return RET_OKAY;
}

CResGraphic* CResources::getGraphic(int imageID)
{
	CResGraphic* graphic = NULL;
	unsigned int id;

//	vector <CResGraphic*>::iterator it;
//	for (it = m_graphics.begin() ; it != m_graphics.end(); ++it) {
//		if (*it) {
//			if (((CResGraphic*)*it)->getCode() == imageID) {
//				graphic = *it;
//			}
//		}
//	}
	id = imageID;
	if (id < m_graphics.size()) {
		graphic = m_graphics[imageID];
	}
	return graphic;
}


ALLEGRO_FONT* CResources::getFont(int fontID)
{
	ALLEGRO_FONT* retFont = NULL;

	switch (fontID) {
	case RESFONT_STD:
		retFont = m_fontStd;
	}

	return retFont;
}
