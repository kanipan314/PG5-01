﻿#pragma once

#include <memory>
#include "IScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "ClearScene.h"

class GameManager
{

private:
	//シーンを保持するメンバ変数
	std::unique_ptr < IScene > sceneArr_[3];

	//どのステージを呼び出すかを管理する変数
	int currentSceneNo_;
	int prevSceneNo_ = TITLE;

public:
	GameManager(); //コンストラクタ
	~GameManager(); //デストラクタ

	int Run();

};