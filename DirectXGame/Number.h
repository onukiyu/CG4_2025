#pragma once

#include <KamataEngine.h>

class Number {
public:
	// デストラクタ
	~Number();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// スプライト
	KamataEngine::Sprite* sprite_[5] = {};

	KamataEngine::Vector2 size = {32.0f, 64.0f};

	int score = 12340;
};
