#pragma once
#include <vector>
#include "SDL.h"
#include <memory>

class Actor;

class World
{
public:
	World();
	virtual ~World();

	void SpawnActor(std::shared_ptr<Actor> NewActor);
	void DestroyActor(std::shared_ptr<Actor> DestroyActor);

	void Tick();
	void Render();
	void BeginPlay();

	const std::vector<std::shared_ptr<Actor>>& GetActorList() { return ActorList; }


protected:
	std::vector<std::shared_ptr<Actor>> ActorList;

};

