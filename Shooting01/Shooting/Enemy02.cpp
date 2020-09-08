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

static int Counter = 0;

void Enemy02::Update()
{
	float EnemySpeed = 1.0f;
	

	Counter++;
	
		

	if (Counter <= 40)
	{
		//Position.X -= EnemySpeed;
		Position.Y += EnemySpeed;
		
	}

	if (Counter >= 40)
	{
		//Position.X -= EnemySpeed;
		Position.Y -= EnemySpeed;
		
	}

	if (Counter == 80)
	{
		Counter = 0;
	}

	//X = -80.0�ɂȂ�Ə�����
	if (Position.X <= -80.0f)
	{
		IsActive = false;
	}
}

void Enemy02::Draw()
{
	//�G�摜�̃L�[���[�h���g���悤��

	Engine::DrawTexture(Position.X, Position.Y, "Enemy02", Alpha, Angle, 0.9f, 0.8f );


}