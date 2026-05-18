#include "Enemy.h"

#define DEBUG

static const VECTOR ZERO = { 0.0f, 0.0f,0.0f };
static const float MOVE_SPEED = 3.0f;
static const float RADIUS = 3.0f;

//コンストラクタ・デストラクタ
Enemy::Enemy()
{
	Init();
}
Enemy::~Enemy()
{
	Exit();
}

//初期化
void Enemy::Init()
{
	m_Pos = ZERO;
	m_Speed = ZERO;
	m_hndl = -1;
	m_fRadius = RADIUS;
	m_isActive = false;
}

//データロード
void Enemy::Load(int Modelhndl)
{
	if (m_hndl == -1)
		m_hndl = MV1DuplicateModel(Modelhndl);
}

//終了処理
void Enemy::Exit()
{
	if (m_hndl != -1)
	{
		MV1DeleteModel(m_hndl);
		m_hndl = -1;
	}
}

//描画処理
void Enemy::Draw()
{
	if (m_isActive)
	{
		MV1DrawModel(m_hndl);

#ifdef DEBUG
		VECTOR vPos = m_Pos;
		vPos.y += m_fRadius;
		DrawSphere3D(vPos, m_fRadius, 16, GetColor(0, 0, 255), GetColor(0, 0, 0), FALSE);

#endif // DEBUG

	}
}


//毎フレーム呼ぶ処理
void Enemy::Step()
{
	if (!m_isActive) return;

	//座標に速度を加算
	m_Pos = VAdd(m_Pos, m_Speed);
	//一定範囲を超えたら消す
	float fLength = 300.0f;
	if (m_Pos.x > fLength || m_Pos.x < -fLength
		|| m_Pos.y > fLength || m_Pos.y < -fLength
		|| m_Pos.z > fLength || m_Pos.z < -fLength)
	{
		m_isActive = false;
	}
}

void Enemy::Update()
{
	//座標更新
	MV1SetPosition(m_hndl, m_Pos);
}

//リクエスト
bool Enemy::Request(const VECTOR& Pos, const VECTOR& Speed)
{
	//すでに発射されている
	if (m_isActive) return false;

	m_Pos = Pos;
	m_Speed = Speed;
	m_isActive = true;

	return true;
}

//===========================
//		当たり判定後の処理
//===========================
void Enemy::HitCalc()
{
	CSoundManager::Play(CSoundManager::SOUNDID_SE_EXPLORE);
	//フラグを消す
	m_isActive = false;
}
