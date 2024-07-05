#include "ClearScene.h"

void ClearScene::Init()
{
}

void ClearScene::Update()
{
	sceneNo = TITLE;

}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Scene = Clear");

}
