#pragma once
#include <DxLib.h>
#include "CameraManager.h"
#include "player.h"
#include "ShotManager.h"
#include "EnemyManager.h"
#include "background.h"
#include "CollisionManager.h"
#include "../src/SoundManager.h"
#include "../src/sceneTitle.h"
#include "../src/sceneResult.h"


class CPlayScene
{
public:
	//playsceneの状態遷移
	enum tagPLAY_SCENE
	{
		INIT,
		LOAD,
		LOOP,
		END,

		NUM
	};
private:
	CameraManager cCameraManager;
	CPlayer cPlayer;
	ShotManager m_shot;
	tagPLAY_SCENE m_sceneID;
	EnemyManager m_enemy;
	BackGround m_background;


public:
	//コンストラクタ・デストラクタ
	CPlayScene();
	
	//繰り返し行う処理
	int Loop();
	//描画処理
	void Draw();
	//初期化
	void Init();
	//終了前処理
	void Exit();
	//データロード
	void Load();
	
	//毎フレーム呼ぶ処理
	void Step();

};
