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

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../engine/resourcemanager.h"
#include "../engine/EventListener.h"
#include "../engine/EventManager.h"
#include "../engine/fpscontrol.h"
#include "config/config.h"
#include "config/configlistener.h"
#include "gui/gui.h"
#include "ingame/game.h"
#include "video/videomanager.h"

class GameManager : public ResourceManager, public ConfigListener
{
	public:
		GameManager();
		~GameManager();

		void Start();

		// ResourceManager
		void* AskFor(std::string data);

		void SentSignal(std::string name);

		//OptionListener
		void SettingChanged(std::string name){};

	private:
		// important components that doesnt have to be a module
		Configuration* m_config;
		FPSControl*    m_fpscontrol;

		// the components that have to be a module
		VideoManager* m_video_module;
		Gui*          m_gui_module;
		Game*         m_game_module;

		//the indicator for the game loop
		bool m_running;
};

#endif
