#include "objectmanager.h"

bool ObjectManager::IsColliding(Object* obj1, Object* obj2)
{

	geo::Rect rect1 = obj1->GetArea();
	geo::Rect rect2 = obj2->GetArea();

	if(rect1.GetX() + rect1.GetW() <= rect2.GetX())
		return 0;
	if(rect1.GetX() >= rect2.GetX() + rect2.GetW())
		return 0;
	if(rect1.GetY() + rect1.GetH() <= rect2.GetY())
		return 0;
	if(rect1.GetY() >= rect2.GetY() + rect2.GetH())
		return 0;

	return 1;
};

ObjectManager::~ObjectManager()
{
	Clear();
};

void ObjectManager::Clear()
{
	for(m_iter = m_list.begin(); m_iter != m_list.end(); m_iter++)
	{
		delete (*m_iter).second;
		m_list.erase(m_iter);
	};
};

void ObjectManager::AddObject(char* name, Object* ptr)
{
	if(!name || !ptr)
		fprintf(stderr, "Could not add the object %s at %i to the Object Manager\n", name, ptr);
	else
		m_list[name] = ptr;
};

Object* ObjectManager::GetObject(char* name)
{
	Object* ptr = m_list[name];
	if(!ptr)
		fprintf(stderr, "This Object doesn't exist: %s\n", name);
	else
		return ptr;

	return 0;
};

void ObjectManager::Draw(SDL_Surface* screen)
{
	for(m_iter = m_list.begin(); m_iter != m_list.end(); m_iter++)
		(*m_iter).second->Render(screen);
};

void ObjectManager::Update()
{
	for(m_iter = m_list.begin(); m_iter != m_list.end(); m_iter++)
		(*m_iter).second->Update();
};

void ObjectManager::CheckCollisions()
{
	std::map <char*, Object*>::iterator iter;
	for(m_iter = m_list.begin(); m_iter != m_list.end(); m_iter++)
		(*m_iter).second->ClearCollisionList();

	if(m_list.size()>1)
	{

		for(m_iter = m_list.begin(); m_iter != m_list.end()--; m_iter++)
		{
			for(iter = m_iter,iter++; iter != m_list.end(); iter++)
			{
				if(IsColliding((*m_iter).second, (*iter).second))
				{
               #ifdef DEBUG
					fprintf(stdout, "%s collided with %s\n",(*iter).first,(*m_iter).first);
               #endif
					(*m_iter).second->CollidesWith((*iter).first);
					(*iter).second->CollidesWith((*m_iter).first);
					Bounce((*m_iter).second,(*iter).second);
					Bounce((*iter).second,(*m_iter).second);
				};
			};
		};
	};
};

void ObjectManager::Bounce(Object* obj1, Object* obj2)
{
	SDL_Rect rect1 = GEOToSDLRect(obj1->GetArea());
	SDL_Rect rect2 = GEOToSDLRect(obj2->GetArea());

	geo::Point vel= obj1->GetVelocity();

	float a = abs((rect2.x + rect2.w / 2) - (rect1.x + rect1.w / 2));
	float b = abs((rect2.y + rect2.h / 2) - (rect1.y + rect1.h / 2));
	float c = abs((rect1.w / 2 + rect2.w / 2) - a);
	float d = abs((rect1.h / 2 + rect2.h / 2) - b);

	if(d <= c)
	{
		if(rect2.y + rect2.h / 2  < rect1.y + rect1.h / 2)
		{
			if(vel.GetY() < 0)
				obj1->SetYVelocity(vel.GetY()*(-1));
		} else {
			if(vel.GetY() > 0)
				obj1->SetYVelocity(vel.GetY()*(-1));
		};
	};
	if(c <= d)
	{
		if(rect2.x + rect2.w / 2  < rect1.x + rect1.w / 2)
		{
			if(vel.GetX() < 0)
				obj1->SetXVelocity(vel.GetX()*(-1));
		} else {
			if(vel.GetX() > 0)
				obj1->SetXVelocity(vel.GetX()*(-1));
		};
	};
};

float abs(float i)
{
	if(i<0)
		return (i*(-1));
	else
		return i;
};
