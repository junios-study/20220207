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

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	if (MyRenderer == nullptr)
	{
		cout << "can't Create renderer :" << SDL_GetError() << endl;
		return -1;
	}

	SDL_Event MyEvent;

	bool bIsRunning = true;

	while (bIsRunning)
	{
		//Input
		SDL_PollEvent(&MyEvent);

		switch (MyEvent.type)
		{
		case SDL_QUIT:
			bIsRunning = false;
			break;
		case SDL_KEYDOWN:
			cout << SDL_GetKeyName(MyEvent.key.keysym.sym) << "키 눌러짐" << endl;
			switch (MyEvent.key.keysym.sym)
			{
			case SDLK_q:
				bIsRunning = false;
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			cout << (MyEvent.button.button == SDL_BUTTON_LEFT) <<  "마우스 버튼 눌러짐" << endl;
			cout << "(" << MyEvent.button.x << ", " << MyEvent.button.y << ")" << endl;
			break;
		}

		//그릴 리스트 준비
		//PreRender(그릴 준비, 그릴 물체 배치)
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderClear(MyRenderer);

		//빨간색 선 그리기
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0, 0, 0);
		SDL_RenderDrawLine(MyRenderer, 100, 100, 200, 200);


		//GPU야 그려라
		//Render
		SDL_RenderPresent(MyRenderer);
	}

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

	return 0;
}