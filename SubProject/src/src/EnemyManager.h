#pragma once
#include "Enemy.h"

static const int ENEMY_NUM = 50;


//球全体を管理するクラス
class EnemyManager
{
private:
	Enemy m_enemy[ENEMY_NUM];
	int m_waitcount;

public:
	//コンストラクタ
	EnemyManager();

	//デストラクタ
	~EnemyManager();

	//初期化
	void Init();

	//データロード
	void Load();

	//終了処理
	void Exit();

	//毎フレーム呼ぶ処理
	void Step();

	//描画処理
	void Draw();

	//敵情報取得
	inline Enemy& GetEnemy(int iID) { return m_enemy[iID]; }

	//更新したデータをDxLibに反映させる
	void Update();

	//プレイヤーのショットリクエスト
	void Request();
};