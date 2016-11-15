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
#ifndef VIDEOMODULE_H
#define VIDEOMODULE_H

#include "videomanager.h"
#include "../../common/rect.h"
#include <SDL.h>

class VideoModule
{
   public:
   virtual ~VideoModule(){};

   virtual void Draw(SDL_Surface* screen) = 0;

   void SetVisibility(bool v);
   bool GetVisibility() const;

   void SetClipRect(geo::Rect &clip);
   geo::Rect GetClipRect() const;

   protected:
   bool m_video_visibility;
   geo::Rect m_clip;
};

#endif
