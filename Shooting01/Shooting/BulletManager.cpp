#include "BulletManager.h"

void BulletManager::Initialize()
{
	for (int i = 0; i < 100; i++)
	{
		Bullets[i].Iintialize(Vec2(0.0f, 0.0f));
	}
}


void BulletManager::Update()
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

void BulletManager::Draw()
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

Bullet* BulletManager::CreateBullet(Vec2 init_pos)
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

Bullet* BulletManager::GetBullet(int index)
{
	//要素番号チェック
	if (index < 0 || index >= 100)
	{
		return nullptr;
	}

	//非アクティブ　==　ゲーム中に存在しないのでnullptrとして扱う
	if (Bullets[index].IsActive == false)
	{
		return nullptr;
	}

	return &Bullets[index];
}