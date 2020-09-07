#include "Score.h"
#include "Src/Engine/Engine.h"



void Score::Update()
{

}

void Score::Iintialize(Vec2 init_pos)
{
	//メンバ変数初期化
	Position = Vec2(0.0f, 0.0f);
	Scale = Vec2(1.0f, 1.0f);
	Angle = 0.0f;
	Alpha = 255;
	//unsigned char Alpha;

}
void Release()
{

}

void  Score::Draw()
{

	int g_Score = 354;

	const char* number_keys[] =
	{
		"Score00",
		"Score01",
		"Score02",
		"Score03",
		"Score04",
		"Score05",
		"Score06",
		"Score07",
		"Score08",
		"Score09",
	};

	float offset = 120.0f; //数値画像のサイズ
	int digit_count = 0; //行チェックの回数
	int score = g_Score; //チェック用のスコア

	int numbers[6] =
	{
		0, 2, 0, 3, 0, 0
	};

	//名桁の値を割り出すための処理
	//do
	//{
	//	int digit = g_Score % 10;
	//	g_Score /= 10;

		//Engine::DrawTexture(300.0f - (offset * digit_count), 200.0f, number_keys[digit]);
	//	numbers[digit_count] = digit;
	//	digit_count++;
	//} while (g_Score != 0);

	for (int i = 0; i < 6; i++)
	{
		int key_id = numbers[i];
		Engine::DrawTexture(i * 100.0, 200.0f, number_keys[key_id]);
	}
//Engine::DrawTexture(Position.X, Position.Y, "Score00", Alpha, Angle, Scale.X, Scale.Y); 
	//Engine::DrawTexture(Position.X, Position.Y, "Score01", Alpha, Angle, Scale.X, Scale.Y);
	//Engine::DrawTexture(Position.X, Position.Y, "Score02", Alpha, Angle, Scale.X, Scale.Y);
	//Engine::DrawTexture(Position.X, Position.Y, "Score03", Alpha, Angle, Scale.X, Scale.Y);
	//Engine::DrawTexture(Position.X, Position.Y, "Score04", Alpha, Angle, Scale.X, Scale.Y);
	//Engine::DrawTexture(Position.X, Position.Y, "Score05", Alpha, Angle, Scale.X, Scale.Y);
	//Engine::DrawTexture(Position.X, Position.Y, "Score06", Alpha, Angle, Scale.X, Scale.Y);
	//Engine::DrawTexture(Position.X, Position.Y, "Score07", Alpha, Angle, Scale.X, Scale.Y);
	//Engine::DrawTexture(Position.X, Position.Y, "Score08", Alpha, Angle, Scale.X, Scale.Y);
	//Engine::DrawTexture(Position.X, Position.Y, "Score09", Alpha, Angle, Scale.X, Scale.Y);

}
