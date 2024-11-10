#pragma once
#include <KamataEngine.h>
#include "3d/Model.h"
#include "3d/WorldTransform.h"
#include "3d/camera.h"
#include <input/Input.h>
#include "MathUtility.h"

class Player {

public:
	void Initialize(KamataEngine::Model* model, uint32_t textureHandle, 
		KamataEngine::Vector3 position);
	void Update();
	void Draw(KamataEngine::Camera* camera);

private:
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	uint32_t textureHandle_ = 0u;

	KamataEngine::Input* input_ = nullptr;

	KamataEngine::Vector3 position_ = {0, 0, 0};
};
