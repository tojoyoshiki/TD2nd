#include "Spere.h"

using namespace KamataEngine;

void Spere::Initialize(KamataEngine::Model* model,
	KamataEngine::Camera* camera) 
{
	worldTransform_.Initialize();
	model_ = model;
	camera_ = camera;
	//textureHandle_ = textureHandle;
	//textureHandle_ = TextureManager::Load("./Resources/uvChecker.png");
	textureHandle_ = Model::CreateFromOBJ("./Resources/uvChecker.png", true);
}

void Spere::Update() 
{ 
}

void Spere::Draw(KamataEngine::Camera* camera) 
{
	model_->Draw(worldTransform_, *camera, textureHandle_); 
}
