#pragma once
#include "SDL.h"
#include <iostream>

class Actor
{
public:
	//�����ε�, ������ �����ε�
	Actor();
	Actor(int NewX, int NewY);

	virtual void Init(int NewX, int NewY);


	virtual ~Actor();

	//���� �����Լ�, �ڽ� Ŭ�������� ������ ������ �ؾ� ��
	//�������̽��� ���� �ϱ� ���ؼ� ����� �մϴ�.
	virtual void Tick() = 0; 
	virtual void Render();
	virtual void BeginPlay();
	
	inline virtual void SetActorLocation(int NewX, int NewY);
	inline virtual void SetShape(char NewShape);
	inline virtual char GetShape() { return Shape; }
	inline virtual int GetX() { return X; }
	inline virtual int GetY() { return Y; }

	bool operator <(Actor& RHS)
	{
		return this->ZOrder < RHS.ZOrder;
	}

	inline static bool Compare(std::shared_ptr<Actor> LHS, std::shared_ptr<Actor> RHS)
	{
		return LHS->ZOrder < RHS->ZOrder;
	}

	bool CanMove(int FutureX, int FutureY);

	void LoadBMP(std::string ImageName);

protected:
	int X;
	int Y;
	char Shape;
	SDL_Color Color;
	SDL_Color ColorKey;
	int TileSize = 64;

	int ZOrder;

	SDL_Surface* Surface;
	SDL_Texture* Texture;


public:
	bool bIsBlock;
};

