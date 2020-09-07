#ifndef SCORE_H
#define SCORE_H

#include "Src/Common/Vec.h"

class Score
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


};



#endif // !SCORE_H
