#include "Data.h"

#include "stdafx.h"

CData::CData(void)
{
}


CData::~CData(void)
{
}

CResources* CData::getResources(void)
{
	return &m_resources;
}

int CData::initData(void)
{
	m_resources.initResources();

	return RET_OKAY;
}

void CData::clearData(void)
{
	m_resources.clearResources();

}

ALLEGRO_FONT* CData::getFont(int fontID)
{
	ALLEGRO_FONT* retFont = NULL;

	retFont = m_resources.getFont(fontID);

	return retFont;
}

CResGraphic* CData::getGraphic(int graphicID)
{
	CResGraphic* retGraphic = NULL;
		
	retGraphic = m_resources.getGraphic(graphicID);

	return retGraphic;
}

int CData::initGameObjects()
{
	int ret = RET_OKAY;

	return ret;
}