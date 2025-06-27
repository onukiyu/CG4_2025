#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {

	// 3Dモデルデータの解放
	delete modelParticle_;
	// パーティクルの解放
	delete particle_;

	Model2::StaticFinalize();
}

// 初期化
void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelParticle_ = Model2::CreateSphere(4, 4);
	// パーティクルの生成
	particle_ = new Particle();

	// カメラの初期化
	camera_.Initialize();

	
	// パーティクルの初期化
	particle_->Initialize(modelParticle_);

	Model2::StaticInitialize();

}
// 更新
void GameScene::Update() {

	// パーティクルの更新
	particle_->Update();

}
// 描画
void GameScene::Draw() {

	// DirectCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画処理
	Model2::PreDraw(dxCommon->GetCommandList());

	// パーティクルの描画
	particle_->Draw(camera_);

	// 3Dモデル描画後処理
	Model2::PostDraw();
}

