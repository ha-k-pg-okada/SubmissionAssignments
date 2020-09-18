#include "Boss.h"
#include "Src/Engine/Engine.h"

void Boss::Iintialize(Vec2 init_pos)
{
	//ƒƒ“ƒo•Ï”‰Šú‰»
	Position = init_pos;
	Scale = Vec2(1.0f, 1.0f);
	Angle = 0.0f;
	Alpha = 255;
	unsigned char Alpha;

	BossHp = 100;

	IsActive = true;


}

void Boss::Release()
{


}

static int BossCounter = 0;
static float BossSpeed = 2.0f;

void Boss::Update()
{
	BossCounter++;
	
	
	if (BossCounter >= 2000)
	{
		if (Position.X <= 500.0f)
		{
			Position.X = 500.0f;
		}

		Position.X -= BossSpeed;
	}
	
	BossCounter == 0;

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