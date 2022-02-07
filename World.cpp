#include "World.h"
#include "Actor.h"

World::World()
{
}

World::~World()
{
	for (auto CurrentActor : ActorList)
	{
		delete CurrentActor;
		CurrentActor = nullptr;
	}

	ActorList.clear();
}

void World::SpawnActor(Actor* NewActor)
{
}

void World::DestroyActor(Actor* DestroyActor)
{
}

void World::Tick()
{
}

void World::Render()
{
}

void World::Input()
{
}

void World::BeginPlay()
{
}
