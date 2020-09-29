#ifndef BULLET_MANAGER02_H
#define BULLET_MANAGER02_H

#include "Bullet02.h"

class BulletManager02
{
public:
	void Initialize();
	void Update();
	void Draw();

	Bullet02* CreateBullet(Vec2 init_pos);
	Bullet02* GetBullet(int index);


public:
	Bullet02 Bullets[100];


};




#endif // !BULLET_MANAGER02_H
