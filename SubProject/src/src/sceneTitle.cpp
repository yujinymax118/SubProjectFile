#include "sceneTitle.h"
#include "soundmanager.h"
#include<DxLib.h>
#include "../lib/input.h"
#include "../lib/fade.h"

#define TITLE_SIZE_X (640)   //タイトルの横
#define TITLE_SIZE_Y (480)   //タイトルの縦

//コンストラクタ・デストラクタ
Title::Title()
{
	m_sceneID = INIT;
}

Title::~Title()
{
	Exit();
}


//------------------------------------
//データの初期化
//------------------------------------
void Title::Init()
{
	//ここは最初の状態を設定するだけでよい
	m_hdl = -1;
}

//繰り返し行う処理
int Title::Loop()
{
	int Ret = 0;

	switch (m_sceneID)
	{
	case Title::INIT:
		Init();
		m_sceneID = LOAD;
		break;
	case Title::LOAD:
		Load();
		m_sceneID = STEP;
		break;
	case Title::STEP:
		Step();
		break;
	case Title::END:
		Exit();
		m_sceneID = INIT;
		Ret = 1;
		break;
	}

	return Ret;
}

//データロード
void Title::Load()
{
	//画像ロード関連
	if (m_hdl == -1)
	{
		m_hdl = LoadGraph("data/graphic/title/title.jpg");
	}

}

void Title::Step()
{
	//決定ボタンを押したら次へ==============
 	if (IsInputTrg(KEY_SHOT) != 0)
	{
		m_sceneID = END;
	}

}

//---------------------------------
//タイトルの描画管理
//---------------------------------
void Title::Draw()
{
	switch (m_sceneID)
	{
	case STEP:
	case END:
		//タイトル画面描画
		DrawRotaGraph((int)(TITLE_SIZE_X * 0.5f), (int)(TITLE_SIZE_Y * 0.5f),
			1.0, 0.0, m_hdl, TRUE);
		break;
	}
}

//終了前処理
void Title::Exit()
{
	if (m_hdl != -1)
	{
		DeleteGraph(m_hdl);

		m_hdl = -1;
	}
	
}
