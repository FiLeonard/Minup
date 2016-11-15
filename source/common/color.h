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

#ifndef DISP_COLOR_H
#define DISP_COLOR_H

namespace disp
{
/**
  * A color class with a couple of useful functions
  */
class Color {
public:
  /**
    * Constructor that expects all color components
    * @param r red
    * @param g green
    * @param b blue
    * @param a alpha
    */
  Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);
  /**
    * Standart constructor
    */
  Color();
  /**
    * Standart destructor
    */
  virtual ~Color(){};
  /**
    * Overloaded + operator, that sums r,g,b and a
    * @param p the other Color
    * @return the sum as Color
    */
  Color operator+(Color &p) const;

  /**
    * Overloaded - operator, that substracts r,g,b and a
    * @param p the other Color
    * @return the substracted Color
    */
  Color operator-(Color &p) const;

  /**
    * Overloaded == operator, that compares r,g,b and a
    * @param p the other Color
    * @return indicates the result of the comparison
    */
  bool operator==(Color &p) const;

  /**
    * Overloaded != operator, that compares r,g,b and a
    * @param p the other Color
    * @return indicates the result of the comparison
    */
  bool operator!=(Color &p) const;

  unsigned char m_r;
  unsigned char m_g;
  unsigned char m_b;
  unsigned char m_a;
};

};

#endif
