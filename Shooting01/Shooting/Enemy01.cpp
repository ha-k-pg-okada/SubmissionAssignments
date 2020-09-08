#include "Enemy01.h"
#include "Src/Engine/Engine.h"



void Enemy::Iintialize(Vec2 init_pos)
{
	//メンバ変数初期化
	Position = init_pos;
	Scale = Vec2(1.0f, 1.0f);
	Angle = 0.0f;
	Alpha = 255;
	//unsigned char Alpha;

	IsActive = false;
	

}

void Enemy::Release()
{


}


void Enemy::Update()
{
	float EnemySpeed = 1.0f;

	Position.X -= EnemySpeed;

	if (Position.X <= -80.0f)
	{
		IsActive = false;
	}
}

void Enemy::Draw()
{
	//敵画像のキーワードを使うように

		Engine::DrawTexture(Position.X, Position.Y, "Enemy", Alpha, Angle, Scale.X, Scale.Y);
	

}