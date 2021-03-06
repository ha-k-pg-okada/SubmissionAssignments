#ifndef PLAYER_H
#define PLAYER_H

#include "Src/Common/Vec.h"
class Player
{
public:

	void Update(); //更新
	void Draw(); //描画
	void Iintialize(Vec2 init_pos); //初期化
	void Release(); //後処理

	Player* CreatePlayer(Vec2 init_pos);
	Player* GetPlayer(int index);

public:
	Vec2 Position;
	Vec2 Scale;
	float Angle;
	unsigned char Alpha;

	bool IsActive; //生存フラグ

	int Player_Hp = 3;

};




#endif // !PLAYER_H

