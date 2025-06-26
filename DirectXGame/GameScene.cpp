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

	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();
}

// 初期化
void GameScene::Initialize() {

	
	//particle_ = new Particle();

	// カメラの初期化
	camera_.Initialize();

	// 乱数の初期化
	srand((unsigned)time(NULL));

	// モデル読み込み
	modelEffect_ = Model::CreateFromOBJ("plane");

	//effect_ = new Effect();

	

}
// 更新
void GameScene::Update() {

	if (rand() % 20 == 0) {
		// 発生位置は乱数
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
	
		// パーティクル発生
		ParticleBorn(position);
	}
	

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


	if (rand() % 20 == 0) {
		// 発生位置は乱数
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};

		// エフェクト発生
		EffectBorn(position);
	}
	// 終了フラグの立ったエフェクトを削除
	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
	});

	// エフェクトの更新
	for (Effect* effect : effects_) {
		effect->Update();
	}
	//effect_->EffectUpdate();

}
// 描画
void GameScene::Draw() {

	// DirectCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画処理
	Model::PreDraw(dxCommon->GetCommandList());

	//// パーティクルの描画
	//for (Particle* particle : particles_) {
	//	particle->Draw(camera_);
	//}

	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}
	//effect_->EffectDraw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();

	
}

void GameScene::ParticleBorn(Vector3 position) {
	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);
	// パーティクルの生成
	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();
		// 位置
		//Vector3 position = {0.0f, 0.0f, 0.0f};
		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;

		// 初期化
		particle->Initialize(modelParticle_, position, velocity);
		// リストに追加
		particles_.push_back(particle);
	}
}

void GameScene::EffectBorn(Vector3 position) {
	// エフェクトの初期化
	for (int i = 0; i < 10; i++) {
		// 生成
		Effect* effect = new Effect();
		// 位置
		// Vector3 position = {0.0f, 0.0f, 0.0f};
		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		// 発生位置は乱数
		float size = abs(distribution(randomEngine) * 5.0f) + 0.5f;

		float rotate = abs(distribution(randomEngine) * 3.14f);

		effect->Initialize(modelEffect_, size, rotate, position);

		// 初期化
		//effect->Initialize(modelParticle_, position);
		// リストに追加
		effects_.push_back(effect);
	}
}

