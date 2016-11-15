/* minup - yet another pong-like game
 *
 * Copyright (C) 2005 Fabian Ruette (fabianruette@web.de), Leonard Fischer (Crimson-Skies@gmx.de)
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

#include "config.h"
#include "../../engine/tools/converttostring.h"

void Configuration::InitConfig(std::string filedst)
{
	if(!m_config_file.LoadFile(filedst.c_str())){

		fprintf(stderr, "Error while loading the file: %s\n", m_config_file.ErrorDesc());
		exit(1);
	}
	TiXmlElement* tmp;
	std::string str;
	TiXmlElement* root = m_config_file.RootElement();
	tmp = root->FirstChildElement("Setting");
	TiXmlAttribute* atr;
	while(tmp)
	{
		atr = tmp->FirstAttribute();
		if(atr)
		{
			str = atr->Name();
			m_settings[str] = tmp->Attribute(str.c_str());
		}
		tmp = tmp->NextSiblingElement("Setting");
	};
};

void Configuration::AddListener(ConfigListener* listener)
{
	m_listeners.push_back(listener);
	listener->SetConfig(this);
};

void Configuration::RemoveListener(ConfigListener* listener)
{
	m_listeners.remove(listener);
	listener->SetConfig(0);
};

void Configuration::ClearListeners()
{
	m_listeners.clear();
};

std::string Configuration::GetValue(const std::string &key, std::string deflt)
{
	m_settingiterator = m_settings.find(key);
	return ((m_settingiterator != m_settings.end()) ? m_settingiterator->second : deflt);
};

float Configuration::GetValue(const std::string &key, float deflt)
{
	m_settingiterator = m_settings.find(key);
	return ((m_settingiterator != m_settings.end()) ? atof(m_settingiterator->second.c_str()) : deflt);
};

void Configuration::setValue(const std::string &key, std::string value)
{
	m_settings[key] = value;
	for(m_iterl = m_listeners.begin();m_iterl != m_listeners.end();m_iterl++)
		(*m_iterl)->SettingChanged(key);
};
void Configuration::setValue(const std::string &key, float value)
{
	m_settings[key] = ConvertToString(value);
	for(m_iterl = m_listeners.begin();m_iterl != m_listeners.end();m_iterl++)
		(*m_iterl)->SettingChanged(key);
};
