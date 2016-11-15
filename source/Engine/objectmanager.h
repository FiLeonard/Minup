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
#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "object.h"
#include <map>
#define DEBUG

/**
 * This class should manage all the objects that are used
 */
class ObjectManager
{
   public:
  ~ObjectManager();
   /**
    * Adds an Object to the manager
    * @param name the name of the object(only once)
    * @param ptr the pointer to the object
    */
   void AddObject(char* name, Object* ptr);
   /**
    * returns a pointer to an Object of the manager
    * @param name the name of the object
    */
   Object* GetObject(char* name);
   /**
    * Checks if there are any collisions between objects
    * //TODO also reacts should be replaced by an function of objects
    */
   void CheckCollisions();
   /**
    * Calls to the draw function of the objects
    * @param screen the surface to which the objects will be drawn
    */
   void Draw(SDL_Surface* screen);
   /**
    * Updates all objects
    */
   void Update();
   /**
    * Clears all objects
    */
   void Clear();

   private:
   std::map <char*, Object*> m_list;
   std::map <char*, Object*>::iterator m_iter;
   bool IsColliding(Object* obj1, Object* obj2);
   void Bounce(Object* obj1, Object* obj2);
};

float abs(float i);


#endif
