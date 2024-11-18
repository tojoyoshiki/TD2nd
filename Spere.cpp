#include "Spere.h"

using namespace KamataEngine;

void Spere::Initialize(KamataEngine::Model* model,
	KamataEngine::Camera* camera) 
{
	worldTransform_.Initialize();
	model_ = model;
	camera_ = camera;
}

void Spere::Update() 
{ 
}

void Spere::Draw(KamataEngine::WorldTransform& worldTransform,
	KamataEngine::Camera* camera)
{
	model_->Draw(worldTransform, *camera); 
}
