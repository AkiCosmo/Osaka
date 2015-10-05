
#include "stdafx.h"
#include "GObject.h"


CGObject::CGObject(void)
{
}


CGObject::~CGObject(void)
{
}

bool CGObject::isClickable()
{
	return m_clickable;
}

void CGObject::setClickable(bool clickable)
{
	m_clickable = clickable;
}
