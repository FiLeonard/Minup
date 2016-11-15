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

#ifndef GUI_H
#define GUI_H

#include <guichan.hpp>
#include <guichan/sdl.hpp>
#include "widgets.h"
#include "sdltruetypefont/sdltruetypefont.hpp"
#include "../../engine/module.h"
#include "../../engine/eventlistener.h"
#include "../video/videomodule.h"
#include "../config/configlistener.h"

class Gui : public gcn::Gui, public gcn::ActionListener, public ConfigListener, public Module, public VideoModule
{
	public:
		Gui();
		~Gui();

		void action(const gcn::ActionEvent& actionEvent);

		bool Load();
		bool Unload();
		bool Update();

		void GetSignal(std::string name);

		void SettingChanged(std::string name){};

		void Draw(SDL_Surface* screen);

	protected:
		void InitMain();
		void CleanMain();
		void InitOptions();
		void CleanOptions();
		void InitMenu();
		void CleanMenu();
		void InitIngame();
		void CleanIngame();
		void InitGametypes();
		void CleanGametypes();
		void InitInetchoose();
		void CleanInetchoose();
		void InitConnect();
		void CleanConnect();

		gcn::SDLTrueTypeFont* m_font;
		gcn::SDLImageLoader* m_sdlimageloader;

		gcn::Container* m_crown;
		gcn::Container* m_menu;

		gcn::Container* m_ingame;
		gcn::Label* m_player1;
		gcn::Label* m_player2;
		gcn::Label* m_title;

		gcn::Container* m_gametype;
		SubMenu* m_gametypeentrys;

		gcn::Container* m_inetchoose;
		SubMenu* m_inetchooseentrys;

		gcn::Container* m_main;
		SubMenu* m_mainentrys;

		gcn::Container* m_options;
		SubMenu* m_optionentrys;
		Spin* m_resolution;
		Spin* m_fullscreen;

		gcn::Container* m_connect;
		SubMenu* m_connectentrys;
		gcn::TextField* m_ip;
		gcn::TextField* m_port;
};

#endif
