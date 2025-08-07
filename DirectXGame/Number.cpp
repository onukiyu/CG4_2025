#include "Number.h"

Number::~Number() { 
	for (int i = 0; i < 5; i++) {
		delete sprite_[i];
	}
}

// 初期化
void Number::Initialize() {
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = KamataEngine::TextureManager::Load("number.png");
	// スプライトインスタンスの生成
	for (int i = 0; i < 5; i++) {
		sprite_[i] = KamataEngine::Sprite::Create(textureHandle_, {100.0f + size.x*i, 30});
		sprite_[i]->SetSize(size);
	}
	
}

// 更新
void Number::Update() {
	score += 1;
	int number = score;
	// 最初に割る数値は5桁なので10000で初期設定する
	int32_t digit = 10000;
	// 5桁分ループ
	for (int i = 0; i < 5; i++) {
		// 今の桁の数値を取り出す
		int nowNumber = number / digit; 
		// 今の桁の数値の部分を切り出すようにする 
		sprite_[i]->SetTextureRect({size.x * nowNumber, 0}, {32.0f, 64.0f});
		// 次の桁の処理のために、残りの桁の数値にする
		number %= digit;
		// 次の桁の処理の為に、割る数値を10で割って桁に応じた値にする
		digit /= 10;
	}

}

// 描画
void Number::Draw() {
	for (int i = 0; i < 5; i++) {
		sprite_[i]->Draw();
	}
}