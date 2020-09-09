#ifndef ENEMY_MANAGER_H_
#define ENEMY_MANAGER_H_

#include "Enemy01.h"
#include "Enemy02.h"

class EnemyManager
{
public:
	void Initialize();
	void Update();
	void Draw();
	
	Enemy* CreateEnemy(Vec2 init_pos);
	Enemy* GetEnemy(int index);




public:
	 Enemy Enemies[200];
	
	
};




#endif // !ENEMY_MANAGER_H

