#include "../../Engine/Engine.h"
#include "Scene.h"
#include "GameScene.h"

void InitGameScene();
void RunGameScene();
void FinishGameScene();
void DrawGameScene();

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

Vec2 g_RobotPosition = Vec2(0.0f, 0.0f);
Vec2 g_EnemyPosition = Vec2(0.0f, 0.0f);

void InitGameScene()
{
	Engine::LoadTexture("Robot", "Res/Robot_idle 1.PNG");
	Engine::LoadTexture("Enemy", "Res/EA1.PNG");

	g_CurrentSceneStep = SceneStep::Run;
}

void RunGameScene()
{
	float speed = 2.0f;

	if (Engine::IsKeyboardKeyHeld(DIK_UPARROW))
	{
		g_RobotPosition.Y -= speed;
	}
	else if (Engine::IsKeyboardKeyHeld(DIK_DOWNARROW))
	{
		g_RobotPosition.Y += speed;
	}

	if (Engine::IsKeyboardKeyHeld(DIK_LEFTARROW))
	{
		g_RobotPosition.X -= speed;
	}
	else if (Engine::IsKeyboardKeyHeld(DIK_RIGHTARROW))
	{
		g_RobotPosition.X += speed;
	}
}

void FinishGameScene()
{
	Engine::ReleaseTexture("Robot");
	Engine::ReleaseTexture("Enemy");
}

void DrawGameScene()
{
	if (g_CurrentSceneStep != SceneStep::Run)
	{
		return;
	}
	Engine::StartDrawing(0);

	Engine::DrawTexture(g_RobotPosition.X, g_RobotPosition.Y, "Robot");
	Engine::DrawTexture(g_EnemyPosition.X, g_EnemyPosition.Y, "Enemy");

	Engine::FinishDrawing();
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
