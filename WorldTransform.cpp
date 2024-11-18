#include "MathUtility.h"
#include <KamataEngine.h>
#include <3d/WorldTransform.h>

using namespace KamataEngine;

void KamataEngine::WorldTransform::UpdateMatrix() {
	// スケール・回転・平行移動を合成して計算する
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);
	// 定数バッファに転送する
	TransferMatrix();
}