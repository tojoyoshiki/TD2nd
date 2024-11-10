#pragma once
#include "math/Vector3.h"
#include <math/Matrix4x4.h>
#include <math/Vector3.h>
#include <cmath>
#include <KamataEngine.h>
#include "3d/WorldTransform.h"

KamataEngine::Vector3& operator+=(KamataEngine::Vector3& a, const KamataEngine::Vector3& b);
KamataEngine::Vector3& operator-=(KamataEngine::Vector3& a, const KamataEngine::Vector3& b);

const KamataEngine::Vector3 operator+(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);
const KamataEngine::Vector3 operator-(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);

KamataEngine::Matrix4x4 MakeAffineMatrix(const KamataEngine::Vector3& scale, const KamataEngine::Vector3& rot, const KamataEngine::Vector3& translate);

KamataEngine::Matrix4x4 MatrixMultiply(KamataEngine::Matrix4x4& m1, KamataEngine::Matrix4x4& m2);

KamataEngine::Vector3 TransformNormal(const KamataEngine::Vector3& v, const KamataEngine::Matrix4x4& m);