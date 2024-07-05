#include "TitleScene.h"
#include <memory>

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	sceneNo = STAGE;
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Scene = Title");

}
