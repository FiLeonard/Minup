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

#ifndef FPSCONTROL_H
#define FPSCONTROL_H

#include <SDL.h>

/**
 * This class should manage the framerate
 */
class FPSControl
{
   public:
   FPSControl();
   /**
    * A function that should be called to know if a graphic update is needed or not
    * @return a boolean that indicates if an update is needed or not
    */
   bool NeedsGraphicRefresh(){return m_graphicrefresh;};
   /**
    * A function that should be called to know if a logic update is needed or not
    * @return a boolean that indicates if an update is needed or not
    */
   bool NeedsLogicRefresh(){return m_logicrefresh;};

   /**
    * A function that starts the graphic timer(should be called before graphic instructions)
    */
   void StartGraphicTimer(){if(m_graphicrefresh)m_graphictime = SDL_GetTicks();};
   /**
    * A function that starts the logic timer(should be called before logic instructions)
    */
   void StartLogicTimer(){if(m_logicrefresh)m_logictime = SDL_GetTicks();};
   /**
    * A function that stops the graphic timer(should be called after graphic instructions)
    * Also calculates, when the next update is needed.
    */
   void StopGraphicTimer();
   /**
    * A function that starts the logic timer(should be called after logic instructions)
    * Also calculates, when the next update is needed.
    */
   void StopLogicTimer();
   /**
    * Sets the desired graphic frames
    * @param frames the number of frames per second
    */
   void SetGraphicFrames(unsigned short frames){m_desiredgframes = frames;};
   /**
    * Sets the desired logic frames
    * @param frames the number of frames per second
    */
   void SetLogicFrames(unsigned short frames){m_desiredlframes = frames;};
   /**
    * Calculates the idle time and what should be updated first. Prefers logic frames.
    * Should be called after the logic and graphic stuff.
    */
   void Measure();

   protected:
   unsigned int m_time;
   unsigned int m_logictime;
   unsigned int m_graphictime;

   bool m_graphicrefresh;
   bool m_logicrefresh;

   int m_logicfreetime;
   int m_graphicfreetime;

   unsigned int m_nextlogicrefresh;
   unsigned int m_nextgraphicrefresh;

   unsigned short m_desiredlframes;
   unsigned short m_desiredgframes;
};
#endif
