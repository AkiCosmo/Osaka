
#include "stdafx.h"

CTile::CTile(void)
{
	//m_bitmapPosX = 0;
	//m_bitmapPosY = 0;
	m_image = NULL;
	m_imageActive = NULL;
	m_idX = m_idY = 0;
	m_active = false;
}

CTile::CTile(long index)
{
	m_index = index;
}

CTile::~CTile(void)
{
}

void CTile::setImage(ALLEGRO_BITMAP* image, ALLEGRO_BITMAP* imageActive, long bitmapPosX, long bitmapPosY) {
	if (image) {
		m_image = image;
		m_imageActive = imageActive;
		//m_bitmapPosX = bitmapPosX;
		//m_bitmapPosY = bitmapPosY;

		m_width = al_get_bitmap_width(image);
		m_height = al_get_bitmap_height(image); 
	}
}

void CTile::setGraphic(CResGraphic* graphic)
{
	if (graphic) {
		m_graphic = graphic;
	}
}


int CTile::getWidth() {
	return m_width;
}

ALLEGRO_BITMAP* CTile::getImage(int style)
{
	return m_graphic->getImage(style);
}

ALLEGRO_BITMAP* CTile::getImage(void)
{

	if (m_active) {
		return m_imageActive;
	}
	else {
		return m_image;
	}
}

int CTile::getHeight() {
	return m_height;
}

void CTile::setPos(int line, int column) {
	m_posLine = line;
	m_posCol = column;

	m_idX = column;
	m_idY = line;
}

void CTile::setActive(void) {
	m_active = true;
}

void CTile::setInactive(void) {
	m_active = false;
}


