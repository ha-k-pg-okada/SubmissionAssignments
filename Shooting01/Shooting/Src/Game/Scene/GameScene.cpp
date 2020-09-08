#include "../../Engine/Engine.h"
#include "Scene.h"
#include "GameScene.h"
#include "../../../EnemyManager.h"
#include "../../../Player.h"
#include "../../../Bullet.h"
#include "../../../BulletManager.h"
#include "../../../Score.h"
//#include "../../../Enemy01.h"
#include "../../../Enemy02.h"
#include "../../../Enemy02Manager.h"

void InitGameScene();
void RunGameScene();
void FinishGameScene();
void DrawGameScene();

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

Vec2 g_RobotPosition = Vec2(0.0f, 0.0f);
Vec2 g_EnemyPosition = Vec2(0.0f, 0.0f);
Vec2 g_BulletPosition = Vec2(0.0f, 0.0f);

bool g_IsCollision = false;
EnemyManager g_EnemyManager;
Player g_Player;
BulletManager g_BulletManager;
Score g_Score;
Enemy g_Enemy;
Enemy02 g_Enemy02;
EnemyManager02 g_EnemyManager02;

//�w�i01
static float background01 = 0.0f;
//�w�i02
static float background02 = 1000.0f;

//Enemy�̃J�E���^�[
static int EnemyCounter = 0;

//Enemy02�̃J�E���^�[
static int EnemyCounter02 = 0;

//���������Enemy��X���W��Y���W
static float Enemy_X = 700.0f;
static float Enemy_Y = 0;

//���������Enemy02��X���W��Y���W
static float Enemy02_X = 700.0f;
static float Enemy02_Y = 0;

struct Rect
{
	float Left;
	float Right;
	float Top;
	float Bottom;


};

/*
bool OnCollisionCircleAndCircle(Vec2 pos_a, float radius_a, Vec2 pos_b, float radius_b)
{
	Vec2 length = Vec2(pos_a.X - pos_b.X, pos_a.Y - pos_b.Y);
	length.X *= length.X;
	length.Y *= length.Y;

	float distance = sqrtf(length.X + length.Y);

	if ((radius_a + radius_b) < distance)
	{
		return true;
	}

	return false;
}
*/


/*
	���� =>
		��`�����

	�߂�l =>
		������̌���
			�������Ă� => true
			�������ĂȂ� => false
*/


bool OnCollisionRectAndRect(Rect* object01, Rect* object02)
{


		// �T�C�Y
		Vec2 size[] =
		{
			Vec2(object01->Right - object01->Left, object01->Bottom - object01->Top),
			Vec2(object02->Right - object02->Left, object02->Bottom - object02->Top),
		};

		// ���S���W
		Vec2 center_pos[] =
		{
			Vec2(object01->Left + size[0].X / 2.0f, object01->Top + size[0].Y / 2.0f),
			Vec2(object02->Left + size[1].X / 2.0f, object02->Top + size[1].Y / 2.0f),
		};

		// Robot��Enemy��̋�`�̋���
		Vec2 distance = Vec2(
			center_pos[0].X - center_pos[1].X,
			center_pos[0].Y - center_pos[1].Y);

		
		
		if (distance.X < 0.0f)
		{
			distance.X *= -1.0f;
		}

		if (distance.Y < 0.0f)
		{
			distance.Y *= -1.0f;
		}




		// Robot��Enemy�̃T�C�Y�̘a
		Vec2 size_sum = Vec2(
			(size[0].X + size[1].X ) / 2.0f,
			(size[0].Y + size[1].Y ) / 2.0f);


		// ����
		/*
			��`�Ԃ̋�������`�T�C�Y�̍��v������������Γ�����
		*/
		if (distance.X < size_sum.X &&
			distance.Y < size_sum.Y)
		{
			// �������Ă�
			return true;
		}

		// �������Ă��Ȃ�
		return false;

}




