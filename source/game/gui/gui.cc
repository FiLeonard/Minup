#include "gui.h"

Gui::Gui()
{};

Gui::~Gui()
{
	Unload();
};

bool Gui::Load()
{
	m_sdlimageloader = new gcn::SDLImageLoader;
	gcn::Image::setImageLoader(m_sdlimageloader);

	mInput = new gcn::SDLInput();
	mGraphics = new gcn::SDLGraphics();

	m_font = new gcn::SDLTrueTypeFont("res/gamefont.ttf", 30);

	gcn::Widget::setGlobalFont(m_font);

	m_crown = new gcn::Container();
	m_crown->setDimension(gcn::Rectangle(0, 0, 640, 480));
	m_crown->setOpaque(false);
	setTop(m_crown);

	InitIngame();
	InitMenu();
	m_main->setVisible(true);
	m_mainentrys->requestFocus();

	if(!m_font || !mInput || !mGraphics)
		return 0;
	else
		return 1;
};

bool Gui::Unload()
{
	delete m_font;
	m_font = 0;
	delete m_crown;
	m_crown = 0;
	delete mInput;
	mInput = 0;
	delete mGraphics;
	mGraphics = 0;
	CleanMenu();
	CleanIngame();
	return 1;
};

bool Gui::Update()
{
	logic();

	if(m_ingame->isFocused())
	{
		char buff[10];
		int* a = (int*) m_modulemanager->AskFor("Game", "P1Points");
		itoa(*a, buff, 10);
		m_player1->setCaption(buff);
		a = (int*) m_modulemanager->AskFor("Game", "P2Points");
		itoa(*a, buff, 10);
		m_player2->setCaption(buff);
	};

   SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if(event.key.keysym.sym == SDLK_ESCAPE)
			{
				m_modulemanager->SentSignal("PongEnd");
			};
			((gcn::SDLInput*) mInput)->pushInput(event);
		}
		else if (event.type == SDL_KEYUP)
		{
			((gcn::SDLInput*) mInput)->pushInput(event);
		}
		else if (event.type == SDL_QUIT)
			m_modulemanager->SentSignal("End");
	}
}

void Gui::InitMain()
{
	m_main = new gcn::Container();
	m_mainentrys = new SubMenu();

	m_mainentrys->addString("Play Game");
	m_mainentrys->addString("Options");
	m_mainentrys->addString("Exit");

	m_menu->add(m_main);
	m_main->setDimension(gcn::Rectangle(0, 0, 640, 480));
	m_main->setBaseColor(gcn::Color(0,0,0));
	m_main->setOpaque(true);

	m_main->add(m_mainentrys, 70, 70);
	m_mainentrys->setActionEventId("main");
	m_mainentrys->addActionListener(this);
	m_mainentrys->setBackgroundColor(gcn::Color(0,0,0));
	m_mainentrys->setForegroundColor(gcn::Color(255,255,255));

	m_mainentrys->setSelected(0);
	m_main->setVisible(0);
};

void Gui::CleanMain()
{
	delete m_main;
	m_main = 0;
	delete m_mainentrys;
	m_mainentrys = 0;
};

void Gui::InitIngame()
{
	m_ingame = new gcn::Container();
	m_player1 = new gcn::Label();
	m_player2 = new gcn::Label();
	m_title = new gcn::Label();


	m_crown->add(m_ingame);
	m_ingame->setDimension(gcn::Rectangle(0, 0, 640, 480));
	m_ingame->setBaseColor(gcn::Color(0,0,0));
	m_ingame->setOpaque(true);
	m_ingame->setVisible(0);
	m_ingame->setFocusable(true);

	m_player1->setDimension(gcn::Rectangle(20, 20, 80, 30));
	m_player2->setDimension(gcn::Rectangle(540, 20, 80, 30));
	m_player1->setAlignment(gcn::Graphics::CENTER);
	m_player2->setAlignment(gcn::Graphics::CENTER);
	m_player1->setCaption("0");
	m_player2->setCaption("0");
	m_player1->setForegroundColor(gcn::Color(255,255,255));
	m_player2->setForegroundColor(gcn::Color(255,255,255));

	m_title->setDimension(gcn::Rectangle(80, 20, 480, 30));
	m_title->setAlignment(gcn::Graphics::CENTER);
	m_title->setCaption("NEwMinUP");
	m_title->setForegroundColor(gcn::Color(255,255,255));

	m_ingame->add(m_player1);
	m_ingame->add(m_player2);
	m_ingame->add(m_title);
};

void Gui::CleanIngame()
{
	delete m_ingame;
	m_ingame = 0;
	delete m_player1;
	m_player1 = 0;
	delete m_player2;
	m_player2 = 0;
	delete m_title;
	m_title = 0;
};


