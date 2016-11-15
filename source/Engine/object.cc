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

#include "object.h"

//render the object
void Object::Render(SDL_Surface* screen)
{
	SDL_Rect blitrect = GEOToSDLRect(m_rect);
	if(m_img)
		SDL_BlitSurface(m_img, NULL, screen, &blitrect);
};


Object::Object(char* imglocation, int mode)
{
	if(imglocation)
	{
		m_img = IMG_Load(imglocation);
		if(!m_img)
			fprintf(stderr, "Following error occurred: %s\n", SDL_GetError());
		m_rect.m_w = m_img->w;
		m_rect.m_h = m_img->h;
	}else {
		m_img = 0;
	};
	m_mode = mode;
};

//moves the object with the given x and y force
void Object::Update(void)
{
	m_rect.m_x = m_rect.m_x + m_velocity.m_x;
	m_rect.m_y = m_rect.m_y + m_velocity.m_y;
};


//the destructor frees the image surface
Object::~Object()
{
	if(m_img)
		SDL_FreeSurface(m_img);
};

//sets the color key for the img
void Object::Setsrccolorkey(disp::Color col)
{
	if(m_img)
		SDL_SetColorKey(m_img, SDL_SRCCOLORKEY, SDL_MapRGB(m_img->format, col.m_r, col.m_g, col.m_b));
};

bool Object::CollidedWith(char* name)
{
	std::vector<char*>::iterator iter;
	for(iter = m_collision_list.begin(); iter != m_collision_list.end(); iter++)
	{
		if(*iter == name)
			return true;
	};
	return false;
};




