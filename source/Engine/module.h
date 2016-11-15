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
#ifndef MODULE_H
#define MODULE_H
#include "resourcemanager.h"

class ResourceManager;

/**
 * This class is inherited by all the modules that should be managed by the resource manager
 */
class Module
{
   public:
   /**
    * Called, when the module is loaded by
    * the Resource Manager ( or another class)
    */
   virtual bool Load() = 0;
   /**
    * Called, when the module is to be updated
    * the Resource Manager ( or another class)
    */
   virtual bool Unload() = 0;
   /**
    * Called, when the module is unloaded
    * the Resource Manager ( or another class)
    */
   virtual bool Update() = 0;
   /**
    * A Function that is called to become a
    * specified pointer
    * @param data the key to specify what you want
    * @return a void pointer to the asked data
    */
   virtual void* AskFor(std::string data){return 0;};

   /**
    * Called, when a signal is sent to the module
    * @param name the name of the signal
    */
   virtual void GetSignal(std::string name){};

   /**
    * A function that sets the resource manager
    * of the module
    * @param manager the pointer to the manager that is set
    */
   void SetManager(ResourceManager* manager);
   protected:
   ResourceManager* m_modulemanager;
};

#endif

