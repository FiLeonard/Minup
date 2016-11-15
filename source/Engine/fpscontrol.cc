#include "fpscontrol.h"

FPSControl::FPSControl()
{
	m_time = SDL_GetTicks();
	m_nextlogicrefresh = 0;
	m_nextgraphicrefresh = 0;
	m_graphictime = 0;
	m_logictime = 0;
	m_graphicrefresh = true;
	m_logicrefresh = true;
};


void FPSControl::Measure()
{
	m_time = SDL_GetTicks();

	if(m_nextgraphicrefresh < m_nextlogicrefresh)
	{
		int tmp = m_nextgraphicrefresh - SDL_GetTicks();
		fprintf(stderr, "Delay: %i\n", tmp);
		fprintf(stderr, "Graphictime: %i\n", m_graphictime);
		fprintf(stderr, "nextgraphicRefresh: %i\n", m_nextgraphicrefresh);
		fprintf(stderr, "Logictime: %i\n", m_logictime);
		fprintf(stderr, "nextlogicRefresh: %i\n", m_nextlogicrefresh);
		if(tmp > 0)
			SDL_Delay(tmp);
		m_graphicrefresh = true;
		m_logicrefresh = false;
		fprintf(stderr, "graphic\n");
	}else {
		int tmp = m_nextlogicrefresh - SDL_GetTicks();
		fprintf(stderr, "Delay: %i\n", tmp);
		fprintf(stderr, "Logictime: %i\n", m_logictime);
		fprintf(stderr, "nextlogicRefresh: %i\n", m_nextlogicrefresh);
		fprintf(stderr, "Graphictime: %i\n", m_graphictime);
		fprintf(stderr, "nextgraphicRefresh: %i\n", m_nextgraphicrefresh);
		if(tmp > 0)
			SDL_Delay(tmp);
		m_graphicrefresh = false;
		m_logicrefresh = true;
		fprintf(stderr, "Logic\n");
	};


};

void FPSControl::StopGraphicTimer()
{
	if(m_graphicrefresh)
	{
		m_graphictime = SDL_GetTicks() - m_graphictime;
		m_graphicfreetime = (1000 - (m_desiredgframes * m_graphictime)) / (m_desiredgframes - 1);
		if(m_graphicfreetime > 0)
		{
			if(m_graphicfreetime > 1000)
			{
				m_nextgraphicrefresh = SDL_GetTicks();
				m_nextlogicrefresh = m_nextgraphicrefresh;
			}else
				m_nextgraphicrefresh =  m_nextgraphicrefresh + m_graphicfreetime;
		};
	};
};
void FPSControl::StopLogicTimer()
{

	if(m_logicrefresh)
	{
		m_logictime = SDL_GetTicks() - m_logictime;
		m_logicfreetime = (1000 - (m_desiredlframes * m_logictime)) / (m_desiredlframes - 1);
		if(m_logicfreetime > 0)
		{
			if(m_logicfreetime > 1000)
			{
				m_nextlogicrefresh = SDL_GetTicks();
				m_nextgraphicrefresh = m_nextlogicrefresh;
			}else
				m_nextlogicrefresh =  m_nextlogicrefresh + m_logicfreetime;
		};
	};
};
