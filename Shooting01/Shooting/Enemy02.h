#ifndef ENEMY02_H
#define ENEMY02_H

#include "Src/Common/Vec.h"
class Enemy02
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




#endif // !ENEMY02_H

