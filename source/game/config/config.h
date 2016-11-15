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

#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <tinyxml.h>
#include <map>
#include <list>
#include "configlistener.h"

class ConfigListener;

class Configuration
{
	public:
		Configuration(){};
		virtual ~Configuration(){};

		void InitConfig(std::string filedst);
		void Save(){}; //TODO

		void AddListener(ConfigListener* listener);
		void RemoveListener(ConfigListener* listener);
		void ClearListeners();

		void setValue(const std::string &key, std::string value);
		void setValue(const std::string &key, float value);

		std::string GetValue(const std::string &key, std::string deflt);
		float GetValue(const std::string &key, float deflt);

	protected:
		std::map<std::string, std::string> m_settings;
		std::map<std::string, std::string>::iterator m_settingiterator;

		std::list<ConfigListener*> m_listeners;
		std::list<ConfigListener*>::iterator m_iterl;

		TiXmlDocument m_config_file;
};
#endif
