#include "Player.h"
#include "Src/Engine/Engine.h"

void Player::Iintialize(Vec2 init_pos)
{
	//�����o�ϐ�������
	Position = Vec2(0.0f, 0.0f);
	Scale = Vec2(1.0f, 1.0f);
	Angle = 0.0f;
	Alpha = 255;
	Player_Hp = 3;
	//unsigned char Alpha;


}


void Player::Release()
{


}


void Player::Update()
{


	//�㉺�E���ړ�
	float speed = 2.0f;

	if (Position.Y >= 420.0f)
	{	
		Position.Y = 420.0f;
	}


	if (Engine::IsKeyboardKeyHeld(DIK_UPARROW))
	{
		Position.Y -= speed;
	}


	if (Position.Y <= 0.0f)
	{
		Position.Y = 0.0f;
	}

	if (Engine::IsKeyboardKeyHeld(DIK_DOWNARROW))
	{
		Position.Y += speed;
	}



	if (Position.X >= 580.0f)
	{
		
		Position.X = 580.0f;
	}
	if (Engine::IsKeyboardKeyHeld(DIK_LEFTARROW))
	{
		Position.X -= speed;
	}
	
	if (Position.X <= 0.0f)
	{	
		Position.X = 0.0f;
	}
	if (Engine::IsKeyboardKeyHeld(DIK_RIGHTARROW))
	{
		Position.X += speed;
	}
	
}

void Player::Draw()
{
	//�G�摜�̃L�[���[�h���g���悤��

	Engine::DrawTexture(Position.X, Position.Y, "Robot", Alpha, Angle, Scale.X, Scale.Y);


}