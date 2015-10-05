
#include "stdafx.h"

//#include "ResGraphics.h"


CResGraphic::CResGraphic(void)
{
	m_imageCode = 0;
}


CResGraphic::~CResGraphic(void)
{
}

void CResGraphic::setImage(ALLEGRO_BITMAP* image)
{
	if (image) {
		m_image = image;
	}
}

ALLEGRO_BITMAP* CResGraphic::getImage(int style)
{
	ALLEGRO_BITMAP* retBitmap = NULL;

	switch (style) {
	case RESG_IMG_STYLE_STD:
		retBitmap = m_image;
	}

	return retBitmap;
}

void CResGraphic::clear(void)
{
	if (m_image) {
		al_destroy_bitmap(m_image);	
	}

}

void CResGraphic::setCode(int imageCode)
{
	if (imageCode >0) {
		m_imageCode = imageCode;
	}
}

int CResGraphic::getCode(void)
{
	return m_imageCode;
}
