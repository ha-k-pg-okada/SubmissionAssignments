#include "Scene.h"
#include "TitleScene.h"

void InitTitleScene();
void RunTitleScene();
void FinishTitleScene();

extern SceneKind g_CurrentSceneKind;
extern SceneStep g_CurrentSceneStep;

void InitTitleScene()
{

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
