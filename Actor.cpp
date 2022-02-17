#include "Actor.h"
#include <iostream>
#include "Util.h"
#include "MyEngine.h"

Actor::Actor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
}

Actor::Actor(int NewX, int NewY)
{
	SetActorLocation(NewX, NewY);
}

Actor::~Actor()
{
}

void Actor::Tick()
{
}

void Actor::Render()
{
	//static ¸â¹ö ÇÔ¼ö
	//Util::GotoXY(GetX(), GetY());
	//std::cout << GetShape() << std::endl;
	SDL_SetRenderDrawColor(MyEngine::GetRenderer(), Color.r, Color.g, Color.b, Color.a);
	SDL_Rect Rect = { GetX() * TileSize, GetY() * TileSize, TileSize, TileSize };

	SDL_RenderFillRect(MyEngine::GetRenderer(), &Rect);
}

void Actor::BeginPlay()
{
}

inline void Actor::SetActorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}

inline void Actor::SetShape(char NewShape)
{
	Shape = NewShape;
}
