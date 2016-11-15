#include "point.h"

namespace geo
{

Point::Point(int x, int y, int z):
m_x(x),
m_y(y),
m_z(z){};

Point::Point():
m_x(0),
m_y(0),
m_z(0){};

int Point::GetX() const
{
   return m_x;
};
int Point::GetY() const
{
   return m_y;
};
int Point::GetZ() const
{
   return m_z;
};

Point Point::operator+(Point &p) const
{
   return Point(m_x + p.m_x,m_y + p.m_y, m_z + p.m_z);
};

};
