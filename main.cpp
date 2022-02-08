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

	SDL_Window* MyWindow = SDL_CreateWindow("First SDL Example", 100, 100, 800, 600, SDL_WINDOW_VULKAN);

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
			cout << (MyEvent.button.button == SDL_BUTTON_LEFT) << "마우스 버튼 눌러짐" << endl;
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

		//녹색 사각형 그리기
		SDL_SetRenderDrawColor(MyRenderer, 0x00, 0xff, 0, 0);
		SDL_Rect MyRect = { 100, 100, 200, 200 };
		SDL_RenderDrawRect(MyRenderer, &MyRect);

		//파란색 채워진 사각형 그리기
		SDL_SetRenderDrawColor(MyRenderer, 0x00, 0x0, 0xff, 0);
		SDL_Rect MyRect2 = { 300, 200, 100, 100 };
		SDL_RenderFillRect(MyRenderer, &MyRect2);

		//노란색 원 그리기
		int Radius = 50;
		int PositionX = 350;
		int PositionY = 350;
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0x00, 0);
		int OldX = sin(3.14f / 180.0f * 0.0f) * Radius;
		int OldY = cos(3.14f / 180.0f * 0.0f) * Radius;
		for (int Angle = 1; Angle < 360; ++Angle)
		{
			int X1 = OldX;
			int Y1 = OldY;
			int X2 = sin(3.14f / 180.0f * Angle) * Radius;
			int Y2 = cos(3.14f / 180.0f * Angle) * Radius;

			SDL_RenderDrawLine(MyRenderer, X1 + PositionX,
				Y1 + PositionY,
				X2 + PositionX,
				Y2 + PositionY
			);
			OldX = X2;
			OldY = Y2;
		}



		//GPU야 그려라
		//Render
		SDL_RenderPresent(MyRenderer);
	}

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

	return 0;
}