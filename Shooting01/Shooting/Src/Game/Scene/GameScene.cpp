#include "../../Engine/Engine.h"
#include "Scene.h"
#include "GameScene.h"
#include "../../../EnemyManager.h"
#include "../../../Player.h"
#include "../../../Bullet.h"
#include "../../../BulletManager.h"
#include "../../../Score.h"
#include "../../../Enemy02.h"
#include "../../../Enemy02Manager.h"
#include "../../../Boss.h"
#include "../../../BulletManager02.h"
//bool OnCollisionCircleAndCircle(Vec2 pos_a, float radius_a, Vec2 pos_b, float radius_b)
//{
//	Vec2 length = Vec2(pos_a.X - pos_b.X, pos_a.Y - pos_b.Y);
//	length.X *= length.X;
//	length.Y *= length.Y;
//
//	float distance = sqrtf(length.X + length.Y);
//
//	if ((radius_a + radius_b) < distance)
//	{
//		return true;
//	}
//
//	return false;
//}
//*/
//
//
///*
//	引数 =>
//		矩形情報二つ
//
//	戻り値 =>
//		当たりの結果
//			当たってる => true
//			当たってない => false
//*/
//
void InitGameScene();
void RunGameScene();
void FinishGameScene();
void DrawGameScene();

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

bool g_IsCollision = false;
EnemyManager g_EnemyManager;
Player g_Player;
BulletManager g_BulletManager;
Score g_Score;
Enemy g_Enemy;
Enemy02 g_Enemy02;
EnemyManager02 g_EnemyManager02;
Boss g_Boss;
Bullet02 g_Bullet02;
BulletManager02 g_BulletManager02;

//背景01
static float background01 = 0.0f;
//背景02
static float background02 = 1000.0f;

//Enemyのカウンター
static int EnemyCounter = 0;

//Enemy02のカウンター
static int EnemyCounter02 = 0;

//生成されるEnemyのX座標とY座標
static float Enemy_X = 700.0f;
static float Enemy_Y = 0;

//生成されるEnemy02のX座標とY座標
static float Enemy02_X = 700.0f;
static float Enemy02_Y = 0;

//Bossの弾の生成カウンター
static float BossBulletCounter = 0;

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
 引数 =>
  矩形情報二つ

 戻り値 =>
  当たりの結果
   当たってる => true
   当たってない => false
*/


bool OnCollisionRectAndRect(Rect* object01, Rect* object02)
{


    // サイズ
    Vec2 size[] =
    {
     Vec2(object01->Right - object01->Left, object01->Bottom - object01->Top),
     Vec2(object02->Right - object02->Left, object02->Bottom - object02->Top),
    };

    // 中心座標
    Vec2 center_pos[] =
    {
     Vec2(object01->Left + size[0].X / 2.0f, object01->Top + size[0].Y / 2.0f),
     Vec2(object02->Left + size[1].X / 2.0f, object02->Top + size[1].Y / 2.0f),
    };

    // RobotとEnemy二つの矩形の距離
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




    // RobotとEnemyのサイズの和
    Vec2 size_sum = Vec2(
        (size[0].X + size[1].X) / 2.0f,
        (size[0].Y + size[1].Y) / 2.0f);


    // 判定
    /*
     矩形間の距離が矩形サイズの合計よりも小さければ当たり
    */
    if (distance.X < size_sum.X &&
        distance.Y < size_sum.Y)
    {
        // 当たってる
        return true;
    }

    // 当たっていない
    return false;

}




