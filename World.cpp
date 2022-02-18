#include "World.h"
#include "Actor.h"
#include <algorithm>

World::World()
{
}

World::~World()
{
	//c++ 14 
	//UE4 
	//for (int i = 0; i < ActorList.size(); ++i)
	//{
	//	delete ActorList[i];
	//	ActorList[i] = nullptr;
	//}

	//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	////for (std::vector<Actor*>::iterator iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	//{
	//	delete *iter;
	//	*iter = nullptr;
	//}

	//range for
	for (auto CurrentActor : ActorList)
	{
//		delete CurrentActor;
		CurrentActor = nullptr;
	}

	ActorList.clear();
}

void World::SpawnActor(std::shared_ptr<Actor> NewActor)
{
	ActorList.push_back(NewActor);

	sort(ActorList.begin(), ActorList.end(), Actor::Compare);
}

void World::DestroyActor(std::shared_ptr<Actor> DestroyActor)
{
	//�ڷ� ���� Actor����Ʈ���� ���� ����Ʈ���� ����
	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));
	//�޸𸮿��� ������ ����
	//delete DestroyActor;
	DestroyActor = nullptr;
}

void World::Tick()
{
	DeltaSeconds = SDL_GetTicks64() - LastTick;

	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Tick();
	}
}

void World::Render()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Render();
	}

	LastTick = SDL_GetTicks64();
}


void World::BeginPlay()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->BeginPlay();
	}
}

void World::DestroyWorld()
{
	ActorList.clear();
}
