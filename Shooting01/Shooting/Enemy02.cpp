#include "Enemy02.h"
#include "Src/Engine/Engine.h"

void Enemy02::Iintialize(Vec2 init_pos)
{
	//�����o�ϐ�������
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


void Enemy02::Update()
{
	float EnemySpeed = 1.0f;

	Position.X -= EnemySpeed;

	if (Position.X <= -80.0f)
	{
		IsActive = false;
	}
}

void Enemy02::Draw()
{
	//�G�摜�̃L�[���[�h���g���悤��

	Engine::DrawTexture(Position.X, Position.Y, "Enemy", Alpha, Angle, Scale.X, Scale.Y);


}