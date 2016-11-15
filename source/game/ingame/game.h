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

#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <SDL.h>
#include <string.h>

#include "../../engine/objectmanager.h"
#include "../../engine/eventlistener.h"
#include "../../engine/module.h"
#include "wall.h"
#include "../video/videomodule.h"


class Game : public Module, public VideoModule, public ConfigListener
{
	public:
		Game(){};
		~Game(){};

		void Draw(SDL_Surface* screen);

		bool Load();
		bool Unload();
		bool Update();

		void* AskFor(std::string data);

		void GetSignal(std::string name);

		void SettingChanged(std::string name){}; //TODO

	private:
		void Input();
		void KiCalc();
		void NewRound();

		void Clear();

		void VSPlayerLogic();
		void VSCpuLogic();

		ObjectManager m_manager;

		int m_p1points;
		int m_p2points;
};
#endif
