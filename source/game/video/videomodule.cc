#include "VideoModule.h"

void VideoModule::SetVisibility(bool v)
{
   m_video_visibility = v;
};

bool VideoModule::GetVisibility() const
{
   return m_video_visibility;
};

void VideoModule::SetClipRect(geo::Rect &clip)
{
   m_clip = clip;
};

geo::Rect VideoModule::GetClipRect() const
{
   return m_clip;
};
