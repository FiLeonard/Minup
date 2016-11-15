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

#ifndef OBJECT_H
#define OBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>

#include <vector>

#include "../common/rect.h"
#include "../common/point.h"
#include "../common/color.h"
#include "tools/geotosdlrect.h"



enum CollisionMode{
   FLEXIBLE = 0,
   INFLEXIBLE = 1
};

/**
 * This class is inherited by all objects that should be managed by the object manager
 */
class Object
{
   public:
   /**
    * Constructor
    * @param imglocation the location of the image that is loaded
    * @param mode the collision mode that is used
    */
   Object(char* imglocation, int mode = 0);
   virtual ~Object();
   /**
    * renders the image to the specified screen
    * @param screen the screen to which the object is drawn
    */
   virtual void Render(SDL_Surface* screen);
   /**
    * updates the object. Could be everything
    */
   virtual void Update();
   /**
    * sets the source coler key
    * @param r the value for red
    * @param g the value for green
    * @param b the value for blue
    */
   void Setsrccolorkey(disp::Color col);
   /**
    * sets the x value of the position
    * @param i the value for x
    */
   void SetXPos(int i){ m_rect.m_x = i;};
   /**
    * sets the y value of the position
    * @param i the value for y
    */
   void SetYPos(int i){ m_rect.m_y = i ;};
   /**
    * sets the centered x value of the position
    * @param i the value for x
    */
   void SetCenterXPos(int i){ m_rect.m_x = i - m_rect.m_w/2;};
   /**
    * sets the centered y value of the position
    * @param i the value for y
    */
   void SetCenterYPos(int i){ m_rect.m_y = i - m_rect.m_h/2;};
   /**
    * sets the x value of the velocity
    * @param i the value for x
    */
   void SetXVelocity(int i){ m_velocity.m_x = i;};
   /**
    * sets the y value of the velocity
    * @param i the value for y
    */
   void SetYVelocity(int i){ m_velocity.m_y = i;};
   /**
    * Sets the string for the object with which ths one collided(used by object manager)
    * @param name name of the object with which this one collided
    */
   void CollidesWith(char* name){m_collision_list.push_back(name);};
   /**
    * Gets the boolean for the object with which ths one collided
    * @param name name of the object that could collided with this object
    * @return a boolean that indicates wether it collided with "name" or not
    */
   bool CollidedWith(char* name);
   /**
    * Clears the whole collision list
    */
   void ClearCollisionList(){m_collision_list.clear();};
   /**
    * Gets the x and y velocity
    * @param x the pointer which will set to the member x
    * @param y the pointer which will set to the member y
    */
   geo::Point GetVelocity() const {return m_velocity;};
   /**
    * Gets the x and y position
    * @param x the pointer which will set to the velocity member x
    * @param y the pointer which will set to the velocity member y
    */
   geo::Rect GetArea() const {return m_rect;};
   /**
    * Gets the Collision mode
    * @return the collision mode
    */
   int GetCollisionMode() const {return m_mode;};

   protected:
   geo::Rect m_rect;
   geo::Point m_velocity;
   SDL_Surface* m_img;
   int m_mode;

   std::vector<char*> m_collision_list;
};
#endif
