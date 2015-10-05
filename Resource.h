#pragma once

#include "stdafx.h"

class CResources
{

protected:
	vector <CResGraphic*> m_graphics;

	ALLEGRO_FONT *m_fontStd;

public:
	CResources(void);
	~CResources(void);

	int initResources(void);
	void clearResources(void);

	int loadImage(string& filename, int imageID);

	CResGraphic* getGraphic(int imageID);

	ALLEGRO_FONT* getFont(int fontID);
};

