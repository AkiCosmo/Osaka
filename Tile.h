#pragma once

#include "stdafx.h"

class CTile
{
	friend class CMainMap;

private:
	long m_index;
	long m_idX, m_idY;

	bool m_active;

	ALLEGRO_BITMAP* m_image;
	ALLEGRO_BITMAP* m_imageActive;

	CResGraphic *m_graphic;

//	long m_bitmapPosX;
//	long m_bitmapPosY;
	int m_posLine;
	int m_posCol;

	int m_width;
	int m_height;

public:
	CTile(void);
	CTile(long index);
	~CTile(void);

	void setImage(ALLEGRO_BITMAP* image, ALLEGRO_BITMAP* imageActive, long bitmapPosX, long bitmapPosY);
	void setGraphic(CResGraphic* graphic);
	ALLEGRO_BITMAP* getImage(int style);

	ALLEGRO_BITMAP* getImage(void);

	void setPos(int line, int column);

	void setActive(void);
	void setInactive(void);

	int getWidth();
	int getHeight();
};

