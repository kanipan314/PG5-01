#include "GameManager.h"

using namespace std;


GameManager::GameManager()
{
	sceneArr_[TITLE] = make_unique<TitleScene>();
	sceneArr_[STAGE] = make_unique<StageScene>();
	sceneArr_[CLEAR] = make_unique<ClearScene>();

	//初期シーンの設定
	currentSceneNo_ = TITLE;
}

GameManager::~GameManager() {};

int GameManager::Run() {
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame(); //フレームの開始
		
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		//シーンのチェック
 		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		//シーン変更チェック
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		//更新処理
		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
			sceneArr_[currentSceneNo_]->Update();

		}
		//描画処理
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame(); //フレームの終了

		//ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0;
}