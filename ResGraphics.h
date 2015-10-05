#pragma once

#include "stdafx.h"

class CResGraphic
{

protected:
	ALLEGRO_BITMAP	*m_image;
	int m_imageCode;

public:
	CResGraphic(void);
	~CResGraphic(void);

	void setImage(ALLEGRO_BITMAP* image);
	ALLEGRO_BITMAP* getImage(int style);

	void clear(void);

	void setCode(int imageCode);
	int getCode(void);

};