/*
bool OncollisionRectAndRect(Rect* object01, Rect* object02)
{
 //サイズ
 Vec2 size[] =
 {
  Vec2(object01->Right - object01->Left, object01->Bottom - object01->Top),
  Vec2(object02->Right - object02->Left, object02->Bottom - object02->Top),
 };

 //中心座標
 Vec2 center_pos[] =
 {
  Vec2(object01->Left + size[0].X / 2.0f, object01->Top + size[0].Y / 2.0f),
  Vec2(object02->Left + size[1].X / 2.0f, object02->Top + size[1].Y / 2.0f),
 };

 //距離
 Vec2 distance = Vec2(center_pos[0].X - center_pos[1].X, center_pos[0].Y - center_pos[1].Y);

 if (distance.X < 0.0f)
 {
  distance.X *= -1.0f;
 }

 if (distance.Y < 0.0f)
 {
  distance.Y *= -1.0f;
 }

 //サイズの和
 Vec2 size_sum = Vec2(
  (size[0].X + size[1].X) / 2.0f,
  (size[0].Y + size[1].Y) / 2.0f);


 //判定
 //矩形間の距離が矩形サイズの合計よりも小さければ当たり
 if (distance.X < size_sum.X && distance.Y < size_sum.Y)
 {
  //当たっている
  return true;
 }
 //当たっていない
 return false;


 //RobotとEnemyの半径
 //float Robot_radius = size[0].Y / 2;
 //float Enemy_radius = size[1].Y / 2;

 //RobotとEnemyの距離
 //float a = center_pos[0].X - center_pos[1].X;
 //float b = center_pos[0].Y - center_pos[1].Y;
 //float c = sqrt(a * a + b * b);

 //if (c <= Robot_radius + Enemy_radius)
 //{
  //当たっている
 // return true;
 //}

 //当たっていない
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
    g_Boss.Iintialize(Vec2(1000.0f, 100.0f));
    //g_BulletManager.CreateBullet(Vec2(100.0f, 200.0f));
    //g_Bullet02.Iintialize(Vec2(100.0f, 200.0f));
    g_BulletManager02.Initialize();

    Engine::LoadTexture("Robot", "Res/Robot_idle 1.PNG");
    Engine::LoadTexture("Bullet", "Res/Bullet1.PNG");
    Engine::LoadTexture("Bullet02", "Res/Bullet2.png");
    Engine::LoadTexture("Heart02", "Res/Heart02.png");

    Engine::LoadTexture("Enemy", "Res/EA1.PNG");
    Engine::LoadTexture("Enemy02", "Res/EA2 1.png");
    Engine::LoadTexture("Boss", "Res/Head_Boss_01.png");

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
   

    //弾丸発射キー
    if (Engine::IsKeyboardKeyPushed(DIK_5))
    {
        g_BulletManager.CreateBullet(Vec2(g_Player.Position.X + 30.0f, g_Player.Position.Y + 20.0f));
    }

    if (g_Boss.Position.X <= 500.0f)
    {
        BossBulletCounter++;
    }

    if (BossBulletCounter >= 50)
    {
        g_BulletManager02.CreateBullet(Vec2(g_Boss.Position.X, g_Boss.Position.Y + 90.0f));

        BossBulletCounter = 0;

    }

   


    g_Player.Update();
    g_BulletManager.Update();
    g_Score.Update();
    g_EnemyManager.Update();
    //g_Enemy02.Update();
    g_EnemyManager02.Update();
    g_Boss.Update();
    //g_Bullet02.Update();
    g_BulletManager02.Update();

    Texture* texture[6] =
    {
     Engine::GetTexture("Robot"),
     Engine::GetTexture("Enemy"),
     Engine::GetTexture("Enemy02"),
     Engine::GetTexture("Bullet"),
     Engine::GetTexture("Boss"),
     Engine::GetTexture("Bullet02")
    };

    Vec2 tex_size[6];

    // テクスチャサイズの取得
    for (int i = 0; i < 6; i++)
    {
        if (texture[i] != nullptr)
        {
            tex_size[i].X = texture[i]->Width;
            tex_size[i].Y = texture[i]->Height;
        }

    }

    Rect RobotRect = 
    {
         g_Player.Position.X,
         g_Player.Position.X + tex_size[0].X,
         g_Player.Position.Y,
         g_Player.Position.Y + tex_size[0].Y
    };


    Rect BossRect = 
    {
         g_Boss.Position.X,
         g_Boss.Position.X + tex_size[4].X,
         g_Boss.Position.Y,
         g_Boss.Position.Y + tex_size[4].Y,
    };

    
    for (int i = 0; i < 100; i++) {

        Rect EnemyRect = 
        {
           g_EnemyManager.Enemies[i].Position.X,
           g_EnemyManager.Enemies[i].Position.X + tex_size[1].X,
           g_EnemyManager.Enemies[i].Position.Y,
           g_EnemyManager.Enemies[i].Position.Y + tex_size[1].Y
        };

        if (g_EnemyManager.Enemies[i].IsActive == true)
        {
            //EnemyとRobotの当たり判定
            if (OnCollisionRectAndRect(&RobotRect, &EnemyRect))
            {
                g_EnemyManager.Enemies[i].IsActive = false;
                g_Player.Player_Hp--;
            }
        }
    }

   
  
       
    for (int i = 0; i < 100; i++) 
    {
        
        Rect Enemy02Rect = 
        {
           g_EnemyManager02.Enemies[i].Position.X,
           g_EnemyManager02.Enemies[i].Position.X + tex_size[1].X,
           g_EnemyManager02.Enemies[i].Position.Y,
           g_EnemyManager02.Enemies[i].Position.Y + tex_size[1].Y
        };

        if (g_EnemyManager02.Enemies[i].IsActive == true)
        {
            //EnemyとRobotの当たり判定
            if (OnCollisionRectAndRect(&RobotRect, &Enemy02Rect))
            {
                g_EnemyManager02.Enemies[i].IsActive = false;
                g_Player.Player_Hp--;
            }
           
        
        }
    }

  for (int a = 0; a < 100; a++)
    {
        Rect Bullet02Rect =
        {
            g_BulletManager02.Bullets[a].Position.X,
            g_BulletManager02.Bullets[a].Position.X + tex_size[1].X,
            g_BulletManager02.Bullets[a].Position.Y,
            g_BulletManager02.Bullets[a].Position.Y + tex_size[1].Y
        };

        //BulletとRobotの当たり判定
        if (g_BulletManager02.Bullets[a].IsActive == true)
        {
            if (OnCollisionRectAndRect(&RobotRect, &Bullet02Rect))
            {

                g_BulletManager02.Bullets[a].IsActive = false;
                g_Player.Player_Hp--;
            }
        }
    }



    
    for (int i = 0; i < 100; i++) 
    {
        Rect BulletRect = 
        {
                g_BulletManager.Bullets[i].Position.X,
                g_BulletManager.Bullets[i].Position.X + tex_size[3].X,
                g_BulletManager.Bullets[i].Position.Y,
                g_BulletManager.Bullets[i].Position.Y + tex_size[3].Y
        };

        if (g_BulletManager.Bullets[i].IsActive == true) 
        {

            for (int j = 0; j < 100; j++) 
            {
                Rect EnemyRect = 
                {
   g_EnemyManager.Enemies[j].Position.X,
   g_EnemyManager.Enemies[j].Position.X + tex_size[1].X,
   g_EnemyManager.Enemies[j].Position.Y,
   g_EnemyManager.Enemies[j].Position.Y + tex_size[1].Y
                };

                if (g_EnemyManager.Enemies[j].IsActive == true)
               {
                    //EnemyとBulletの当たり判定
                    if (OnCollisionRectAndRect(&BulletRect, &EnemyRect))
                    {
                        g_EnemyManager.Enemies[j].IsActive = false;
                        g_BulletManager.Bullets[i].IsActive = false;
                    }
                }
            }

           





            for (int j = 0; j < 100; j++) 
            {
                Rect Enemy02Rect = 
                {
   g_EnemyManager02.Enemies[j].Position.X,
   g_EnemyManager02.Enemies[j].Position.X + tex_size[1].X,
   g_EnemyManager02.Enemies[j].Position.Y,
   g_EnemyManager02.Enemies[j].Position.Y + tex_size[1].Y
                };

                if (g_EnemyManager02.Enemies[j].IsActive == true)
                {
                    //Enemy02とBulletの当たり判定
                    if (OnCollisionRectAndRect(&BulletRect, &Enemy02Rect))
                    {
                        g_EnemyManager02.Enemies[j].IsActive = false;
                        g_BulletManager.Bullets[i].IsActive = false;
                    }
                }
            }

            

           
        
            //BossとRobotの当たり判定
            if (g_Boss.IsActive == true)
            {
                if (OnCollisionRectAndRect(&BulletRect, &BossRect))
                {
                    g_Boss.BossHp--;
                    g_BulletManager.Bullets[i].IsActive = false;
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
    Engine::ReleaseTexture("Boss");
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


       
        if (g_Player.Player_Hp == 0)
        {
            g_CurrentSceneKind = SceneKind::TitleScene;
            g_CurrentSceneStep = SceneStep::Init;

        }
        else if (g_Boss.BossHp == 0)
        {
            g_CurrentSceneKind = SceneKind::TitleScene;
            g_CurrentSceneStep = SceneStep::Init;

        }
        


	//背景処理
	Engine::DrawTexture(background01--, 350.0f, "building");
	Engine::DrawTexture(background02--, 350.0f, "building");
	

	g_EnemyManager.Draw();
	g_Player.Draw();
	g_BulletManager.Draw();
	//g_Enemy02.Draw();
    g_EnemyManager02.Draw();
    g_Boss.Draw();
   // g_Bullet02.Draw();
    g_BulletManager02.Draw();
	

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