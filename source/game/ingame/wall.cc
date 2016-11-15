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

#include "wall.h"

Wall::Wall(geo::Rect area, disp::Color col):Object(0, INFLEXIBLE)
{
   m_rect = area;
   m_col = col;
};

//draws the field
void Wall::Render(SDL_Surface* screen)
{
   SDL_Rect blitrect = GEOToSDLRect(m_rect);
   SDL_FillRect(screen, &blitrect, SDL_MapRGB(screen->format, m_col.m_r, m_col.m_g, m_col.m_b));
};
