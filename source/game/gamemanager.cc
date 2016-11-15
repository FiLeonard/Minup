#include "gamemanager.h"

GameManager::GameManager()
{
   m_config = new Configuration;
   m_fpscontrol = new FPSControl;

   m_video_module = new VideoManager;
   m_gui_module = new Gui;
   m_game_module = new Game;
};

GameManager::~GameManager()
{
   delete m_config;
   delete m_fpscontrol;

   delete m_video_module;
   delete m_gui_module;
   delete m_game_module;
};

void GameManager::Start()
{
   m_running = true;

   m_config->InitConfig("config.xml");

   AddModule("Video", m_video_module);
   AddModule("Gui", m_gui_module);
   AddModule("Game", m_game_module);

   LoadModules();
   StartModules();
   HaltModule("Game");

   m_video_module->AddVideoModule(m_gui_module);
   m_video_module->AddVideoModule(m_game_module);
   m_gui_module->SetVisibility(true);

   m_game_module->SetVisibility(false);

   m_config->AddListener(this);
   m_config->AddListener(m_video_module);
   m_config->AddListener(m_game_module);
   m_config->AddListener(m_gui_module);

   m_video_module->LoadScreen();

   m_fpscontrol->SetLogicFrames(60);
   m_fpscontrol->SetGraphicFrames((int)m_config->GetValue("maxfps", 60));

   while(m_running)
   {
      if(m_fpscontrol->NeedsLogicRefresh())
      {
         m_fpscontrol->StartLogicTimer();
         UpdateModule("Gui");
         UpdateModule("Game");
         UpdateModule("EventManager");
         m_fpscontrol->StopLogicTimer();
      };

      if(m_fpscontrol->NeedsGraphicRefresh())
      {
         m_fpscontrol->StartGraphicTimer();
         UpdateModule("Video");
         m_fpscontrol->StopGraphicTimer();
      };

      m_fpscontrol->Measure();
   };
};


void* GameManager::AskFor(std::string data){};

void GameManager::SentSignal(std::string name)
{
   if(name == "PongStart") {
      m_game_module->SetVisibility(true);
      StartModule("Game");
   }else if(name == "PongEnd") {
      m_game_module->SetVisibility(false);
      HaltModule("Game");
   }else if(name == "End") {
      m_running = false;
   };

   ResourceManager::SentSignal(name);
};
