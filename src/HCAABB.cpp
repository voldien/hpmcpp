#include"HCAABB.h"

HCAABB::HCAABB(const HCVector3& size, const HCVector3& center) {
	setCenter(center);
	setSize(size);
}

bool HCAABB::intersect(const HCAABB& bounds) {

	return false;
}

bool HCAABB::contains(const HCVector3& point, const HCVector3 worldPosition) {
	return (point.x() > minX() + worldPosition.x()
			&& point.x() < maxX() + worldPosition.x()
			&& point.y() > minY() + worldPosition.y()
			&& point.y() < maxY() + worldPosition.y()
			&& point.z() > minZ() + worldPosition.z()
			&& point.z() < maxZ() + worldPosition.z());
}

bool HCAABB::contains(const HCAABB& bounds) {
	return false;
}

HCAABB& HCAABB::operator=(const HCAABB& bound) {
	this->mhalfsize = bound.mhalfsize;
	this->mcenter = bound.mcenter;
	return *this;
}

HCVector3 HCAABB::getVertexP(HCVector3 &normal) const {
	HCVector3 res = this->mhalfsize;
	if (normal.x() >= 0.0f)
		res[0] += this->mcenter.x();
	if (normal.y() >= 0.0f)
		res[1] += this->mcenter.y();
	if (normal.z() >= 0.0f)
		res[2] += this->mcenter.z();
	return res;
}
HCVector3 HCAABB::getVertexN(HCVector3 &normal) const {
	HCVector3 res = this->mhalfsize;
	if (normal.x() < 0.0f)
		res[0] += this->mcenter.x();
	if (normal.y() < 0.0f)
		res[1] += this->mcenter.x();
	if (normal.z() < 0.0f)
		res[2] += this->mcenter.x();
	return res;
}


bool HCAABB::operator==(const HCAABB& bound){
	return (this->getCenter() == bound.getCenter()) && (this->getSize() == bound.getSize());
}

bool HCAABB::operator!=(const HCAABB& bound){
	return (this->getCenter() != bound.getCenter()) || (this->getSize() != bound.getSize());
}


