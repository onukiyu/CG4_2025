#pragma once

#include <KamataEngine.h>

class Player {
public:
	// デストラクタ
	~Player();

	// 初期化
	void Initialize(KamataEngine::Model* model);

	// 更新
	void Update();

	// 描画
	void Draw(KamataEngine::Camera& camera);

private:

	// ワールド変換データ
	KamataEngine::WorldTransform worldTtansform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;
	
};
