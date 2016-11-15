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
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <string>
#include <list>
#include <SDL.h>
#include "eventlistener.h"

struct Event
{
	std::string m_name;
	int m_time;
};

class EventListener;

class EventManager
{
	public:
		EventManager();
		~EventManager();
		/**
		 * A function that adds an event
		 * @param name the string that is given to the listeners function
		 * @param time the time when the event should start. relative to now.
		 * @param duration the time that should pass by since the event started to call the listeners function
		 */
		void AddTimeEvent(std::string name, int time);
		/**
		 * A function that adds an event that imidiatly call the listener functions
		 * @param name the string that is given to the listeners function
		 */
		void AddEvent(std::string name);
		/**
		 * A function that adds a listener
		 * @param listener a pointer to a listener, that is to be added
		 */
		void AddListener(EventListener* listener);
		/**
		 * A function that removes a listener
		 * @param listener a pointer to a listener, that is to be removed
		 */
		void RemoveListener(EventListener* listener);
		/**
		 * A function that updates the Manager. Do the managers job etc
		 */
		bool Update();
		/**
		 * A function that clears all events
		 */
		void ClearEvents();
		/**
		 * A function that clears all listeners
		 */
		void ClearListeners();

	protected:
		int m_time;
		int m_frames;
		std::list<EventListener*> m_listeners;
		std::list<EventListener*>::iterator m_iterl;
		std::list<Event*> m_events;
		std::list<Event*>::iterator m_itere;
};

#endif

