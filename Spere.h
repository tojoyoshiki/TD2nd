#pragma once
#include <KamataEngine.h>
#include "3d/Model.h"
#include "3d/WorldTransform.h"
#include "3d/camera.h"
#include "MathUtility.h"

class Spere
{
public:
	void Initialize(KamataEngine::Model* model,
		KamataEngine::Camera* camera);
	void Update();
	void Draw(KamataEngine::WorldTransform& worldTransform_,
		KamataEngine::Camera* camera);

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Camera* camera_ = nullptr;
	uint32_t textureHandle_ = 0u;
};
