#ifndef ENEMY02_MANAGER_H_
#define ENEMY02_MANAGER_H_

#include "Enemy02.h"

class EnemyManager02
{
public:
	void Initialize();
	void Update();
	void Draw();

	Enemy02* CreateEnemy(Vec2 init_pos);
	Enemy02* GetEnemy(int index);




public:
	Enemy02 Enemies[100];


};




#endif // !ENEMY_MANAGER_H

