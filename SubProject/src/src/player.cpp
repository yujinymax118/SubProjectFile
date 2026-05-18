#include "player.h"
#include "../lib/input.h"

//---------------------------
//定義関連
//---------------------------
static const char PLAYER_MODEL_PATH[] = { "data/model/player/player.pmx" };
static const VECTOR ZERO = { 0.0f, 0.0f,0.0f };
static const float ROTATE_SPEED = 0.1f;
static const float MOVE_SPEED = 3.0f;
static const float SHOT_SPEED = 5.0f;
static const float RADIUS = 3.0f;


CPlayer::CPlayer()
{
	Init();

}

CPlayer::~CPlayer()
{
	Exit();
}

void CPlayer::Init()
{
	m_Pos = ZERO;
	m_Rot = ZERO;
	m_Speed = ZERO;
	m_fRadius = RADIUS;
	m_State = PLSTATE_NORMAL;
	m_Hndl = -1;
	m_isActive = true;
}

void CPlayer::Load()
{
	if (m_Hndl == -1)
	{
		m_Hndl = MV1LoadModel(PLAYER_MODEL_PATH);
	}
}


void CPlayer::Exit()
{

	MV1DeleteModel(m_Hndl);
	m_Hndl = -1;
}

//---------------------------------------
//		毎フレーム呼ぶ処理
//---------------------------------------
void CPlayer::Step(ShotManager& cShotManager)
{
	if (m_isActive == false)
	{
		return;
	}

	//キャラクターの移動
	float fSpeed = 0.0f;
	if (IsInputRep(KEY_UP))
		fSpeed = -MOVE_SPEED;

	if (IsInputRep(KEY_DOWN))
		fSpeed = MOVE_SPEED;
	
	//キャラクターの回転
	if (IsInputRep(KEY_LEFT) != 0)
		m_Rot.y -= ROTATE_SPEED;

	if (IsInputRep(KEY_RIGHT) != 0)
		m_Rot.y += ROTATE_SPEED;


	//入力したキーの情報とプレイヤーの角度から、移動速度を求める
	m_Speed.x = sinf(m_Rot.y) * fSpeed;
	m_Speed.y = 0.0f;
	m_Speed.z = cosf(m_Rot.y) * fSpeed;
	//移動速度を現在の座標に加算する
	m_Pos = VAdd(m_Pos, m_Speed);

	if (IsInputTrg(KEY_SHOT))
	{
		//プレイヤーの体から球を発射
		VECTOR vPos = m_Pos;
		vPos.y += 5.0f;
		//速度はプレイヤーと同じ方法で移動方向を決める
		VECTOR vSpd;
		vSpd.x = sinf(m_Rot.y) * -SHOT_SPEED;
		vSpd.z = cosf(m_Rot.y) * -SHOT_SPEED;
		vSpd.y = 0.0f;
		cShotManager.RequestPlayerShot(vPos, vSpd);
	}

}

//===================================
//更新したデータを反映させる
//===================================
void CPlayer::Update()
{
	//角度・座標を反映させる
	MV1SetRotationXYZ(m_Hndl, m_Rot);
	MV1SetPosition(m_Hndl, m_Pos);
}

//===================================
//描画処理
//===================================
void CPlayer::Draw()
{
	if (m_isActive)
	{
		MV1DrawModel(m_Hndl);

	#ifdef DEBUG
			VECTOR vPos = m_Pos;
			vPos.y += m_fRadius;
			DrawSphere3D(vPos, m_fRadius, 16, GetColor(0, 0, 255), GetColor(0, 0, 0), FALSE);

	#endif // DEBUG

	}
}

//===========================
//		当たり判定後の処理
//===========================
void CPlayer::HitCalc()
{
	m_isActive = false;
}
