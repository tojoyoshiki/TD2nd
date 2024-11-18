#include "Enemy.h"

void Enemy::Initialize(KamataEngine::Model* model, uint32_t enemyTextureHandle, uint32_t angryTexture, uint32_t deadTexture, uint32_t cryTexture, uint32_t currentTexture, 
	KamataEngine::Vector3 position)
{
	model_ = model;
	enemyTextureHandle_ = enemyTextureHandle;
	currentTexture_ = angryTexture;
	angryTextureHandle_ = deadTexture;
	deadTextureHandle_ = cryTexture;
	cryTextureHandle_ = currentTexture;

	worldTransform_.Initialize();

	position_ = position;
	worldTransform_.translation_ = position_;

    SetState(State::red);
}

void Enemy::Update() 
{
	//float enemySpeed = 0.1f;

	worldTransform_.matWorld_ =MakeAffineMatrix(
		worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();

	//移動
   // worldTransform_.translation_.z -= enemySpeed;

}

void Enemy::SetState(State state) {
	currentState_ = state;

	// 状態に応じてテクスチャを変更
	switch (state) {
	case State::red:
		currentTexture_ = enemyTextureHandle_; // 通常のテクスチャ
		break;
	case State::blue:
		// 怒った状態のテクスチャ
		currentTexture_ = angryTextureHandle_; // angryTextureHandle_を事前にロードしておく
		break;
	case State::yellow:
		// 死亡状態のテクスチャ
		currentTexture_ = deadTextureHandle_; // deadTextureHandle_を事前にロードしておく
		break;
	case State::green:
		// テクスチ
		currentTexture_ = cryTextureHandle_; // deadTextureHandle_を事前にロードしておく
		break;
	}
}

void Enemy::Draw(KamataEngine::Camera* camera) { model_->Draw(worldTransform_, *camera, currentTexture_); }


