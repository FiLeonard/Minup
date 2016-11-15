/* minup - yet another pong-like game
 *
 * Copyright (C) 2005 Leonard Fischer (Crimson-Skies@gmx.de)
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

#ifndef NETWORK_H
#define NETWORK_H

#include <SDL.h>
#include <SDL_net.h>
#include <string>

#include "../../engine/eventlistener.h"
#include "../../engine/module.h"

enum Network_Mode {
   UNCONNECTED = 0,
   CONNECTING = 1,
   WAITINGFORCLIENTS = 2,
   CONNECTED = 3
};

enum CLIENT_HOST {
   CLIENT = 0,
   HOST = 1
   };

class Network : public Module
{
   public:
   Network(){};
   ~Network(){}

   bool Load();
   bool Unload();
   bool Update();

   void* AskFor(std::string data);

   void GetSignal(std::string name){};

   void SetIp(std::string ip);
   void SetPort(int port);

   bool HostGame();
   bool AcceptClient();

   bool ConnectToHost();

   void ClientSend();
   void ClientRecv();

   void HostSend();
   void HostRecv();

   private:
   TCPsocket m_sock;
   TCPsocket m_server;

   std::string m_ip;
   int m_port;

   int m_mode;
   int m_modus;

   int m_connected;
};

#endif
