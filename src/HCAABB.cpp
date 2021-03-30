// #include "Ext/HCAABB.h"

// using namespace LIBHPM;

// AABB &AABB::operator=(const AABB &bound) {
// 	this->mhalfsize = bound.mhalfsize;
// 	this->mcenter = bound.mcenter;
// 	return *this;
// }

// AABB operator*(const AABB &bound, float scalar) { return AABB(bound.getCenter(), bound.getSize() / scalar); }

// AABB operator/(const AABB &bound, float divisor) { return AABB(bound.getCenter(), bound.getSize() / divisor); }

// AABB &AABB::operator*=(float scalar) {
// 	this->mhalfsize *= scalar;
// 	return *this;
// }

// AABB &AABB::operator/=(float divisor) {
// 	const float scalar = 1.0f / divisor;
// 	this->mhalfsize *= scalar;
// 	return *this;
// }

// // Vector3 AABB::getVertexP(Vector3 &normal) const {
// // 	Vector3 res = this->mhalfsize;
// // 	if (normal.x() >= 0.0f)
// // 		res[0] += this->mcenter.x();
// // 	if (normal.y() >= 0.0f)
// // 		res[1] += this->mcenter.y();
// // 	if (normal.z() >= 0.0f)
// // 		res[2] += this->mcenter.z();
// // 	return res;
// // }
// // Vector3 AABB::getVertexN(Vector3 &normal) const {
// // 	Vector3 res = this->mhalfsize;
// // 	if (normal.x() < 0.0f)
// // 		res[0] += this->mcenter.x();
// // 	if (normal.y() < 0.0f)
// // 		res[1] += this->mcenter.y();
// // 	if (normal.z() < 0.0f)
// // 		res[2] += this->mcenter.z();
// // 	return res;
// // }

// // bool AABB::operator==(const AABB &bound) {
// // 	return (this->getCenter() == bound.getCenter()) && (this->getSize() == bound.getSize());
// // }

// // bool AABB::operator!=(const AABB &bound) {
// // 	return (this->getCenter() != bound.getCenter()) || (this->getSize() != bound.getSize());
// // }
