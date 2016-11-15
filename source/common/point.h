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

#ifndef GEO_POINT_H
#define GEO_POINT_H

namespace geo
{
/**
  * A point class with a couple of useful functions
  */
class Point {
public:
  /**
    * Constructor that expects x and y
    * @param x X-coordinate
    * @param y Y-coordinate
    */
  Point(int x, int y, int z = 0);
  /**
    * Standart constructor
    */
  Point();
  /**
    * Standart destructor
    */
  virtual ~Point(){};
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
    * Asks for the Z-coordinate
    * @return Returns the value
    */
  int GetZ() const;
  /**
    * Overloaded + operator, that sums x and y
    * @param p the other point
    * @return the sum as Point
    */
  Point operator+(Point &p) const;

  int m_x;
  int m_y;
  int m_z;
};

};

#endif
