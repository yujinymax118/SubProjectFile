#include "sceneResult.h"
#include "soundmanager.h"
#include<DxLib.h>
#include "../lib/input.h"
#include "../lib/fade.h"


#define RESULT_SIZE_X (640)   //タイトルの横
#define RESULT_SIZE_Y (480)   //タイトルの縦


//コンストラクタ・デストラクタ
Result::Result()
{
	m_sceneID = INIT;
}

Result::~Result()
{
	Exit();
}


//------------------------------------
//データの初期化
//------------------------------------
void Result::Init()
{
	//ここは最初の状態を設定するだけでよい
	m_hdl = -1;
}

//繰り返し行う処理
int Result::Loop()
{
	int Ret = 0;

	switch (m_sceneID)
	{
	case Result::INIT:
		Init();
		m_sceneID = LOAD;
		break;
	case Result::LOAD:
		Load();
		m_sceneID = STEP;
		break;
	case Result::STEP:
		Step();
		break;
	case Result::END:
		Exit();
		m_sceneID = INIT;
		Ret = 1;
		break;
	}

	return Ret;
}

//データロード
void Result::Load()
{
	//画像ロード関連
	if (m_hdl == -1)
	{
		m_hdl = LoadGraph("data/graphic/title/result.jpg");
	}

}


//-------------------------------------
//ゲーム全体の処理管理
//-------------------------------------
void Result::Step()
{
	//決定ボタンを押したら次へ==============
	if (IsInputTrg(KEY_SHOT) != 0)
	{
		m_sceneID = END;
	}
}

//終了前処理
void Result::Exit()
{
	if (m_hdl != -1)
	{
		DeleteGraph(m_hdl);

		m_hdl = -1;
	}

}


//---------------------------------
//タイトルの描画管理
//---------------------------------
void Result::Draw()
{
	switch (m_sceneID)
	{
	case STEP:
	case END:
		//タイトル画面描画
		DrawRotaGraph((int)(RESULT_SIZE_X * 0.5f), (int)(RESULT_SIZE_Y * 0.5f),
			1.0, 0.0, m_hdl, TRUE);
		break;
	}
}


