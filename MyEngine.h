#pragma once

class World;

class MyEngine
{
public:
	MyEngine();
	virtual ~MyEngine();

	void Run();

	void Stop();

	void SpawnActor(class Actor* NewActor);
	void DestroyActor(class Actor* DestroyActor);

protected:
	void BeginPlay();
	void Tick();
	void Render();
	void Input();

protected:
	bool bIsRunning = true;
	World* CurrentWorld;
};

