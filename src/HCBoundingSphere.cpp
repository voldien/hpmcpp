#include"HCBoundingSphere.h"

using namespace LIBHPM;

/*
bool BoundingSphere::intersect(const Ray& ray) const {
	HCVector3 tmp = ray.getOrigin() - getCenter();
	double t;
	double a = dot(ray.getDirection(), ray.getDirection());
	double b = 2.0f * dot(ray.getDirection(), tmp);
	double d = dot(tmp, tmp) - radius * radius;
	double discriminant = b * b - (4.0 * d * a);
	if (discriminant >= 0) {
		discriminant = sqrt(discriminant);
		//hit.t = (-b - discriminant) / (2.0 * a);

		if (t < 0)
			t = (-b + discriminant) / (2.0 * a);
		return true;
	}
	return false;
}
*/

