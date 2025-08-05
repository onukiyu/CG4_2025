#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Model2.h"
#include "Player.h"
#include "Graph.h"

using namespace KamataEngine;

// ゲームシーン
class GameScene {

public:

	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:

	// パーティクル3Dモデルデータ
	Model2* modelParticle_ = nullptr;

	// カメラ
	Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;

	Player* player_ = nullptr;
	Model* model_ = nullptr;

	Graph* graph_ = nullptr;
};
