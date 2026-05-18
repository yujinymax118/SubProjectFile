#pragma once

class Result
{
public:
	//カメラのタイプ
	enum tagRESULT_SCENE
	{
		INIT,
		LOAD,
		STEP,
		END,

		NUM
	};

private:
	tagRESULT_SCENE m_sceneID;
	int m_hdl;
public:
	//コンストラクタ・デストラクタ
	Result();

	~Result();

	//タイトルの状態推移の初期化
	void Init();
	//タイトル全体の処理管理
	// @return :
	void Step();
	//タイトルの描画関連管理
	void Draw();
	//繰り返し行う処理
	int Loop();
	//終了前処理
	void Exit();
	//データロード
	void Load();

};
