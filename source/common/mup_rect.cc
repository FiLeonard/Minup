#include "mup_rect.h"
namespace mup
{

void Rect::Center(geo::Rect &container)
{
  m_x = container.GetX() + (container.GetW() - m_w) / 2;
  m_y = container.GetY() + (container.GetH() - m_h) / 2;
}

bool Rect::Contains(int x, int y) const
{
  return( (x >= m_x) && (x < (m_x + m_w))
       && (y >= m_y) && (y < (m_y + m_h)) );
}

SDL_Rect Rect::ToSDLRect() const
{
   SDL_Rect rect;
   rect.x = m_x;
   rect.y = m_y;
   rect.w = m_w;
   rect.h = m_h;
   return rect;
};

};