void Gui::InitOptions()
{
	m_options = new gcn::Container();
	m_optionentrys = new SubMenu();
	m_resolution = new Spin;
	m_fullscreen = new Spin;

	m_optionentrys->addString("Resolution");
	m_optionentrys->addString("Fullscreen");
	m_optionentrys->addString("Back");

	m_resolution->addString("1024*768");
	m_resolution->addString("800*600");
	m_resolution->addString("640*480");

	m_fullscreen->addString("on");
	m_fullscreen->addString("off");


	m_menu->add(m_options);
	m_options->setDimension(gcn::Rectangle(0, 0, 640, 480));
	m_options->setBaseColor(gcn::Color(0,0,0));
	m_options->setOpaque(true);

	m_options->add(m_optionentrys, 70, 70);
	m_optionentrys->setActionEventId("option");
	m_optionentrys->addActionListener(this);
	m_optionentrys->setBackgroundColor(gcn::Color(0,0,0));
	m_optionentrys->setForegroundColor(gcn::Color(255,255,255));

	m_options->add(m_resolution, 220, 70);
	m_resolution->setBackgroundColor(gcn::Color(0,0,0));
	m_resolution->setForegroundColor(gcn::Color(255,255,255));

	m_options->add(m_fullscreen, 220, (70 + m_font->getHeight() * 1));
	m_fullscreen->setBackgroundColor(gcn::Color(0,0,0));
	m_fullscreen->setForegroundColor(gcn::Color(255,255,255));

	m_optionentrys->setSelected(0);
	m_resolution->setSelected(0);
	m_fullscreen->setSelected(0);
	m_options->setVisible(0);
};

void Gui::CleanOptions()
{
	delete m_options;
	m_options = 0;
	delete m_optionentrys;
	m_optionentrys = 0;
	delete m_resolution;
	m_resolution = 0;
	delete m_fullscreen;
	m_fullscreen = 0;
};

void Gui::InitMenu()
{
	m_menu = new gcn::Container();
	m_menu->setDimension(gcn::Rectangle(0, 0, 640, 480));
	m_menu->setOpaque(false);
	m_crown->add(m_menu);
	InitMain();
	InitOptions();
	InitGametypes();
	InitInetchoose();
	InitConnect();
};

void Gui::CleanMenu()
{
	delete m_menu;
	m_menu = 0;
	CleanOptions();
	CleanMain();
	CleanGametypes();
	CleanInetchoose();
	CleanConnect();
};

void Gui::InitGametypes()
{
	m_gametype = new gcn::Container();
	m_gametypeentrys = new SubMenu();

	m_gametypeentrys->addString("VS Player");
	m_gametypeentrys->addString("VS Cpu");
	m_gametypeentrys->addString("Internet");
	m_gametypeentrys->addString("Back");

	m_menu->add(m_gametype);
	m_gametype->setDimension(gcn::Rectangle(0, 0, 640, 480));
	m_gametype->setBaseColor(gcn::Color(0,0,0));
	m_gametype->setOpaque(true);

	m_gametype->add(m_gametypeentrys, 70, 70);
	m_gametypeentrys->setActionEventId("gametype");
	m_gametypeentrys->addActionListener(this);
	m_gametypeentrys->setBackgroundColor(gcn::Color(0,0,0));
	m_gametypeentrys->setForegroundColor(gcn::Color(255,255,255));

	m_gametypeentrys->setSelected(0);
	m_gametype->setVisible(0);
};

void Gui::CleanGametypes()
{
	delete m_gametype;
	m_gametype = 0;
	delete m_gametypeentrys;
	m_gametypeentrys = 0;
};

void Gui::InitInetchoose()
{
	m_inetchoose = new gcn::Container();
	m_inetchooseentrys = new SubMenu();

	m_inetchooseentrys->addString("TC/IP");
	m_inetchooseentrys->addString("Host Game");
	m_inetchooseentrys->addString("Back");

	m_menu->add(m_inetchoose);
	m_inetchoose->setDimension(gcn::Rectangle(0, 0, 640, 480));
	m_inetchoose->setBaseColor(gcn::Color(0,0,0));
	m_inetchoose->setOpaque(true);

	m_inetchoose->add(m_inetchooseentrys, 70, 70);
	m_inetchooseentrys->setActionEventId("inetchoose");
	m_inetchooseentrys->addActionListener(this);
	m_inetchooseentrys->setBackgroundColor(gcn::Color(0,0,0));
	m_inetchooseentrys->setForegroundColor(gcn::Color(255,255,255));

	m_inetchooseentrys->setSelected(0);
	m_inetchoose->setVisible(0);
};

void Gui::CleanInetchoose()
{
	delete m_inetchoose;
	m_inetchoose = 0;
	delete m_inetchooseentrys;
	m_inetchooseentrys = 0;
};

