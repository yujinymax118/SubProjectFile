#pragma once

class Fade
{
private:

};
// データの初期化
void InitFade();
//ゲームの推移全体を制御
void StepFade();
//状態推移の中にあるすべての描画を管理
void DrawFade();

//フェードインリクエスト
void RequestFadeIn();
//フェードアウトリクエスト
void RequestFadeOut();
//フェードインが終了したか
bool IsEndFadeIn();
//フェードアウトが終了したか
bool IsEndFadeOut();