#include "Player.h"

using namespace KamataEngine;

void Player::Initialize(
	KamataEngine::Model* model,uint32_t textureHandle, KamataEngine::Vector3 position)
{
	model_ = model;
	textureHandle_ = textureHandle;
	worldTransform_.Initialize();
	
	position_ = position;
	worldTransform_.translation_ = position_;

	input_ = KamataEngine::Input::GetInstance();
}

void Player::Update()
{
	Vector3 move = {0, 0, 0};

	// キャラクターの移動速度
	const float kCharacterSpeed = 0.2f;

	// 回る速度
	const float roatationSpeed = 0.1f;

	// 押した方向で移動ベクトルを変更
	if (input_->PushKey(DIK_A)) {
		move.x -= kCharacterSpeed;
	}
	if (input_->PushKey(DIK_D)) {
		move.x += kCharacterSpeed;
	}
	if (input_->PushKey(DIK_S)) {
		move.y -= kCharacterSpeed;
	}
	if (input_->PushKey(DIK_W)) {
		move.y += kCharacterSpeed;
	}

	// 旋回処理
	if (input_->PushKey(DIK_LEFT)) {
		worldTransform_.rotation_.y += roatationSpeed;
	}
	if (input_->PushKey(DIK_RIGHT)) {
		worldTransform_.rotation_.y -= roatationSpeed;
	}
	// 移動
	worldTransform_.translation_ += move;

	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();
}

void Player::Draw(KamataEngine::Camera* camera) 
{ 
	model_->Draw(worldTransform_, *camera, textureHandle_);
}
