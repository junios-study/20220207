#include <iostream>
#include "SDL.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL_Init Error :" << SDL_GetError() << endl;
		return -1;
	}

	SDL_Window* MyWindow = SDL_CreateWindow("First SDL Example", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	SDL_Event MyEvent;

	bool bIsRunning = true;

	while (bIsRunning)
	{
		SDL_PollEvent(&MyEvent);

		switch (MyEvent.type)
		{
		case SDL_QUIT:
			bIsRunning = false;
			break;
		case SDL_KEYDOWN:
			cout << SDL_GetKeyName(MyEvent.key.keysym.sym) << "키 눌러짐" << endl;
			break;
		case SDL_MOUSEBUTTONDOWN:
			cout << (MyEvent.button.button == SDL_BUTTON_LEFT) <<  "마우스 버튼 눌러짐" << endl;
			cout << "(" << MyEvent.button.x << ", " << MyEvent.button.y << ")" << endl;
			break;
		}
	}
	


	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

	return 0;
}