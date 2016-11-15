#include "color.h"

namespace disp
{

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a):
m_r(r),
m_g(g),
m_b(b),
m_a(a){};

Color::Color():
m_r(0),
m_g(0),
m_b(0),
m_a(255){};

Color Color::operator+(Color &p) const
{
   Color tmp;
   tmp.m_r = ((m_r + p.m_r > 255)? 255 : (m_r + p.m_r));
   tmp.m_g = ((m_g + p.m_g > 255)? 255 : (m_g + p.m_g));
   tmp.m_b = ((m_b + p.m_b > 255)? 255 : (m_b + p.m_b));
   tmp.m_a = ((m_a + p.m_a > 255)? 255 : (m_a + p.m_a));
   return tmp;
};

Color Color::operator-(Color &p) const
{
   Color tmp;
   tmp.m_r = ((m_r - p.m_r < 0)? 0 : (m_r + p.m_r));
   tmp.m_g = ((m_g - p.m_g < 0)? 0 : (m_g + p.m_g));
   tmp.m_b = ((m_r - p.m_b < 0)? 0 : (m_b + p.m_b));
   tmp.m_a = ((m_a - p.m_a < 0)? 0 : (m_a + p.m_a));
   return tmp;
};

bool Color::operator==(Color &p) const
{
   return (m_r==p.m_r && m_g==p.m_g && m_b==p.m_b && m_a==p.m_a);
};

bool Color::operator!=(Color &p) const
{
   return !(m_r==p.m_r && m_g==p.m_g && m_b==p.m_b && m_a==p.m_a);
};

};
