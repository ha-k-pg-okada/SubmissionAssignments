#include "Boss.h"
#include "Src/Engine/Engine.h"
#include "Scene.h"

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

static float BossSpeed = 2.0f;

void Boss::Iintialize(Vec2 init_pos)
{
	//ƒƒ“ƒo•Ï”‰Šú‰»
	Position = init_pos;
	Scale = Vec2(1.0f, 1.0f);
	Angle = 0.0f;
	Alpha = 255;
	unsigned char Alpha;
	
	BossHp = 30;
	
	IsActive = true;
	BossSpeed = 2.0f;


}

void Boss::Release()
{


}




static float Speed = 2.0f;
static int BossCounter = 0;

void Boss::Update()
{
	
		BossCounter++;
	
	
		
	
	

	//“oê‚ÌŽžŠÔ
	if (BossCounter >= 1200)
	{
		
		Position.X -= BossSpeed;

		if (Position.X <= 500.0f)
		{
		  
			BossSpeed = 0.0f;
		}
		
	}

	

	
//ã‰º‚Ìˆ—
	if (Position.X <= 500.0f)
	{
		//BossSpeed = 2.0f;
		Position.Y -= Speed;
		
			if (Position.Y <= 0.0f)
			{
				Speed *= -1.0f;
			}
			if (Position.Y >= 350.0f)
			{
				Speed *= -1.0f;
			}
			BossCounter = 0;
	
	}



	if (BossHp <= 0)
	{
		IsActive = false;
		
	}

	if (BossHp == 10)
	{
		IsActive = true;
	}

}
void Boss::Draw()
{
	if (IsActive == true)
	{
		Engine::DrawTexture(Position.X, Position.Y, "Boss", Alpha, Angle, Scale.X, Scale.Y);

	}
	

}