/*
bool OncollisionRectAndRect(Rect* object01, Rect* object02)
{
	//�T�C�Y
	Vec2 size[] =
	{
		Vec2(object01->Right - object01->Left, object01->Bottom - object01->Top),
		Vec2(object02->Right - object02->Left, object02->Bottom - object02->Top),
	};

	//���S���W
	Vec2 center_pos[] =
	{
		Vec2(object01->Left + size[0].X / 2.0f, object01->Top + size[0].Y / 2.0f),
		Vec2(object02->Left + size[1].X / 2.0f, object02->Top + size[1].Y / 2.0f),
	};

	//����
	Vec2 distance = Vec2(center_pos[0].X - center_pos[1].X, center_pos[0].Y - center_pos[1].Y);

	if (distance.X < 0.0f)
	{
		distance.X *= -1.0f;
	}

	if (distance.Y < 0.0f)
	{
		distance.Y *= -1.0f;
	}
	
	//�T�C�Y�̘a
	Vec2 size_sum = Vec2(
		(size[0].X + size[1].X) / 2.0f, 
		(size[0].Y + size[1].Y) / 2.0f);
		

	//����
	//��`�Ԃ̋�������`�T�C�Y�̍��v������������Γ�����
	if (distance.X < size_sum.X && distance.Y < size_sum.Y)
	{
		//�������Ă���
		return true;
	}
	//�������Ă��Ȃ�
	return false;
	

	//Robot��Enemy�̔��a
	//float Robot_radius = size[0].Y / 2;
	//float Enemy_radius = size[1].Y / 2;

	//Robot��Enemy�̋���
	//float a = center_pos[0].X - center_pos[1].X;
	//float b = center_pos[0].Y - center_pos[1].Y;
	//float c = sqrt(a * a + b * b);

	//if (c <= Robot_radius + Enemy_radius)
	//{
		//�������Ă���
	//	return true;
	//}

	//�������Ă��Ȃ�
	//return false;

}
*/

void InitGameScene()
{

	g_EnemyManager.Initialize();
	g_Player.Iintialize(Vec2(0.0f, 0.0f));
	g_BulletManager.Initialize();
	//g_Enemy02.Iintialize(Vec2(0.0f, 0.0f));
	g_EnemyManager02.Initialize();
 	
	g_BulletManager.CreateBullet(Vec2(100.0f, 200.0f));

	Engine::LoadTexture("Robot", "Res/Robot_idle 1.PNG");
	Engine::LoadTexture("Enemy", "Res/EA1.PNG");
	Engine::LoadTexture("Enemy02", "Res/EA2 1.png");
	Engine::LoadTexture("Bullet", "Res/Bullet1.PNG");
	Engine::LoadTexture("Heart02", "Res/Heart02.png");
	Engine::LoadTexture("building", "Res/building2.png");
	

	Engine::LoadTexture("Score00", "Res/numbers/number00.png");
	Engine::LoadTexture("Score01", "Res/numbers/number01.png");
	Engine::LoadTexture("Score02", "Res/numbers/number02.png");
	Engine::LoadTexture("Score03", "Res/numbers/number03.png");
	Engine::LoadTexture("Score04", "Res/numbers/number04.png");
	Engine::LoadTexture("Score05", "Res/numbers/number05.png");
	Engine::LoadTexture("Score06", "Res/numbers/number06.png");
	Engine::LoadTexture("Score07", "Res/numbers/number07.png");
	Engine::LoadTexture("Score08", "Res/numbers/number08.png");
	Engine::LoadTexture("Score09", "Res/numbers/number09.png");




	g_CurrentSceneStep = SceneStep::Run;
	
}

