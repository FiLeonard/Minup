/* minup - yet another pong-like game
 *
 * Copyright (C) 2005 Leonard Fischer (Crimson-Skies@gmx.de)
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

#ifndef WALL_H
#define WALL_H

#include <SDL.h>
#include "../../engine/object.h"
#include "../../common/rect.h"
#include "../../common/color.h"


class Wall : public Object
{
	public:
	Wall(geo::Rect area, disp::Color col);
	void Render(SDL_Surface* screen);

   private:
   disp::Color m_col;
};

#endif
