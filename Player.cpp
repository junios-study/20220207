#include "Player.h"
#include "MyEngine.h"

Player::Player()
{
	X = 0;
	Y = 0;
	Shape = 'P';
	Color.r = 0xff;
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;
}

Player::Player(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = 'P';
	Color.r = 0xff;
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;
}

Player::~Player()
{
}

void Player::Tick()
{
	if (MyEngine::GetEvent().type == SDL_KEYDOWN)
	{
		switch (MyEngine::GetEvent().key.keysym.sym)
		{
		case SDLK_LEFT:
			X--;
			break;
		case SDLK_RIGHT:
			X++;
			break;
		case SDLK_UP:
			Y--;
			break;
		case SDLK_DOWN:
			Y++;
			break;
		}
	}
}
