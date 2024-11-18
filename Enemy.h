#pragma once
#include <KamataEngine.h>
#include "MathUtility.h"

class Enemy {
public:
	enum class State {
		red, 
		blue,  
		yellow,
		green    
	};
	Enemy::State GetState() const { return currentState_; }


	void Initialize(KamataEngine::Model* model, uint32_t enemyTextureHandle, uint32_t currentTexture, uint32_t angryTexture, uint32_t deadTexture,uint32_t cryTexture,
		KamataEngine::Vector3 position);
	void Update();
	void Draw(KamataEngine::Camera* camera);
	void SetState(State state);

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Vector3 position_ = {0.0f, 0.0f, 0.0f};
	uint32_t enemyTextureHandle_;  // 初期テクスチャ
	uint32_t angryTextureHandle_; // 現在のテクスチャ
	uint32_t deadTextureHandle_; // 現在のテクスチャ
	uint32_t cryTextureHandle_; // 現在のテクスチャ

	uint32_t currentTexture_; // 現在のテクスチャ
	State currentState_;      // 現在の状態

	int alive = 1;
};
