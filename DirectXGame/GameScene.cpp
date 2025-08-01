#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {

	// 3Dモデルデータの解放
	delete modelParticle_;
	// パーティクルの解放
	delete particle_;

	delete model_;
	delete player_;

	Model2::StaticFinalize();
}

// 初期化
void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelParticle_ = Model2::CreateSquare();
	// パーティクルの生成
	particle_ = new Particle();
	// 3Dモデル
	player_ = new Player();

	// カメラの初期化
	camera_.Initialize();

	
	// パーティクルの初期化
	particle_->Initialize(modelParticle_);


	model_ = Model::CreateFromOBJ("player");
	player_->Initialize(model_);

	Model2::StaticInitialize();

}
// 更新
void GameScene::Update() {

	// パーティクルの更新
	particle_->Update();

	player_->Update();

}
// 描画
void GameScene::Draw() {

	// DirectCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// 2D


	// スプライト描画後処理
	Sprite::PostDraw();

	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommon->GetCommandList());

	// パーティクルの描画
	particle_->Draw(camera_);

	// 3Dモデル描画後処理
	Model2::PostDraw();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// プレイヤーの描画
	player_->Draw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// 2D近景

	// スプライト描画後処理
	Sprite::PostDraw();
}

