#include"HCOBB.h"

HCOBB::HCOBB(void) {

}

HCOBB::HCOBB(const HCOBB& obb) {
	*this = obb;
}

HCOBB::HCOBB(const HCVector3& u, const HCVector3& v, const HCVector3& w) {
	this->onb.set(u, v, w);
}

HCOBB::HCOBB(const HCVector3& u, const HCVector3& v, const HCVector3& w,
		const HCVector3& size) {
	this->onb.set(u, v, w);
	this->halfu = size.x();
	this->halfv = size.y();
	this->halfw = size.z();
}

HCVector3 HCOBB::getU(void) const {
	return onb.u();
}

HCVector3 HCOBB::getV(void) const {
	return onb.v();
}

HCVector3 HCOBB::getW(void) const {
	return onb.w();
}

HCOBB& HCOBB::operator=(const HCOBB& obb) {
	this->onb = obb.onb;
	this->halfu = obb.halfu;
	this->halfv = obb.halfv;
	this->halfw = obb.halfw;
	return *this;
}
