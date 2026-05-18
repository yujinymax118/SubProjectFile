#pragma once
#include "DxLib.h"
#include "SoundManager.h"

class Enemy
{
private:
	VECTOR m_Pos;			//座標
	VECTOR m_Speed;			//移動速度
	float m_fRadius;		//半径
	int m_hndl;				//モデルハンドル
	bool m_isActive;		//生存フラグ

public:
	//コンストラクタ・デストラクタ
	Enemy();
	~Enemy();

	//初期化
	void Init();

	//データロード
	void Load(int Modelhndl);
	//終了処理
	void Exit();
	//毎フレーム呼ぶ処理
	void Step();
	//描画処理
	void Draw();

	void Update();

	//===========================
	//		当たり判定後の処理
	//===========================
	void HitCalc();

	//リクエスト
	// Pos		:	初期座標
	// Speed	:	移動速度(方向ベクトル)
	// return	:	true=リクエスト成功 false=失敗
	bool Request(const VECTOR& Pos, const VECTOR& Speed);
	//生存判定
	// @return	:	true = 生存 false = 死亡
	bool IsActive() { return m_isActive; }
	void SetActive(bool active) { m_isActive = active; }

	//=======================================
	//		取得関連
	//=======================================
	//座標取得
	//	vPos	:	座標を保存する変数
	void GetPosition(VECTOR& vPos) { vPos = m_Pos; }
	//半径取得
	float GetRadius(void) { return m_fRadius; }

	//
};