#include "rect.h"

namespace geo
{

Rect::Rect(int x, int y, int w, int h)
{
   m_x = x;
   m_y = y;
   m_w = w;
   m_h = h;
}

int Rect::GetX() const
{
   return m_x;
}
int Rect::GetY() const
{
   return m_y;
}
int Rect::GetW() const
{
   return m_w;
}
int Rect::GetH() const
{
   return m_h;
}

Rect Rect::operator+(Rect &r) const
{
   return Rect(m_x + r.m_x,m_y + r.m_y,m_w + r.m_w,m_h + r.m_h);
};

bool Rect::IsInside(const geo::Point& p) const
{
   return (p.m_x > m_x && p.m_x < m_x + m_w && p.m_y > m_y && p.m_y < m_y + m_h);
};

};
