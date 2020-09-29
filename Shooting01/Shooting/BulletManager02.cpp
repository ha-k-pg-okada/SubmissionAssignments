#include "BulletManager02.h"

void BulletManager02::Initialize()
{
	for (int i = 0; i < 100; i++)
	{
		Bullets[i].Iintialize(Vec2(0.0f, 0.0f));
	}
}


void BulletManager02::Update()
{
	for (int i = 0; i < 100; i++)
	{
		if (Bullets[i].IsActive == false)
		{
			continue;
		}

		Bullets[i].Update();
	}

}

void BulletManager02::Draw()
{
	for (int i = 0; i < 100; i++)
	{
		if (Bullets[i].IsActive == false)
		{
			continue;
		}

		Bullets[i].Draw();
	}

}

Bullet02* BulletManager02::CreateBullet(Vec2 init_pos)
{
	for (int i = 0; i < 100; i++)
	{
		if (Bullets[i].IsActive == false)
		{
			Bullets[i].Iintialize(init_pos);
			Bullets[i].IsActive = true;

			return &Bullets[i];
		}

	}

	return nullptr;
}

Bullet02* BulletManager02::GetBullet(int index)
{
	//�v�f�ԍ��`�F�b�N
	if (index < 0 || index >= 100)
	{
		return nullptr;
	}

	//��A�N�e�B�u�@==�@�Q�[�����ɑ��݂��Ȃ��̂�nullptr�Ƃ��Ĉ���
	if (Bullets[index].IsActive == false)
	{
		return nullptr;
	}

	return &Bullets[index];
}