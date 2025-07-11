#pragma once

#include <KamataEngine.h>


class TitleScene {
public:

	// デストラクタ
	~TitleScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	uint32_t textureHandleBG_ = 0;

	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Sprite* spriteBG_ = nullptr;
};
