#pragma once
#include <KamataEngine.h>
#include "Enemy.h"
using namespace KamataEngine;

class Ground {
public:
	void Initialize();

	void Update();

	void Draw(DebugCamera* debugCamera, Enemy::State enemyState);

	void UpdateMatrices();

	WorldTransform Transform_RED;
	WorldTransform Transform_GREEN;
	WorldTransform Transform_BLUE;
	WorldTransform Transform_YELLOW;

private:
	bool isDebugCameraActive_ = false;

	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Camera camera_;
	DebugCamera* debugCamera;

	Enemy* enemy_;

	Model* Ground_RED_Model_ = nullptr;
	Model* Ground_GREEN_Model_ = nullptr;
	Model* Ground_BLUE_Model_ = nullptr;
	Model* Ground_YELLOW_Model_ = nullptr;
};