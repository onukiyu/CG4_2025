#include "Effect.h"

using namespace KamataEngine;
using namespace MathUtility;

// 
void Effect::EffectInitialize(KamataEngine::Model* model, float size, float rotate ) {//mataEngine::Vector3 position, KamataEngine::Vector3 velocity

	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTtansform_.Initialize();

	//rldTtansform_.translation_ = position;

	//locity_ = velocity;

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	// 大きさ
	worldTtansform_.scale_ = {size, 0.5f, 1.0f};

	worldTtansform_.rotation_ = {0.0f, 3.14f, rotate};

}

// 
void Effect::EffectUpdate() {
	// 行列を更新
	worldTtansform_.UpdateMatrix();
}

// 
void Effect::EffectDraw(KamataEngine::Camera& camera) {

	// 3Dモデルを描画
	model_->Draw(worldTtansform_, camera, &objectColor_);
}