void Gui::InitConnect()
{
	m_connect = new gcn::Container();
	m_connectentrys = new SubMenu();
	m_ip = new gcn::TextField;
	m_port = new gcn::TextField;

	m_connectentrys->addString("IP Adress");
	m_connectentrys->addString("Port");
	m_connectentrys->addString("Connect");
	m_connectentrys->addString("Back");

	m_menu->add(m_connect);
	m_connect->setDimension(gcn::Rectangle(0, 0, 640, 480));
	m_connect->setBaseColor(gcn::Color(0,0,0));
	m_connect->setOpaque(true);

	m_connect->add(m_connectentrys, 70, 70);
	m_connectentrys->setActionEventId("connect");
	m_connectentrys->addActionListener(this);
	m_connectentrys->setBackgroundColor(gcn::Color(0,0,0));
	m_connectentrys->setForegroundColor(gcn::Color(255,255,255));

	m_connect->add(m_ip, 220, 70);
	m_ip->setBackgroundColor(gcn::Color(0,0,0));
	m_ip->setForegroundColor(gcn::Color(255,255,255));
	m_ip->setActionEventId("ip");
	m_ip->addActionListener(this);
	m_ip->setText("000.000.000.000");
	m_ip->adjustSize();
	m_ip->setBorderSize(0);

	m_connect->add(m_port, 220, (70 + m_font->getHeight()));
	m_port->setBackgroundColor(gcn::Color(0,0,0));
	m_port->setForegroundColor(gcn::Color(255,255,255));
	m_port->setActionEventId("port");
	m_port->addActionListener(this);
	m_port->setText("65000");
	m_port->adjustSize();
	m_port->setBorderSize(0);

	m_connectentrys->setSelected(0);
	m_connect->setVisible(0);
};

void Gui::CleanConnect()
{
	delete m_connect;
	m_connect = 0;
	delete m_connectentrys;
	m_connectentrys = 0;
	delete m_ip;
   m_ip = 0;
	delete m_port;
	m_port = 0;
};

void Gui::action(const gcn::ActionEvent& actionEvent)
{
	if (actionEvent.getId() == "main")
	{
		switch (m_mainentrys->getSelected())
		{
			case 0:
				m_main->setVisible(0);
				m_gametype->setVisible(1);
				m_gametypeentrys->requestFocus();
				break;

			case 1:
				m_main->setVisible(0);
				m_options->setVisible(1);
				m_optionentrys->requestFocus();
				break;

			case 2:
				m_modulemanager->SentSignal("End");
				break;

			default:
				break;
		}
	}
	if(actionEvent.getId() == "gametype")
	{
		switch (m_gametypeentrys->getSelected())
		{
			case 0:
				m_config->setValue("Player", 2);
				m_modulemanager->SentSignal("PongStart");
				break;

			case 1:
				m_config->setValue("Player", 1);
				m_modulemanager->SentSignal("PongStart");
				break;

			case 2:
				m_gametype->setVisible(0);
				m_inetchoose->setVisible(1);
				m_inetchooseentrys->requestFocus();
				break;
			case 3:
				m_gametype->setVisible(0);
				m_main->setVisible(1);
				m_mainentrys->requestFocus();
				break;

			default:
				break;
		}
	}
	if(actionEvent.getId() == "inetchoose")
	{
		switch (m_inetchooseentrys->getSelected())
		{
			case 0:
				m_inetchoose->setVisible(0);
				m_connect->setVisible(1);
				m_connectentrys->requestFocus();
				break;
			case 2:
				m_inetchoose->setVisible(0);
				m_main->setVisible(1);
				m_mainentrys->requestFocus();
				break;

			default:
				break;
		}
	}
	if(actionEvent.getId() == "connect")
	{
		switch (m_connectentrys->getSelected())
		{
			case 0:
				m_ip->requestFocus();
				break;
			case 1:
				m_port->requestFocus();
				break;
			case 3:
				m_connect->setVisible(0);
				m_inetchoose->setVisible(1);
				m_inetchooseentrys->requestFocus();
				break;

			default:
				break;
		}
	}
	if(actionEvent.getId() == "ip" || actionEvent.getId() == "port")
	{
		m_connectentrys->requestFocus();
	}

	if (actionEvent.getId() == "option")
	{
		switch (m_optionentrys->getSelected())
		{
			case 0:
				m_resolution->moveSelection(1);
				break;

			case 1:
				m_fullscreen->moveSelection(1);
				break;

			case 2:
				m_options->setVisible(0);
				m_main->setVisible(1);
				m_mainentrys->requestFocus();
				break;

			default:
				break;
		}
	}
};

void Gui::Draw(SDL_Surface* screen)
{
	((gcn::SDLGraphics*) mGraphics)->setTarget(screen);
	draw();
};

void Gui::GetSignal(std::string name)
{
	if(name == "PongStart")
	{
		m_menu->setVisible(0);
		m_gametype->setVisible(0);
		m_ingame->setVisible(1);
		m_ingame->requestFocus();
	} else if(name == "PongEnd"){
		m_ingame->setVisible(0);
		m_menu->setVisible(1);
		m_gametype->setVisible(0);
		m_options->setVisible(0);
		m_main->setVisible(1);
		m_mainentrys->requestFocus();
	};

};
