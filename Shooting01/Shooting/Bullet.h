#ifndef BULLET_H
#define BULLET_H

#include "Src/Common/Vec.h"
class Bullet
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

	bool IsActive; //�����t���O

};




#endif // !BULLET_H01

