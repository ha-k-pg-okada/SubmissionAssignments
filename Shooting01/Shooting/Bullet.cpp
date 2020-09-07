#include "Bullet.h"
#include "Src/Engine/Engine.h"

void Bullet::Iintialize(Vec2 init_pos)
{

	//�����o�ϐ�������
	Position = Vec2(init_pos);
	Scale = Vec2(1.0f, 1.0f);
	Angle = 0.0f;
	Alpha = 255;
	//unsigned char Alpha;


}

void Bullet::Release()
{


}


void Bullet::Update()
{
	float Bulletspeed = 4.0f;

	Position.X += Bulletspeed;

	if (Position.X >= 1000.0f)
	{
		IsActive = false;
	}


}

void Bullet::Draw()
{
	//�G�摜�̃L�[���[�h���g���悤��

	Engine::DrawTexture(Position.X, Position.Y, "Bullet", Alpha, Angle, Scale.X, Scale.Y);


}