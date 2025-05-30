#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Effect.h"



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

	void ParticleBorn(KamataEngine::Vector3 position);

private:

	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;


	// カメラ
	KamataEngine::Camera camera_;

	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelEffect_ = nullptr;

	// カメラ
	//KamataEngine::Camera camera_;

	// パーティクル
	//Particle* particle_ = nullptr;
	std::list<Particle*> particles_;

	Effect* effect_ = nullptr;
};
