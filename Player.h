#pragma once
#include "Actor.h"
#include "SDL.h"

class Player : public Actor
{
public:
	Player();
	Player(int NewX, int NewY, std::string ImageName);
	virtual ~Player();

	virtual void Tick() override;

	virtual void Render() override;
};

