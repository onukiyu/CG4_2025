#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) {

	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTtansform_.Initialize();

	worldTtansform_.translation_ = position;

	velocity_ = velocity;

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	// 大きさ
	worldTtansform_.scale_ = {0.2f, 0.2f, 0.2f};
}

void Particle::Update() {

	// 移動
	worldTtansform_.translation_ += velocity_;

	// 行列を定数バッファに転送
	//worldTtansform_.TransferMatrix();

	// 行列を更新
	worldTtansform_.UpdateMatrix();

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);
}

void Particle::Draw(Camera& camera) {

	//3Dモデルを描画
	model_->Draw(worldTtansform_, camera, &objectColor_);
	
}
