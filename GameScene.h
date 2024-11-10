#pragma once
#include "Player.h"
#include "Spere.h"
#include <KamataEngine.h>

using namespace KamataEngine;

class Player;

class GameScene {
public:
	// コンストラクタ
	GameScene();
	// デストラクタ
	~GameScene();

	// 初期化
	void Initialze();

	// 毎フレーム処理
	void Update();

	// 描画
	void Draw();

private:
	// メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// モデル
	Model* model_ = nullptr;

	// ビュープロ(カメラ)
	Camera camera_;

	// プレイヤー
	Player* player_ = nullptr;

	//天球
	Spere* spere_ = nullptr;
};