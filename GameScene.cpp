#include "GameScene.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {

	delete model_;
	delete player_;
	delete enemy_;
	delete debugCamera_;
}

void GameScene::Initialze() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources/white1x1.png");
	
	enemyTextureHandle_ = TextureManager::Load("./Resources/Loudlycryingface.png");
	angryTextureHandle_ = TextureManager::Load("./Resources/Coldface.png");
	deadTextureHandle_ = TextureManager::Load("./Resources/Cowboyhatface.png");
	cryTextureHandle_ = TextureManager::Load("./Resources/Faceblowingakiss.png");

	//生成
	model_ = Model::Create();
	player_ = new Player();
	enemy_ = new Enemy();
	spere_ = new Spere();
	debugCamera_ = new DebugCamera(1280, 720);

	//初期化

	camera_.Initialize();
	player_->Initialize(model_, textureHandle_, {0.0f,-5.0f,-30.0f});
	enemy_->Initialize(model_, enemyTextureHandle_, angryTextureHandle_,deadTextureHandle_, cryTextureHandle_,angryTextureHandle_, {0.0f, 5.0f, 5.0f});
	spere_->Initialize(model_,  &camera_);
	ground_.Initialize();
}

void GameScene::Update() {

	//更新
	player_->Update();
	spere_->Update();
	enemy_->Update();
	ground_.Update();

	///
	///ここのifの条件式を、必要に応じて変えればOK！
	/// 
	if (Input::GetInstance()->PushKey(DIK_U)) {
		enemy_->SetState(Enemy::State::red); // 敵の状態をAngryに変更
	}
	// さらに、条件に応じて死んだ状態にすることもできる
	if (Input::GetInstance()->PushKey(DIK_I)) {
		enemy_->SetState(Enemy::State::yellow); // 敵をDeadに変更
	}
	if (Input::GetInstance()->PushKey(DIK_O)) {
		enemy_->SetState(Enemy::State::blue); // 敵の状態をAngryに変更
	}
	// さらに、条件に応じて死んだ状態にすることもできる
	if (Input::GetInstance()->PushKey(DIK_P)) {
		enemy_->SetState(Enemy::State::green); // 敵をDeadに変更
	}
	///
	///
	/// 


	if (Input::GetInstance()->PushKey(DIK_1)) {
		finished_ = true;
	}

#ifdef _DEBUG
	if (input_->TriggerKey(DIK_F1)) {
		isDebugCameraActive_ = !isDebugCameraActive_; // トグル
	}
#endif // DEBUG

	// デバッグカメラがアクティブな場合のみ更新
	if (isDebugCameraActive_) {
		debugCamera_->Update();
	}

	ChangePhase();

	// imGui
	ImGui::Begin("debug");
	ImGui::Text("IsDebugCamera: %d", isDebugCameraActive_);
	ImGui::End();

	// REDモデルの位置調整
	ImGui::Text("RED Model");
	ImGui::SliderFloat3("Red Translation", &ground_.Transform_RED.translation_.x, -20.0f, 20.0f);
	ground_.Transform_RED.UpdateMatrix();

	// GREENモデルの位置調整
	ImGui::Text("GREEN Model");
	ImGui::SliderFloat3("Green Translation", &ground_.Transform_GREEN.translation_.x, -20.0f, 20.0f);
	ground_.Transform_GREEN.UpdateMatrix();

	// BLUEモデルの位置調整
	ImGui::Text("BLUE Model");
	ImGui::SliderFloat3("Blue Translation", &ground_.Transform_BLUE.translation_.x, -20.0f, 20.0f);
	ground_.Transform_BLUE.UpdateMatrix();

	// YELLOWモデルの位置調整
	ImGui::Text("YELLOW Model");
	ImGui::SliderFloat3("Yellow Translation", &ground_.Transform_YELLOW.translation_.x, -20.0f, 20.0f);
	ground_.Transform_YELLOW.UpdateMatrix();

	ImGui::End();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);
	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	ground_.Draw(debugCamera_, enemy_->GetState());

	// 描画
	player_->Draw(&camera_);
	enemy_->Draw(&camera_);
	//spere_->Draw(&camera_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);
	// スプライト描画後処理
	Sprite::PostDraw();
}

void GameScene::ChangePhase() {

	switch (phase_) {
	case Phase::kPlay:

		// 自キャラの状態をチェック
		if (Input::GetInstance()->PushKey(DIK_3)) {
			// 死亡フェーズに切り替え
			phase_ = Phase::kDeath;
		}

		if (Input::GetInstance()->PushKey(DIK_4)) {
			// クリアフェーズに切り替え
			phase_ = Phase::kClear;
		}
		break;

	case Phase::kDeath:

		// デス演出フェーズの処理
		finished_ = true;
		break;

	case Phase::kClear:

		// デス演出フェーズの処理
		Clear_ = true;
		break;
	}
}