#include "IScene.h"

//タイトルシーンで初期化
int IScene::sceneNo = TITLE;

//仮想デストラクトの定義
//純粋仮想関数化していないので、ここを定義できる

IScene::~IScene() {};

//シーン番号のゲッター
int IScene::GetSceneNo() { return sceneNo; };