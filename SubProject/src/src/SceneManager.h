#pragma once
#include "DxLib.h"
#include "PlayScene.h"

//ゲーム全体を管理するクラス
class SceneManager
{
private:
	//ゲーム中に使用する各シーン
	enum  tagScene
	{
		TITLE,		//タイトル画面
		GAME,		//ゲーム本編
		RESULT,		//リザルト画面

		NUM
	};

	//各種シーンの変数を用意
	Title cTitle;
	Result cResult;
	CPlayScene cPlayScene;
	tagScene m_sceneID;

public:
	//コンストラクタ・デストラクタ
	SceneManager();
	~SceneManager();


	int Loop();

	void Draw();

};