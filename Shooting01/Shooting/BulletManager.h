#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#include "Bullet.h"

class BulletManager
{
public:
	void Initialize();
	void Update();
	void Draw();

	Bullet* CreateBullet(Vec2 init_pos);
	Bullet* GetBullet(int index);


public:
	Bullet Bullets[100];


};




#endif // !BULLET_MANAGER_H
