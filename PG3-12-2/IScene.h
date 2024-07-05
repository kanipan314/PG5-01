#pragma once
#include <Novice.h>

// キー入力結果を受け取る箱
static char keys[256] = { 0 };
static char preKeys[256] = { 0 };

//シーン名をenumで定義
enum SCENE
{
	TITLE,
	STAGE,
	CLEAR
};
class IScene
{
protected:
	//シーン番号を管理する変数
	static int sceneNo;

public:


	//継承先で実装される関数
	//抽象クラスなので純粋関数とする
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//仮想デストラクトを用意しないと警告される
	virtual ~IScene();

	//シーン番号ゲッター
	int GetSceneNo();


};

