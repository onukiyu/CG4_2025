#include "Stage.h"

Stage::~Stage() {
	delete spriteL_;
	delete spriteR_;
}

// 初期化
void Stage::Initialize() {
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = KamataEngine::TextureManager::Load("scrollBG.png");

	// スプライトインスタンスの生成
	spriteL_ = KamataEngine::Sprite::Create(textureHandle_, {-1280, 0});
	spriteR_ = KamataEngine::Sprite::Create(textureHandle_, {0, 0});
}

// 更新
void Stage::Update() {
	// スプライトの今の座標を取得
	KamataEngine::Vector2 positionL = spriteL_->GetPosition();
	KamataEngine::Vector2 positionR = spriteR_->GetPosition();
	
	if (positionL.x <= 0.0f) {
		// 座標を{ 3, 0 }移動
		positionL.x += 3.0f;
		positionR.x += 3.0f;
		// 移動した座標をスプライトに反映
		spriteL_->SetPosition(positionL);
		spriteR_->SetPosition(positionR);
	}
	if (positionL.x >= 0.0f) {
		// 座標を{ 3, 0 }移動
		positionL.x = -1280.0f;
		positionR.x = 0.0f;
		// 移動した座標をスプライトに反映
		spriteL_->SetPosition(positionL);
		spriteR_->SetPosition(positionR);
	}
}

// 描画
void Stage::Draw() {
	// DirectXCommonインスタンスの取得
	KamataEngine::DirectXCommon* dxCommon = KamataEngine::DirectXCommon::GetInstance();

	// スプライト描画前処理
	KamataEngine::Sprite::PreDraw(dxCommon->GetCommandList());

	spriteL_->Draw();
	spriteR_->Draw();

	// スプライト描画後処理
	KamataEngine::Sprite::PostDraw();
}