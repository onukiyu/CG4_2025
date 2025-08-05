#include "Graph.h"

Graph::~Graph() { 
	delete sprite_;
}

// 初期化
void Graph::Initialize() { 
// ファイル名を指定してテクスチャを読み込む
textureHandle_ = KamataEngine::TextureManager::Load("white1x1.png"); 
// スプライトインスタンスの生成
sprite_ = KamataEngine::Sprite::Create(textureHandle_, { 100, 20 });
sprite2_ = KamataEngine::Sprite::Create(textureHandle_, { 100, 20 });
}

// 更新
void Graph::Update() { 
	// スプライトの大きさ指定
	sprite_->SetSize({100, 20});
	KamataEngine::Vector2 sprite2size_ = sprite2_->GetSize();
	sprite2size_.y = 20;
	// スプライトの色指定
	sprite_->SetColor({1.0f, 0.0f, 0.0f, 0.5f}); // 赤
	sprite2_->SetColor({0.0f, 1.0f, 0.0f, 0.5f}); // 緑

	if (sprite2size_.x >= 0) {
		sprite2size_.x -= 1;
		sprite2_->SetSize(sprite2size_);
	}
	if (sprite2size_.x <= 0) {
		sprite2size_.x = 100;
		sprite2_->SetSize(sprite2size_);
	}
}

// 描画
void Graph::Draw() { 
	
	sprite_->Draw();
	sprite2_->Draw();
}