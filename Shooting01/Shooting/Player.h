#ifndef PLAYER_H
#define PLAYER_H

#include "Src/Common/Vec.h"
class Player
{
public:

	void Update(); //�X�V
	void Draw(); //�`��
	void Iintialize(Vec2 init_pos); //������
	void Release(); //�㏈��

	Player* CreatePlayer(Vec2 init_pos);
	Player* GetPlayer(int index);

public:
	Vec2 Position;
	Vec2 Scale;
	float Angle;
	unsigned char Alpha;
	int Player_Hp = 3;

};




#endif // !PLAYER_H

