/* minup - yet another pong-like game
 *
 * Copyright (C) 2005 Fabian Ruette (fabianruette@web.de), Leonard Fischer (Crimson-Skies@gmx.de)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h, int r, int g, int b):Object(0, INFLEXIBLE)
{
   m_posx = x;
   m_posy = y;
   m_blitrect.x = x;
   m_blitrect.y = y;
   m_blitrect.h = h;
   m_blitrect.w = w;
   m_col.r = r;
   m_col.g = g;
   m_col.b = b;
   m_velx = 0;
   m_vely = 0;
};

//draws the field
void Rectangle::Render(SDL_Surface* screen)
{
   SDL_FillRect(screen, &m_blitrect, SDL_MapRGB(screen->format, m_col.r, m_col.g, m_col.b));
};