void RunGameScene()
{

	//�e�۔��˃L�[
	if (Engine::IsKeyboardKeyPushed(DIK_5))
	{
		g_BulletManager.CreateBullet(Vec2(g_Player.Position.X + 30.0f, g_Player.Position.Y + 20.0f));

	}

	g_Player.Update();
	g_BulletManager.Update();
	g_Score.Update();
	g_EnemyManager.Update();
	//g_Enemy02.Update();
	g_EnemyManager02.Update();

	/*
	Texture* texture[2] =
	{
		Engine::GetTexture("Robot"),
		Engine::GetTexture("Enemy"),
		//Engine::GetTexture("Bullet"),
	};
	Vec2 tex_size[2];

	for (int i = 0; i < 2; i++)
	{
		if (texture[i] != nullptr)
		{
			tex_size[i].X = texture[i]->Width;
			tex_size[i].Y = texture[i]->Height;
		}
	}
	Rect rect[2] =
	{
		//Robot�̋�`
		{g_RobotPosition.X, g_RobotPosition.X + tex_size[0].X, g_RobotPosition.Y, g_RobotPosition.Y + tex_size[0].Y},
		{g_EnemyPosition.X, g_EnemyPosition.X + tex_size[1].X, g_EnemyPosition.Y, g_EnemyPosition.Y + tex_size[1].Y},
	};

	if (OnCollisionRectAndRect(&rect[0], &rect[1]) == true)
	{
		g_IsCollision = true;
	}
	else
	{
		g_IsCollision = false;
	}

	if (texture != nullptr)
	{
		int width = texture[0]->Width;
		int height = texture[1]->Height;

	}

//	DrawGameScene();

*/

		Texture* texture[3] =
		{
			Engine::GetTexture("Robot"),
			Engine::GetTexture("Enemy"),
			Engine::GetTexture("Bullet"),
		};
		Vec2 tex_size[3];

		// �e�N�X�`���T�C�Y�̎擾
		for (int i = 0; i < 3; i++)
		{
			if (texture[i] != nullptr)
			{
				tex_size[i].X = texture[i]->Width;
				tex_size[i].Y = texture[i]->Height;
			}

		}

		for (int i = 0; i < 100; i++) 
		{
			for (int j = 0; j < 100; j++)
			{

			
				if (g_EnemyManager.Enemies[i].IsActive == true)
				{

					Rect rect[3] =
					{
						// Robot�̋�`
						{
							g_Player.Position.X,
							g_Player.Position.X + tex_size[0].X,
							g_Player.Position.Y,
							g_Player.Position.Y + tex_size[0].Y
						},


						// �G�̋�`
						 {

						g_EnemyManager.Enemies[i].Position.X,
						g_EnemyManager.Enemies[i].Position.X + tex_size[1].X,
						g_EnemyManager.Enemies[i].Position.Y,
						g_EnemyManager.Enemies[i].Position.Y + tex_size[1].Y

						 },

						//�e�ۂ̋�`
						{
						g_BulletManager.Bullets[j].Position.X,
						g_BulletManager.Bullets[j].Position.X + tex_size[2].X,
						g_BulletManager.Bullets[j].Position.Y,
						g_BulletManager.Bullets[j].Position.Y + tex_size[2].Y

						},



					};

					
					if (OnCollisionRectAndRect(&rect[0], &rect[1]))
					{
						g_EnemyManager.Enemies[i].IsActive = false;
						g_Player.Player_Hp--;
					}
					if (OnCollisionRectAndRect(&rect[1], &rect[2]))
					{
						g_BulletManager.Bullets[j].IsActive = false;
						g_EnemyManager.Enemies[i].IsActive = false;
					}

		
				}

			}

		}

			EnemyCounter++;
			EnemyCounter02++;

		  if (EnemyCounter == 30)
			{

				Enemy_Y = rand() % 440;
				g_EnemyManager.CreateEnemy(Vec2(Enemy_X, Enemy_Y + 10.0f));
				EnemyCounter = 0;
			}

		  if (EnemyCounter02 == 90)
		  {
			  Enemy02_Y = rand() % 440;
			  g_EnemyManager02.CreateEnemy(Vec2(Enemy02_X, Enemy02_Y + 10.0f));
			  EnemyCounter02 = 0;
		  }
		  
			//g_EnemyManager.CreateEnemy(Vec2(200.0f, 200.0f));

		 
}



void FinishGameScene()
{
	Engine::ReleaseTexture("Robot");
	Engine::ReleaseTexture("Enemy");
	Engine::ReleaseTexture("Bullet");
	Engine::ReleaseTexture("Score00");
}


void DrawGameScene()
{
    if (g_CurrentSceneStep != SceneStep::Run)
	{
		return;
	}
	//Engine::StartDrawing(0);
	//g_Score.Draw();

	if (g_Player.Player_Hp >= 1)
	{
		Engine::DrawTexture(0.0f, 0.0f, "Heart02");
	}

		if (g_Player.Player_Hp >= 2)
		{
			Engine::DrawTexture(55.0f, 0.0f, "Heart02");
		}

		if (g_Player.Player_Hp >= 3)
		{
			Engine::DrawTexture(110.0f, 0.0f, "Heart02");
		}


	//�w�i����
	Engine::DrawTexture(background01--, 350.0f, "building");
	Engine::DrawTexture(background02--, 350.0f, "building");
	

	g_EnemyManager.Draw();
	g_Player.Draw();
	g_BulletManager.Draw();
	//g_Enemy02.Draw();
	g_EnemyManager02.Draw();

	if (background01 <= -1000.0f)
	{
		background01 = 1000.0f;
	}
	else if (background02 <= -1000.0f)
	{
		background02 = 1000.0f;
	}

	
	//Engine::FinishDrawing();
}

void UpdateGameScene()
{
	switch (g_CurrentSceneStep)
	{
	case SceneStep::Init:
		InitGameScene();
		break;
	case SceneStep::Run:
		RunGameScene();
		break;
	case SceneStep::Finish:
		FinishGameScene();
		break;
	}

	DrawGameScene();
}
