#include "TitleScene.h"

// デストラクタ
TitleScene::~TitleScene() {
	delete sprite_; 
	delete spriteBG_;
}

// 初期化
void TitleScene::Initialize() {
	// ファイル名を指定してテクスチャを読み込む
	textureHandleBG_ = KamataEngine::TextureManager::Load("title_bg.png");
	textureHandle_ = KamataEngine::TextureManager::Load("title.png");

	// スプライトインスタンスの生成
	spriteBG_ = KamataEngine::Sprite::Create(textureHandleBG_, {0, 0});
	sprite_ = KamataEngine::Sprite::Create(textureHandle_, {0, -400});

}

// 更新
void TitleScene::Update() {
	// スプライトの今の座標を取得
	KamataEngine::Vector2 position = sprite_->GetPosition();
	if (position.y <= 0.0f) {
		// 座標を{ 0, 1 }移動
		position.y += 1.0f;
		// 移動した座標をスプライトに反映
		sprite_->SetPosition(position);
	}
	
}

// 描画
void TitleScene::Draw() {
	// DirectXCommonインスタンスの取得
	KamataEngine::DirectXCommon* dxCommon = KamataEngine::DirectXCommon::GetInstance();

	// スプライト描画前処理
	KamataEngine::Sprite::PreDraw(dxCommon->GetCommandList());

	spriteBG_->Draw();
	sprite_->Draw();


	// スプライト描画後処理
	KamataEngine::Sprite::PostDraw();
}