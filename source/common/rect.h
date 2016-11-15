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

#ifndef GEO_RECT_H
#define GEO_RECT_H

#include "point.h"
namespace geo
{
/**
  * A rectangle class with a couple of useful functions
  */
class Rect {
public:
  /**
    * Constructor that expects the metrics
    * @param x X-coordinate
    * @param y Y-coordinate
    * @param w Width
    * @param h Height
    */
  Rect( int x, int y, int w, int h );
  /**
    * Standart constructor
    */
  Rect(){};
  /**
    * Standart destructor
    */
  virtual ~Rect(){};
  /**
    * Asks for the X-coordinate
    * @return Returns the value
    */
  int GetX() const;
  /**
    * Asks for the Y-coordinate
    * @return Returns the value
    */
  int GetY() const;
  /**
    * Asks for the width
    * @return Returns the value
    */
  int GetW() const;
  /**
    * Asks for the height
    * @return Returns the value
    */
  int GetH() const;
  /**
    * Overloaded + operator, that sums all members
    * @param r the other rect
    * @return the sum as Rect
    */
  Rect operator+(Rect &r) const;
  /**
    * Checks wether point is in the Rect or not
    * @return the result of the check
    */
  bool IsInside(const geo::Point& p) const;

  int m_x;
  int m_y;
  int m_w;
  int m_h;
};

};

#endif
