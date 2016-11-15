#include "geotosdlrect.h"

SDL_Rect GEOToSDLRect(geo::Rect georect)
{
	SDL_Rect rect;
	rect.x = georect.m_x;
	rect.y = georect.m_y;
	rect.w = georect.m_w;
	rect.h = georect.m_h;
	return rect;
};
