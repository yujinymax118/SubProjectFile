#include "PlayScene.h"

//========================
//		定義関連
//========================

//コンストラクタ
CPlayScene::CPlayScene()
{
	m_sceneID = INIT;
}
//繰り返し行う処理
int CPlayScene::Loop()
{
	int Ret = 0;

	switch (m_sceneID)
	{
	case CPlayScene::INIT:
		Init();
		m_sceneID = LOAD;
		break;
	case CPlayScene::LOAD:
		Load();
		CSoundManager::Play(CSoundManager::SOUNDID_BGM, DX_PLAYTYPE_LOOP);
		m_sceneID = LOOP;
		break;
	case CPlayScene::LOOP:
		Step();
		break;
	case CPlayScene::END:
		Exit();
		m_sceneID = INIT;
		Ret = 1;
		break;
	}

	return Ret;
}

//描画処理
void CPlayScene::Draw()
{
	m_background.Draw();
	cPlayer.Draw();
	m_shot.Draw();
	m_enemy.Draw();
}

//初期化
void CPlayScene::Init()
{
	m_background.Init();
	cCameraManager.Init();
	cPlayer.Init();
	m_shot.Init();
	m_enemy.Init();
}

//終了前処理
void CPlayScene::Exit()
{
	m_background.Exit();
	cPlayer.Exit();
	m_shot.Exit();
	m_enemy.Exit();
}

//データロード
void CPlayScene::Load()
{
	m_background.Load();
	cPlayer.Load();
	m_shot.Load();
	m_enemy.Load();
}

//毎フレーム呼ぶ処理
void CPlayScene::Step()
{
	if (cPlayer.IsActive() == false)
	{
		m_sceneID = END;
	}
	//プレイヤー更新処理
	if (cCameraManager.GetID() == CameraManager::ID_PLAY)
	{
		m_background.Step();
		m_background.Update();
		cPlayer.Step(m_shot);
		cPlayer.Update();
		//プレイヤーショット更新
		m_shot.Step();
		m_shot.Update();
		//エネミー更新
		m_enemy.Step();
		m_enemy.Update();
		//当たり判定処理
		CCollisionManager::CheckHitShotToEnemy(m_enemy, m_shot);
		CCollisionManager::CheckHitPlayerToEnemy(m_enemy, cPlayer);
	}

	//カメラ切り替え処理
	if (CheckHitKey(KEY_INPUT_C))
	{
		cCameraManager.ChangeCamera(CameraManager::ID_DEBUG);
	}
	if (CheckHitKey(KEY_INPUT_V))
	{
		cCameraManager.ChangeCamera(CameraManager::ID_PLAY);
	}
	//カメラ更新処理
	cCameraManager.Step(cPlayer.GetPosition(), cPlayer.GetRotationY());
	cCameraManager.Update();
}
