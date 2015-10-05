#pragma once

#include "stdafx.h"

class CGObject
{

protected:
	bool m_clickable;
	long posX, posY;
	long targetX, targetY;

public:
	CGObject(void);
	virtual ~CGObject(void);

	bool isClickable();
	void setClickable(bool clickable);


};

