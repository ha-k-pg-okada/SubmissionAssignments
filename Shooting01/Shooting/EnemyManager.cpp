#include "EnemyManager.h"

void EnemyManager::Initialize()
{
	for (int i = 0; i < 200; i++)
	{
		Enemies[i].Iintialize(Vec2(0.0f, 0.0f));
	}
}


void EnemyManager::Update()
{
	for (int i = 0; i < 200; i++)
	{
		if (Enemies[i].IsActive == false)
		{
			continue;
		}

		Enemies[i].Update();

		

	}

}

void EnemyManager::Draw()
{
	for (int i = 0; i < 200; i++)
	{
		if (Enemies[i].IsActive == false)
		{
			continue;
		}

		Enemies[i].Draw();
	}

}

Enemy* EnemyManager::CreateEnemy(Vec2 init_pos)
{
	for (int i = 0; i < 200; i++)
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

Enemy* EnemyManager::GetEnemy(int index)
{
	//�v�f�ԍ��`�F�b�N
	if (index < 0 || index >= 200)
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

