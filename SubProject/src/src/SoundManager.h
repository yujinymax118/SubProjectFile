#pragma once
#include <DxLib.h>
#include <vector>

using namespace std;

//============================
//		サウンド操作クラス
//============================
class CSoundManager
{
public:
	enum tagSoundID
	{
		SOUNDID_BGM,			//ゲーム中のBGM
		SOUND_ID_SE_PLSHOT,		//SEプレイヤーショット
		SOUNDID_SE_EXPLORE,		//SE爆発

		SOUND_NUM
	};
private:
	static vector<int> m_hndl;
public:

	//初期化
	static void Init();
	//終了処理
	static void Exit();
	//データをロード
	static void Load();

	//音楽再生
	//@id	:	DX_PLAYTYPE_BACK = 1回再生
	//			DX_PLAYTYPE_LOOP = 繰り返し再生
	//@isStart	: true = 再生成功,false = 再生失敗
	//
	static bool Play(tagSoundID id,
		int type = DX_PLAYTYPE_BACK, bool isStart = true);
	//音楽停止
	static void Stop(tagSoundID id);
	//すべての音楽を停止
	static void StopAll();
	//音楽再生中かどうか
	static bool isPlay(tagSoundID id);

};