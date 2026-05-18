#pragma once
#include <DxLib.h>
#include "math.h"
#include "../src/ShotManager.h"

class CPlayer
{
private:
	//プレイヤーの状態を表す列挙型
	enum tagPlayerState
	{
		PLSTATE_NORMAL,  //待機・歩き中
		PLSTATE_JUMP,    //ジャンプ中

		PLSTATE_NUM
	};

	VECTOR m_Pos;		//座標
	VECTOR m_Rot;		//回転
	VECTOR m_Speed;		//移動速度
	float m_fRadius;	//半径
	tagPlayerState m_State;  //現在の状態
	bool m_isActive;	//生存フラグ
	int m_Hndl;			//ハンドル

public:
	//コンストラクタ・デストラクタ
	CPlayer();
	~CPlayer();

	//初期化
	// @vPos		:	座標
	// @vRot		:	注視点
	void Init();

	//データ関連のロード
	void Load();

	//終了処理
	void Exit();

	//毎フレーム呼ぶ処理
	void Step(ShotManager &cShotManager);

	//更新したデータを反映させる
	void Update();

	//描画処理
	void Draw();

	//===========================
	//		当たり判定後の処理
	//===========================
	void HitCalc();


	//===================================
	//		取得関連
	//===================================
	//プレイヤーの座標を取得
	VECTOR GetPosition() { return m_Pos; }

	//プレイヤーの回転角度(Y軸)を取得
	float GetRotationY() { return m_Rot.y; }

	//生存判定
	// @return	:	true = 生存 false = 死亡
	bool IsActive() { return m_isActive; }
	void SetActive(bool active) { m_isActive = active; }

	//半径取得
	float GetRadius(void) { return m_fRadius; }

	
};
