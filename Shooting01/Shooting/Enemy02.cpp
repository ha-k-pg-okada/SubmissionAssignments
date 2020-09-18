#include "Enemy02.h"
#include "Src/Engine/Engine.h"

void Enemy02::Iintialize(Vec2 init_pos)
{
	//メンバ変数初期化
	Position = init_pos;
	Scale = Vec2(1.0f, 1.0f);
	Angle = 0.0f;
	Alpha = 255;
	//unsigned char Alpha;

	IsActive = false;


}

void Enemy02::Release()
{


}

static int Counter = 0;

void Enemy02::Update()
{
	float EnemySpeed = 1.0f;
	
	//Position.X -= EnemySpeed;
	Counter++;
	
		

	if (Counter <= 100)
	{
		Position.X -= 2.0f;
		Position.Y += EnemySpeed;
	
	}

	if (Counter >= 100)
	{
		Position.X -= 2.0f;
		Position.Y -= EnemySpeed;
		
	}

	if (Counter == 200)
	{
		Counter = 0;
	}

	//X = -50.0になると消える
	if (Position.X <= -50.0f)
	{
		IsActive = false;
	}
}

void Enemy02::Draw()
{
	//敵画像のキーワードを使うように

	Engine::DrawTexture(Position.X, Position.Y, "Enemy02", Alpha, Angle, 0.9f, 0.8f );


}