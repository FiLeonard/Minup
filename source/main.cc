#include "main.h"

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDLNet_Init();
	atexit(SDL_Quit);
	atexit(TTF_Quit);
	atexit(SDLNet_Quit);
	SDL_WM_SetCaption("Minup", NULL);
	SDL_WM_SetIcon(IMG_Load("./res/icon.png"), NULL);
	SDL_EnableUNICODE(1);
	SDL_ShowCursor(0);
	GameManager* Game = new GameManager;
	Game->Start();
	return 0;
};
