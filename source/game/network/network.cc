#include "network.h"

void Network::SetIp(std::string ip)
{
   m_ip = ip;
};

void Network::SetPort(int port)
{
   m_port = port;
};

bool Network::HostGame()
{
   m_modus = HOST;
   m_mode = WAITINGFORCLIENTS;
   IPaddress tmp;
   SDLNet_ResolveHost(&tmp,"localhost" ,m_port);
   m_server = SDLNet_TCP_Open(&tmp);
   if(!m_server)
   {
      printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
      m_mode = UNCONNECTED;
      return false;
   } else {
      return true;
   };
};

bool Network::AcceptClient()
{
   m_sock = SDLNet_TCP_Accept(m_server);
   if(!m_sock)
   {
      printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
      m_mode = WAITINGFORCLIENTS;
      return 0;
   } else {
      m_mode = CONNECTED;
      return 1;
   };
}

bool Network::ConnectToHost()
{
   m_mode = CLIENT;
   IPaddress tmp;
   SDLNet_ResolveHost(&tmp,m_ip.c_str() ,m_port);
   m_sock = SDLNet_TCP_Open(&tmp);
   if(!m_sock)
   {
      printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
      m_mode = CONNECTING;
      return 0;
   } else {
      m_mode = CONNECTED;
      return m_connected;
   };
};

