#include "GameScene.h"
#include <random>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

using namespace KamataEngine;
using namespace MathUtility;

GameScene::GameScene() {}

GameScene::~GameScene() {

	// 3Dモデルデータの解放
	delete modelParticle_;
	// パーティクルの解放
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

// 初期化
void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);
	// パーティクルの生成
	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();
		// 位置
		Vector3 position = {0.0f, 0.0f, 0.0f};
		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;

		// 初期化
		particle->Initialize(modelParticle_, position,velocity );
		// リストに追加
		particles_.push_back(particle);
	}
	//particle_ = new Particle();

	// カメラの初期化
	camera_.Initialize();

	// 位置
	//Vector3 position = {0.0f, 0.0f, 0.0f};
	// パーティクルの初期化
	//particle_->Initialize(modelParticle_, position);

}
// 更新
void GameScene::Update() {

	// 終了フラグの立った弾を削除
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle;
			return true;
		}
		return false;
	});

	// パーティクルの更新
	for (Particle* particle : particles_) {
		particle->Update();
	}
	//particle_->Update();

}
// 描画
void GameScene::Draw() {

	// DirectCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画処理
	Model::PreDraw(dxCommon->GetCommandList());

	// パーティクルの描画
	for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();
}

