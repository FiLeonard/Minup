#include "eventmanager.h"

EventManager::EventManager()
{
	m_time = 0;
	m_frames = 0;
};

EventManager::~EventManager()
{
	ClearEvents();
	ClearListeners();
};

void EventManager::AddTimeEvent(std::string name, int time)
{
	Event* event = new Event;
	event->m_name = name;
	event->m_time = SDL_GetTicks() + time;
	m_events.push_back(event);
};

void EventManager::AddEvent(std::string name)
{
	Event* event = new Event;
	event->m_name = name;
	event->m_time = 0;
	m_events.push_back(event);
};

void EventManager::AddListener(EventListener* listener)
{
	m_listeners.push_back(listener);
};

void EventManager::RemoveListener(EventListener* listener)
{
	m_listeners.remove(listener);
};

bool EventManager::Update()
{
	m_time = SDL_GetTicks();
	m_frames++;
	for(m_itere = m_events.begin(); m_itere != m_events.end(); m_itere ++)
	{
		while(m_itere != m_events.end() && (*m_itere)->m_time <= m_time)
		{
			for(m_iterl = m_listeners.begin();m_iterl != m_listeners.end();m_iterl++)
				(*m_iterl)->EventBegins((*m_itere)->m_name);
			delete *m_itere;
			m_itere = m_events.erase(m_itere);
		};
	};
	return 1;
};

void EventManager::ClearEvents()
{
	for(m_itere = m_events.begin(); m_itere != m_events.end();)
	{
		delete *m_itere;
		m_itere = m_events.erase(m_itere);
	};
};

void EventManager::ClearListeners()
{
	for(m_iterl = m_listeners.begin(); m_iterl != m_listeners.end();)
	{
		delete *m_iterl;
		m_iterl = m_listeners.erase(m_iterl);
	};
};
