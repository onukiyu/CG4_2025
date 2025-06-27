#include "Particle.h"

void Particle::Initialize(Model2* model) {

	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTtansform_.Initialize();

}

void Particle::Update() {

	// 行列を定数バッファに転送
	worldTtansform_.TransferMatrix();
}

void Particle::Draw(Camera& camera) {

	//3Dモデルを描画
	model_->Draw(worldTtansform_, camera);
	
}
