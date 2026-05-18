#include "EnemyManager.h"

static const char ENEMY_PATH[] = { "data/enemy/enemy.pmx" };
static const int WAIT_TIME = 60;

//コンストラクタ
EnemyManager::EnemyManager()
{
	m_waitcount = 0;
}

EnemyManager::~EnemyManager()
{
	Exit();
}

//初期化
void EnemyManager::Init()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Init();
	m_waitcount = 0;
}

//データロード
void EnemyManager::Load()
{
	//オリジナルモデル読み込み
	int iHandl = MV1LoadModel(ENEMY_PATH);
	//モデルを複製
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Load(iHandl);
	//オリジナルを削除
	MV1DeleteModel(iHandl);
}

//終了処理
void EnemyManager::Exit()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Exit();
}

//毎フレーム呼ぶ処理
void EnemyManager::Step()
{
	int enemyNum = 0;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_enemy[i].Step();
		if (m_enemy[i].IsActive() == true)
		{
			//生きていたらカウントを増やす
			enemyNum++;
		}
	}
	//敵が0か一定時間経過で新しい敵を呼ぶ
	m_waitcount++;
	if (m_waitcount > WAIT_TIME || enemyNum == 0)
	{
		Request();
		m_waitcount = 0;
	}
}

//描画処理
void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Draw();
}

//更新したデータをDxLibに反映させる
void EnemyManager::Update()
{
	for (int i = 0; i < ENEMY_NUM; i++)
		m_enemy[i].Update();
}

//エネミーのリクエスト
void EnemyManager::Request()
{
	
	VECTOR pos = { (float)GetRand(200) - 100.0f, 0.0f, 200.0f };
	VECTOR speed = { 0.0f, 0.0f, -0.5f };
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_enemy[i].Request(pos, speed))
		{
			//
			break;
		}
	}

}
