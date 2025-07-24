#pragma once

#include <KamataEngine.h>

class Stage {
public:
	// デストラクタ
	~Stage();

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
	KamataEngine::Sprite* spriteL_ = nullptr;
	KamataEngine::Sprite* spriteR_ = nullptr;

};
