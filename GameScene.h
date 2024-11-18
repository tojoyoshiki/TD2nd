#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Spere.h"
#include "Ground.h"
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

	void ChangePhase();

	bool GetIsFinished() const { return finished_; }

	bool GetIsClear() const { return Clear_; }


private:
	// メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t enemyTextureHandle_ = 0;
	uint32_t angryTextureHandle_ = 0;
	uint32_t deadTextureHandle_ = 0;
	uint32_t cryTextureHandle_ = 0;

	// モデル
	Model* model_ = nullptr;

	// ビュープロ(カメラ)
	Camera camera_;

	// プレイヤー
	Player* player_ = nullptr;

	Enemy* enemy_ = nullptr;

	//天球
	Spere* spere_ = nullptr;

	Ground ground_;

		// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;
	bool isDebugCameraActive_ = false;

	enum class Phase {
		kPlay,
		kDeath,
		kClear,
	};

	// ゲームの現在フェーズ(変数)
	Phase phase_;

	bool finished_ = false;
	bool Clear_ = false;
};