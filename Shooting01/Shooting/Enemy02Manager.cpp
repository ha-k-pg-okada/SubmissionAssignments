#include "Enemy02Manager.h"

void EnemyManager02::Initialize()
{
	for (int i = 0; i < 100; i++)
	{
		Enemies[i].Iintialize(Vec2(0.0f, 0.0f));
	}
}


void EnemyManager02::Update()
{
	for (int i = 0; i < 100; i++)
	{
		if (Enemies[i].IsActive == false)
		{
			continue;
		}

		Enemies[i].Update();



	}

}

void EnemyManager02::Draw()
{
	for (int i = 0; i < 100; i++)
	{
		if (Enemies[i].IsActive == false)
		{
			continue;
		}

		Enemies[i].Draw();
	}

}

Enemy02* EnemyManager02::CreateEnemy(Vec2 init_pos)
{
	for (int i = 0; i < 100; i++)
	{
		if (Enemies[i].IsActive == false)
		{
			Enemies[i].Iintialize(init_pos);
			Enemies[i].IsActive = true;

			return &Enemies[i];
		}

	}

	return nullptr;
}

Enemy02* EnemyManager02::GetEnemy(int index)
{
	//�v�f�ԍ��`�F�b�N
	if (index < 0 || index >= 100)
	{
		return nullptr;
	}

	//��A�N�e�B�u�@==�@�Q�[�����ɑ��݂��Ȃ��̂�nullptr�Ƃ��Ĉ���
	if (Enemies[index].IsActive == false)
	{
		return nullptr;
	}

	return &Enemies[index];
}

