#include"HCOBB.h"

using namespace hpmcpp;

HCOBB::HCOBB(const HCOBB& obb) {
	*this = obb;
}

HCOBB::HCOBB(const HCVector3& u, const HCVector3& v, const HCVector3& w) {
	this->onb.set(u, v, w);
}

HCOBB::HCOBB(const HCVector3& u, const HCVector3& v, const HCVector3& w,
		const HCVector3& size) {
	this->onb.set(u, v, w);
	this->setSize(size);
}

const HCVector3& HCOBB::getU(void) const {
	return onb.u();
}

const HCVector3& HCOBB::getV(void) const {
	return onb.v();
}

const HCVector3& HCOBB::getW(void) const {
	return onb.w();
}

HCOBB& HCOBB::operator=(const HCOBB& obb) {
	this->onb = obb.onb;
	this->setSize(obb.getSize());
	return *this;
}

std::istream &operator>>(std::istream &is, HCOBB &t) {
    return is;
}

std::ostream &operator<<(std::ostream &os, const HCOBB &t) {
	return os;
}

