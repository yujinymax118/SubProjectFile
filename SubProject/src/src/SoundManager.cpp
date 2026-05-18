#include "SoundManager.h"

vector<int> CSoundManager::m_hndl;

//初期化
void CSoundManager::Init()
{
	m_hndl.clear();
}

//データをロード
void CSoundManager::Load()
{
	const char* FilePath[SOUND_NUM] = {
		"data/sound/BattleBGM.ogg", "data/sound/se_explore.mp3", "data/sound/se_plshot.mp3"
	};

	for (int i = 0; i < SOUND_NUM; i++)
	{
		int hndl = LoadSoundMem(FilePath[i]);
		m_hndl.push_back(hndl);
	}
}

//終了処理
void CSoundManager::Exit()
{
	for (int i = 0; i < SOUND_NUM; i++)
	{
		if (m_hndl[i] != -1)
		{
			DeleteSoundMem(m_hndl[i]);
			m_hndl[i] = -1;
		}
	}
}

//音楽再生
//@id	:	DX_PLAYTYPE_BACK = 1回再生
//			DX_PLAYTYPE_LOOP = 繰り返し再生
//@isStart	: true = 再生成功,false = 再生失敗
//
bool CSoundManager::Play(tagSoundID id,
	int type, bool isStart)
{
	int ret = PlaySoundMem(m_hndl[id], type, isStart);
	if (ret == -1)return false;
	else return true;
}
//音楽停止
void CSoundManager::Stop(tagSoundID id)
{
	StopSoundMem(m_hndl[id]);
}
//すべての音楽を停止
void CSoundManager::StopAll()
{
	for (int i = 0; i < m_hndl.max_size(); i++)
	{
		StopSoundMem(m_hndl[i]);
	}
}
//音楽再生中かどうか
bool CSoundManager::isPlay(tagSoundID id)
{
	int result = CheckSoundMem(m_hndl[id]);
	if (result == 1) return true;
	else return false;
}
