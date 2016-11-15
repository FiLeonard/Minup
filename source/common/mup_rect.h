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

#ifndef MUP_RECT_H
#define MUP_RECT_H

#include <SDL.h>
#include "rect.h"

namespace mup
{
/**
  * A rectangle class especially for minup
  */
class Rect:public geo::Rect
{
   public:
   Rect(int x, int y, int w, int h):geo::Rect(x,y,w,h){};
   Rect():geo::Rect(){};
   virtual ~Rect(){};
   /**
    * Centers the rectangle relativly
    * @param container the rectangle to that the rectangle will be centered
    */
  void Center(geo::Rect &container );
  /**
    * Checks if a point is in the rectangle
    * @param x the X-coordinate
    * @param y the Y-coordinate
    * @return a boolean value that indicates wether the point is in the rectangle or not
    */
  bool Contains(int x, int y) const;
  /**
    * Converts the rectangle to an SDL compatible rectangle
    * @return return the SDL compatible rectangle
    */
  SDL_Rect ToSDLRect() const;
};

};

#endif
