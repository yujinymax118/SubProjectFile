#include "input.h"
#include <DxLib.h>

//キーボード入力用構造体
typedef struct
{
	unsigned int m_nowKey;
	unsigned int m_PrevKey;
}INPUT_DATA;

//キー入力用にグローバル変数を作成
static INPUT_DATA g_inputData;



//キー入力初期化
void InitInput()
{
	g_inputData.m_nowKey = g_inputData.m_PrevKey = 0;
}

//キー入力情報更新
void UpdateInput()
{
	//最新情報は1フレーム前の情報になる
	g_inputData.m_PrevKey = g_inputData.m_nowKey;
	//いったん最新情報は初期化
	g_inputData.m_nowKey = 0;

	//上を押した
	if (CheckHitKey(KEY_INPUT_UP)) g_inputData.m_nowKey |= KEY_UP;
	if (CheckHitKey(KEY_INPUT_W)) g_inputData.m_nowKey |= KEY_UP;
	//下を押した
	if (CheckHitKey(KEY_INPUT_DOWN)) g_inputData.m_nowKey |= KEY_DOWN;
	if (CheckHitKey(KEY_INPUT_S)) g_inputData.m_nowKey |= KEY_DOWN;
	//右を押した
	if (CheckHitKey(KEY_INPUT_RIGHT)) g_inputData.m_nowKey |= KEY_RIGHT;
	if (CheckHitKey(KEY_INPUT_D)) g_inputData.m_nowKey |= KEY_RIGHT;
	//左を押した
	if (CheckHitKey(KEY_INPUT_LEFT)) g_inputData.m_nowKey |= KEY_LEFT;
	if (CheckHitKey(KEY_INPUT_A)) g_inputData.m_nowKey |= KEY_LEFT;
	//ショットボタンを押した
	if (CheckHitKey(KEY_INPUT_SPACE)) g_inputData.m_nowKey |= KEY_SHOT;
	//切り替えボタンを押した
	if (CheckHitKey(KEY_INPUT_LSHIFT)) g_inputData.m_nowKey |= KEY_CHANGE;


}

//キー入力判定（通常判定）
bool IsInputRep(unsigned int key)
{
	if ((g_inputData.m_nowKey & key) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//キー入力判定(トリガー判定)
bool IsInputTrg(unsigned int key)
{
	if ((g_inputData.m_nowKey & key) != 0
		&& (g_inputData.m_PrevKey & key) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
