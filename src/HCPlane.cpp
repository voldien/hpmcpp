#include"HCPlane.h"

HCPlane::HCPlane(void) {
}
HCPlane::HCPlane(const HCVector3& normal) {
	this->normal = normal;
	this->d = 0;
}
HCPlane::HCPlane(const HCVector3& point, const HCVector3& normal) {
	this->setNormalAndPoint(normal, point);
}
HCPlane::HCPlane(const HCPlane& plane) {
	*this = plane;
}

HCPlane HCPlane::fromPoints(const HCVector3& v1, const HCVector3& v2,
		const HCVector3& v3) {
	HCPlane tmp;
	HCVector3 e1 = v2 - v1;
	HCVector3 e2 = v3 - v1;

	tmp.normal = cross(e1, e2).normalize();
	tmp.d = -dot(tmp.normal, v2);
	return tmp;
}