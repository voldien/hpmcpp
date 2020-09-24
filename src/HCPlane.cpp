#include"HCPlane.h"

using namespace hpmcpp;

// HCPlane::HCPlane(const HCVector3& normal) {
// 	this->normal = normal;
// 	this->d = 0;
// }
// HCPlane::HCPlane(const HCVector3& point, const HCVector3& normal) {
// 	this->setNormalAndPoint(normal, point);
// }
// HCPlane::HCPlane(const HCPlane& plane) {
// 	*this = plane;
// }

// HCPlane HCPlane::fromPoints(const HCVector3& v1, const HCVector3& v2,
// 		const HCVector3& v3) {
// 	HCPlane tmp;
// 	HCVector3 e1 = v2 - v1;
// 	HCVector3 e2 = v3 - v1;

// 	tmp.normal = cross(e1, e2).normalize();
// 	tmp.d = -dot(tmp.normal, v2);
// 	return tmp;
// }

std::istream &operator>>(std::istream &is, Plane &t) {
	return is;
}

std::ostream &operator<<(std::ostream &os, const Plane &t) {
	return os;
}

bool operator==(const Plane &o1, const Plane &o2) {
	return false;
}

bool operator!=(const Plane &o1, const Plane &o2) {
	return false;
}
