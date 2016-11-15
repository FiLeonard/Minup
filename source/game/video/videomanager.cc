#include "VideoManager.h"

bool VideoManager::Load()
{
   return 1;
};

bool VideoManager::Unload()
{
	SDL_FreeSurface(m_screen);
	m_screen = 0;
	ClearVideoModules();
	return 1;
};

bool VideoManager::Update()
{
	for(m_iter = m_videomodules.begin(); m_iter != m_videomodules.end(); m_iter ++)
   {
		if((*m_iter)->GetVisibility())
		(*m_iter)->Draw(m_screen);
   };
   SDL_Flip(m_screen);
};

VideoManager::VideoManager()
{
	Load();
	m_screen = 0;
};

VideoManager::~VideoManager()
{
	Unload();
};

bool VideoManager::LoadScreen()
{
	if(SDL_WasInit(SDL_INIT_VIDEO))
	{
		if(m_screen)
		SDL_FreeSurface(m_screen);
		m_screen = SDL_SetVideoMode((int)m_config->GetValue("width", 640), (int)m_config->GetValue("height", 480),(int)m_config->GetValue("bpp", 16), SDL_HWSURFACE|SDL_DOUBLEBUF);
		return m_screen;
	} else
	return 0;
};

void VideoManager::AddVideoModule(VideoModule* ptr)
{
	m_videomodules.push_back(ptr);
};

void VideoManager::RemoveVideoModule(VideoModule* ptr)
{
	m_videomodules.remove(ptr);
};

void VideoManager::ClearVideoModules()
{
   m_videomodules.clear();
};

void VideoManager::SetClipRect(geo::Rect &clip)
{
   if(m_screen)
   {
      if(!clip.m_w && !clip.m_h)
      SDL_SetClipRect(m_screen, 0);
      else
      {
         SDL_Rect blitrect = GEOToSDLRect(clip);
         SDL_SetClipRect(m_screen, &blitrect);
      };
   };
}
