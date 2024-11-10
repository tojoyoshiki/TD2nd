#include "GameScene.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {

	delete model_;
	delete player_;
	delete spere_;
}

void GameScene::Initialze() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources/white1x1.png");

	//生成
	model_ = Model::Create();
	player_ = new Player();
	spere_ = new Spere();

	//初期化
	camera_.Initialize();
	player_->Initialize(model_, textureHandle_, {0.0f,-5.0f,-30.0f});
	spere_->Initialize(model_,  &camera_);
}

void GameScene::Update() {

	//更新
	player_->Update();
	spere_->Update();
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

	// 描画
	player_->Draw(&camera_);
	spere_->Draw(&camera_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);
	// スプライト描画後処理
	Sprite::PostDraw();
}