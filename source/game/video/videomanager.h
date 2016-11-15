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
#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H

#include "videomodule.h"
#include "../../engine/module.h"
#include "../../engine/tools/geotosdlrect.h"
#include "../../common/rect.h"
#include "../config/configlistener.h"
#include <list>
#include <SDL.h>

class VideoModule;

class VideoManager : public Module, public ConfigListener
{
   public:
   bool Load();
   bool Unload();
   bool Update();

   void GetSignal(std::string name){};

   void SettingChanged(std::string name){};

   VideoManager();
   ~VideoManager();

   bool LoadScreen();
   void SetClipRect(geo::Rect &clip);


   void AddVideoModule(VideoModule* ptr);
   void RemoveVideoModule(VideoModule* ptr);
   void ClearVideoModules();

   protected:
   std::list<VideoModule*> m_videomodules;
   std::list<VideoModule*>::iterator m_iter;
   SDL_Surface* m_screen;
};

#endif
