#include "Ground.h"

class Enemy;

void Ground::Initialize() {
	dxCommon_ = DirectXCommon::GetInstance();

	// REDモデルの設定
	Transform_RED.Initialize();
	Transform_RED.scale_ = {0.5f, 0.5f, 0.5f};
	Transform_RED.translation_ = {-20.0f, -2.0f, 0.0f}; // RED Modelの位置
	Transform_RED.UpdateMatrix();

	// GREENモデルの設定
	Transform_GREEN.Initialize();
	Transform_GREEN.scale_ = {0.5f, 0.5f, 0.5f};
	Transform_GREEN.translation_ = {-10.324f, -2.0f, 0.0f}; // GREEN Modelの位置
	Transform_GREEN.UpdateMatrix();

	// BLUEモデルの設定
	Transform_BLUE.Initialize();
	Transform_BLUE.scale_ = {0.5f, 0.5f, 0.5f};
	Transform_BLUE.translation_ = {-0.265f, -2.0f, 0.0f}; // BLUE Modelの位置
	Transform_BLUE.UpdateMatrix();

	// YELLOWモデルの設定
	Transform_YELLOW.Initialize();
	Transform_YELLOW.scale_ = {0.5f, 0.5f, 0.5f};
	Transform_YELLOW.translation_ = {9.706f, -2.0f, 0.0f}; // YELLOW Modelの位置
	Transform_YELLOW.UpdateMatrix();

	camera_.Initialize();
	debugCamera = new DebugCamera(1280, 720);

	Ground_RED_Model_ = Model::CreateFromOBJ("ground_red", true);
	Ground_GREEN_Model_ = Model::CreateFromOBJ("ground_green", true);
	Ground_BLUE_Model_ = Model::CreateFromOBJ("ground_blue", true);
	Ground_YELLOW_Model_ = Model::CreateFromOBJ("ground_yellow", true);
}
void Ground::Update() {}

void Ground::Draw(DebugCamera* debugCamera_, Enemy::State enemyState) {

	switch (enemyState) {
	case Enemy::State::red:
		Ground_RED_Model_->Draw(Transform_RED, debugCamera_->GetCamera());
		break;
	case Enemy::State::green:
		Ground_GREEN_Model_->Draw(Transform_GREEN, debugCamera_->GetCamera());
		break;
	case Enemy::State::blue:
		Ground_BLUE_Model_->Draw(Transform_BLUE, debugCamera_->GetCamera());
		break;
	case Enemy::State::yellow:
		Ground_YELLOW_Model_->Draw(Transform_YELLOW, debugCamera_->GetCamera());
		break;
	}
}