#include "Ext/HCOBB.h"

using namespace LIBHPM;

OBB::OBB(const OBB &obb) { *this = obb; }

OBB::OBB(const Vector3 &u, const Vector3 &v, const Vector3 &w) { this->onb.set(u, v, w); }

OBB::OBB(const Vector3 &u, const Vector3 &v, const Vector3 &w, const Vector3 &size) {
	this->onb.set(u, v, w);
	this->setSize(size);
}

const Vector3 &OBB::getU(void) const { return onb.u(); }

const Vector3 &OBB::getV(void) const { return onb.v(); }

const Vector3 &OBB::getW(void) const { return onb.w(); }

OBB &OBB::operator=(const OBB &obb) {
	this->onb = obb.onb;
	this->setSize(obb.getSize());
	return *this;
}

std::istream &operator>>(std::istream &is, OBB &t) { return is; }

std::ostream &operator<<(std::ostream &os, const OBB &t) { return os; }
