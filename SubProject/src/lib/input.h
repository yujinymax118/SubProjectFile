#pragma once

//今回のシューティングゲームで使うボタン
#define KEY_UP       (0b1)
#define KEY_DOWN     (0b10)
#define KEY_RIGHT    (0b100)
#define KEY_LEFT     (0b1000)
#define KEY_SHOT     (0b10000)
#define KEY_CHANGE   (0b100000)
//--------------------------------------



//キー入力初期化
void InitInput();
//キー入力情報更新
void UpdateInput();
//キー入力判定（通常判定)
bool IsInputRep(unsigned int key);
//キー入力判定(トリガー判定)
bool IsInputTrg(unsigned int key);