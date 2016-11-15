#include "game.h"

bool Game::Load()
{
	m_manager.AddObject("WallT", new Wall(geo::Rect(0,   50,  640, 20),disp::Color(255,255,255)));
	m_manager.AddObject("WallB", new Wall(geo::Rect(0,   460, 640, 20),disp::Color(255,255,255)));
	m_manager.AddObject("WallL", new Wall(geo::Rect(0,   70,  20,  390),disp::Color(255,255,255)));
	m_manager.AddObject("WallR", new Wall(geo::Rect(620, 70,  20,  390),disp::Color(255,255,255)));
	m_manager.AddObject("PaddleL", new Object("./res/paddle.png"));
	m_manager.AddObject("Ball", new Object("./res/ball.png"));
	m_manager.GetObject("Ball")->Setsrccolorkey(disp::Color(255,0,255));
	m_manager.GetObject("PaddleL")->Setsrccolorkey(disp::Color(255,0,255));
	m_manager.AddObject("PaddleR", new Object("./res/paddle.png"));
	m_manager.GetObject("PaddleR")->Setsrccolorkey(disp::Color(255,0,255));
	m_p1points = 0;
	m_p2points = 0;
	return 1;
};

bool Game::Unload()
{
	Clear();
	return 1;
};

void Game::Clear()
{
	m_manager.Clear();
};

void Game::NewRound()
{
	m_manager.GetObject("Ball")->SetCenterXPos(320);
	m_manager.GetObject("Ball")->SetCenterYPos(240);
	m_manager.GetObject("PaddleL")->SetCenterXPos(60);
	m_manager.GetObject("PaddleL")->SetCenterYPos(240);
	m_manager.GetObject("Ball")->SetYVelocity(0);
	srand (time(NULL));
	if(rand()%2)
		m_manager.GetObject("Ball")->SetXVelocity(-4);
	else
		m_manager.GetObject("Ball")->SetXVelocity(4);
	m_manager.GetObject("PaddleR")->SetCenterXPos(580);
	m_manager.GetObject("PaddleR")->SetCenterYPos(240);
};

void Game::Draw(SDL_Surface* screen)
{
	m_manager.Draw(screen);
};

bool Game::Update()
{

	m_manager.CheckCollisions();
	m_manager.Update();

	if(m_config->GetValue("Player", 100) == 2)
		VSPlayerLogic();
	else if(m_config->GetValue("Player", 100) == 1)
		VSCpuLogic();
	Input();
};

void Game::VSCpuLogic()
{
	VSPlayerLogic();
	KiCalc();
};

void Game::VSPlayerLogic()
{
	if(m_manager.GetObject("WallL")->CollidedWith("Ball"))
	{
		m_p2points++;
		NewRound();
	};
	if(m_manager.GetObject("WallR")->CollidedWith("Ball"))
	{
		m_p1points++;
		NewRound();
	};

	if(m_manager.GetObject("PaddleL")->CollidedWith("Ball"))
	{
		int vel;
		geo::Rect rp = m_manager.GetObject("PaddleL")->GetArea();
		geo::Rect rb = m_manager.GetObject("Ball")->GetArea();
		if((rb.m_y+rb.m_h/2)<(rp.m_y + 4*rp.m_h/6) && (rb.m_y+rb.m_h/2)>(rp.m_y + 2*rp.m_h/6))
		vel = 0;
		if((rb.m_y+rb.m_h/2)>(rp.m_y + 4*rp.m_h/6))
		vel = 2;
		if((rb.m_y+rb.m_h/2)<(rp.m_y + 2*rp.m_h/6))
		vel = -2;
		m_manager.GetObject("Ball")->SetYVelocity(vel);
	};
	if(m_manager.GetObject("PaddleR")->CollidedWith("Ball"))
	{
		int vel;
		geo::Rect rp = m_manager.GetObject("PaddleR")->GetArea();
		geo::Rect rb = m_manager.GetObject("Ball")->GetArea();
		if((rb.m_y+rb.m_h/2)<(rp.m_y + 4*rp.m_h/6) && (rb.m_y+rb.m_h/2)>(rp.m_y + 2*rp.m_h/6))
		vel = 0;
		if((rb.m_y+rb.m_h/2)>(rp.m_y + 4*rp.m_h/6))
		vel = 2;
		if((rb.m_y+rb.m_h/2)<(rp.m_y + 2*rp.m_h/6))
		vel = -2;
		m_manager.GetObject("Ball")->SetYVelocity(vel);
	};
};

void Game::Input()
{
	Uint8 *keys = SDL_GetKeyState(NULL);

	if(keys[SDLK_w])
		m_manager.GetObject("PaddleL")->SetYVelocity(-2);
	else if(keys[SDLK_s])
		m_manager.GetObject("PaddleL")->SetYVelocity(2);
	else
		m_manager.GetObject("PaddleL")->SetYVelocity(0);

	if(m_config->GetValue("Player", 100) == 2)
	{
		if(keys[SDLK_UP])
			m_manager.GetObject("PaddleR")->SetYVelocity(-2);
		else if(keys[SDLK_DOWN])
			m_manager.GetObject("PaddleR")->SetYVelocity(2);
		else
			m_manager.GetObject("PaddleR")->SetYVelocity(0);
	};
};


void Game::KiCalc()
{
	geo::Rect rectb = m_manager.GetObject("Ball")->GetArea();
	geo::Rect rectp = m_manager.GetObject("PaddleR")->GetArea();

	if(rectb.m_y + rectb.m_h/2 < rectp.m_y + rectp.m_h/2)
		m_manager.GetObject("PaddleR")->SetYVelocity(-1);
	if(rectb.m_y + rectb.m_h/2 > rectp.m_y + rectp.m_h/2)
		m_manager.GetObject("PaddleR")->SetYVelocity(1);
};

void Game::GetSignal(std::string name)
{
	if(name == "PongStart")
	{
		NewRound();
		m_p1points = 0;
		m_p2points = 0;
	};
};

void* Game::AskFor(std::string data)
{
	if(data == "P1Points")
	{
		return &m_p1points;
	} else if(data == "P2Points")
	{
		return &m_p2points;
	} else
		return 0;
};
