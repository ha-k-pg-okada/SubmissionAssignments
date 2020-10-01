#ifndef BOSS_H
#define BOSS_H

#include "Src/Common/Vec.h"
class Boss
{
public:

	void Update(); //�X�V
	void Draw(); //�`��
	void Iintialize(Vec2 init_pos); //������
	void Release(); //�㏈��


public:
	Vec2 Position;
	Vec2 Scale;
	float Angle;
	unsigned char Alpha;

	int BossHp = 30;
	

	bool IsActive; //�����t���O

};




#endif // !ENEMY01
