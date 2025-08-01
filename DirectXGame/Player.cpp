#include "Player.h"

Player::~Player() {}

void Player::Initialize(KamataEngine::Model* model) {

	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTtansform_.Initialize();
}

void Player::Update() {

	// 行列を定数バッファに転送
	worldTtansform_.TransferMatrix();

	
}

void Player::Draw(KamataEngine::Camera& camera) {

	// 3Dモデルを描画
	model_->Draw(worldTtansform_, camera);
}


