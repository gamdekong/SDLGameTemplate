
//#include <iostream>
//#include <Windows.h>

//#include "Game.h"
//#include "vld.h"
#include <SDL.h>
//#define main main
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//Uint32 frameStart, frameTime;
	//Uint32 frames = 0;
	//std::cout << SDL_MAIN_AVAILABLE << std::endl;
	// show console
	//AllocConsole();
	//freopen("CON", "w", stdout);

	//TheGame::Instance().init("SDLEngine v0.25", 100, 100, 800, 600, false);

	//while (TheGame::Instance().isRunning())
	//{
	//	frameStart = SDL_GetTicks();

	//	TheGame::Instance().handleEvents();
	//	TheGame::Instance().update();
	//	TheGame::Instance().render();

	//	frameTime = SDL_GetTicks() - frameStart;
	//	if (frameTime < DELAY_TIME)
	//	{
	//		SDL_Delay(int(DELAY_TIME - frameTime));
	//	}

	//	// delta time
	//	auto deltaTime = float(SDL_GetTicks() - frameStart) / 1000.0f;
	//	TheGame::Instance().setDeltaTime(deltaTime);

	//	frames++;
	//	TheGame::Instance().setFrames(frames);

	//}

	//TheGame::Instance().clean();
	//_CrtDumpMemoryLeaks();
	return 0;
}

