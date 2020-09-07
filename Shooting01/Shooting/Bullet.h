#ifndef BULLET_H
#define BULLET_H

#include "Src/Common/Vec.h"
class Bullet
{
public:

	void Update(); //更新
	void Draw(); //描画
	void Iintialize(Vec2 init_pos); //初期化
	void Release(); //後処理


public:
	Vec2 Position;
	Vec2 Scale;
	float Angle;
	unsigned char Alpha;

	bool IsActive; //生存フラグ

};




#endif // !BULLET_H01

