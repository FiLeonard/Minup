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

 #ifndef RESOURCEMANAGER_H
 #define RESOURCEMANAGER_H

 #include <string>
 #include <map>
 #include "module.h"

class Module;

struct ModuleHolder
{
   Module* m_module;
   int m_state;
};

typedef std::map<std::string,ModuleHolder*>::iterator ModuleIter;

enum MODULE_STATE
{
   UNLOADED = 0,
   LOADED   = 1,
   RUNNING  = 2,
};


 class ResourceManager
 {
   public:
   ResourceManager(){};
   virtual ~ResourceManager(){};

   void AddModule(std::string name, Module* modul);
   void RemoveModule(std::string name);

   void StartModule(std::string name);
   void StartModules();

   void HaltModule(std::string name);
   void HaltModules();

   bool LoadModule(std::string name);
   void LoadModules();

   bool UnloadModule(std::string name);
   void UnloadModules();

   int GetModuleState(std::string name);

   bool UpdateModule(std::string name);
   void UpdateModules();

   virtual void SentSignal(std::string name);

   virtual void* AskFor(std::string name, std::string data);
   virtual void* AskFor(std::string data){};

   protected:
   std::map<std::string, ModuleHolder*> m_modules;
};
#endif
