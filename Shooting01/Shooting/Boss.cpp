#include "Boss.h"
#include "Src/Engine/Engine.h"
#include "Scene.h"

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;


void Boss::Iintialize(Vec2 init_pos)
{
	//ƒƒ“ƒo•Ï”‰Šú‰»
	Position = init_pos;
	Scale = Vec2(1.0f, 1.0f);
	Angle = 0.0f;
	Alpha = 255;
	unsigned char Alpha;

	BossHp = 10;

	IsActive = true;


}

void Boss::Release()
{


}

static int MoveCounter = 0;
static int BossCounter = 0;
static float BossSpeed = 2.0f;

void Boss::Update()
{
	
	if (Position.X == 1000.0f)
	{
		BossCounter++;
	
	}

	
	if (BossCounter >= 10)
	{
		
		Position.X -= BossSpeed;

		if (Position.X <= 500.0f)
		{
			Position.X == 500;
		}
		
	}

	

	

	if (Position.X == 500)
	{
		
		if (MoveCounter >= 150)
		{
			Position.Y -= 2.0f;
		}
		else if (MoveCounter <= 300)
		{
			Position.Y += 2.0f;
		}
		if (MoveCounter >= 300)
		{
			MoveCounter = 0;
		}

		BossCounter = 0;
	
	}

	if (BossHp <= 999)
	{
		MoveCounter++;
	}


	if (BossHp <= 0)
	{
		IsActive = false;
	}



}
void Boss::Draw()
{
	if (IsActive == true)
	{
		Engine::DrawTexture(Position.X, Position.Y, "Boss", Alpha, Angle, Scale.X, Scale.Y);
	}

}