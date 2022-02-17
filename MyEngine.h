#pragma once
#include <string>
#include "SDL.h"
#include <memory>

class World;

class MyEngine
{
public:
	//MyEngine();
	MyEngine(std::string Title, std::string LevelName, int Width, int Height);
	virtual ~MyEngine();

	void Init(std::string Title, int Width, int Height);
	void Term();

	void Run();

	void Stop();

	void SpawnActor(std::shared_ptr<class Actor> NewActor);
	void DestroyActor(std::shared_ptr<class Actor> DestroyActor);

	void LoadLevel(std::string LoadMapName);
	void SaveLevel(std::string SaveMapName);

protected:
	void BeginPlay();
	void Tick();
	void Render();
	void Input();

protected:
	bool bIsRunning = true;
	std::unique_ptr<World> CurrentWorld;

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;
};

