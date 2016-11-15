#include "resourcemanager.h"

void ResourceManager::AddModule(std::string name, Module* module)
{
   ModuleHolder* ptr = new ModuleHolder;
   m_modules[name] = ptr;
   ptr->m_module = module;
   ptr->m_state = UNLOADED;
   ptr->m_module->SetManager(this);
};

void ResourceManager::RemoveModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   {
      delete iter->second;
      m_modules.erase(iter);
   };
};

void ResourceManager::StartModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   iter->second->m_state = RUNNING;
};

void ResourceManager::StartModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   iter->second->m_state = RUNNING;
};

void ResourceManager::HaltModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   iter->second->m_state = LOADED;
};

void ResourceManager::HaltModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   if(iter->second->m_state == RUNNING)
   iter->second->m_state = LOADED;
};

bool ResourceManager::LoadModule(std::string name)
{

   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end() && iter->second->m_state == UNLOADED)
   {
      if(iter->second->m_module->Load())
      {
         iter->second->m_state = LOADED;
         return 1;
      } else
      return 0;
   };
   return 0;
};

void ResourceManager::LoadModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   {
      if(iter->second->m_state == UNLOADED)
      {
         iter->second->m_module->Load();
         iter->second->m_state = LOADED;
      };
   };
};

bool ResourceManager::UnloadModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end() && iter->second->m_state == LOADED)
   {
      if(iter->second->m_module->Unload())
      {
         iter->second->m_state = UNLOADED;
         return 1;
      } else
      return 0;
   };
   return 0;
};

void ResourceManager::UnloadModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   {
      if(iter->second->m_state == LOADED)
      {
         iter->second->m_module->Unload();
         iter->second->m_state = UNLOADED;
      };
   };
};

int ResourceManager::GetModuleState(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   return iter->second->m_state;
   else
   return (-1);
};

bool ResourceManager::UpdateModule(std::string name)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end() && iter->second->m_state == RUNNING)
   return iter->second->m_module->Update();
   else
   return 0;
};

void ResourceManager::UpdateModules()
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   if(iter->second->m_state == RUNNING)
   iter->second->m_module->Update();
};

void* ResourceManager::AskFor(std::string name, std::string data)
{
   ModuleIter iter = m_modules.find(name);
   if(iter != m_modules.end())
   return iter->second->m_module->AskFor(data);
   else
   return 0;
};

void ResourceManager::SentSignal(std::string name)
{
   for(ModuleIter iter = m_modules.begin();iter != m_modules.end();iter++)
   iter->second->m_module->GetSignal(name);
};


