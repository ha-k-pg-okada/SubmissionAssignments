#ifndef ENEMY02_H
#define ENEMY02_H

#include "Src/Common/Vec.h"
class Enemy02
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




#endif // !ENEMY02_H

