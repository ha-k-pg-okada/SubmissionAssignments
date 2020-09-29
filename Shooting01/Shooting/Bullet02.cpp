#include "Bullet02.h"
#include "Src/Engine/Engine.h"

void Bullet02::Iintialize(Vec2 init_pos)
{

	//メンバ変数初期化
	Position = Vec2(init_pos);
	Scale = Vec2(1.0f, 1.0f);
	Angle = 0.0f;
	Alpha = 255;
	//unsigned char Alpha;


}

void Bullet02::Release()
{


}


void Bullet02::Update()
{
	float Bulletspeed = 4.0f;

	Position.X -= Bulletspeed;

	if (Position.X <= -10.0f)
	{
		IsActive = false;
	}


}

void Bullet02::Draw()
{
	//敵画像のキーワードを使うように

	Engine::DrawTexture(Position.X, Position.Y, "Bullet02", Alpha, Angle, Scale.X, Scale.Y);


}