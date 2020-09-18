#include "Scene.h"
#include "TitleScene.h"
#include "../../Engine/Engine.h"


void InitTitleScene();
void RunTitleScene();
void FinishTitleScene();

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

void InitTitleScene()
{
	Engine::Update();
	Engine::DrawFont(200.0f, 200.0f, "タイトルシーン", Regular, White);
	if (Engine::IsKeyboardKeyHeld(DIK_RETURN))
	{
		//g_CurrentSceneStep = SceneStep::Init;
		g_CurrentSceneKind = SceneKind::GameScene;
	}
}

void RunTitleScene()
{

}

void FinishTitleScene()
{

}

void UpdateTitleScene()
{
	switch (g_CurrentSceneStep)
	{
	case SceneStep::Init:
		InitTitleScene();
		break;
	case SceneStep::Run:
		RunTitleScene();
		break;
	case SceneStep::Finish:
		FinishTitleScene();
		break;
	}
}
