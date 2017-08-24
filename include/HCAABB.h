/**
    C++ Wrapper for the hpm library.
    Copyright (C) 2017  Valdemar Lindberg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef _HPMCPP_BOUNDS_H_
#define _HPMCPP_BOUNDS_H_ 1
#include"HCRay.h"
#include"HCVector3.h"

/**
 *
 */
class HCDECLSPEC HCAABB {

public:
	HCAABB(void) {}
	HCAABB(const HCVector3& size, const HCVector3& center);
	HCAABB(const HCAABB& bounds) {
		*this = bounds;
	}

	/**/
	inline HCVector3 operator[](int i) const {
		return ((HCVector3*) this)[i];
	}
	inline HCVector3& operator[](int i) {
		return ((HCVector3*) this)[i];
	}

	/**
	 *
	 */
	inline bool isValid(void) const {
		return !(this->mhalfsize.x() != 0.0f || this->mhalfsize.y() != 0.0f
				|| this->mhalfsize.z() != 0.0f);
	}

	/*
	 *
	 */
	inline float maxX(void) const {
		return (this->mcenter.x() + this->mhalfsize.x());
	}
	inline float minX(void) const {
		return (this->mcenter.x() - this->mhalfsize.x());
	}
	inline float maxY(void) const {
		return (this->mcenter.y() + this->mhalfsize.y());
	}
	inline float minY(void) const {
		return (this->mcenter.y() - this->mhalfsize.y());
	}
	inline float maxZ(void) const {
		return (this->mcenter.z() + this->mhalfsize.z());
	}
	inline float minZ(void) const {
		return (this->mcenter.z() - this->mhalfsize.z());
	}

	/**
	 *	@Return
	 */
	inline HCVector3 min(void) const {
		return this->getCenter() - getSize();
	}

	/**
	 *
	 *	@Return
	 */
	inline HCVector3 max(void) const {
		return this->getCenter() + getSize();
	}

	inline HCVector3 getSize(void) const {
		return this->mhalfsize;
	}
	void setSize(const HCVector3& size) {
		this->mhalfsize = size;
	}

	inline HCVector3 getCenter(void) const {
		return this->mcenter;
	}
	inline void setCenter(const HCVector3& center) {
		this->mcenter = center;
	}

	/**
	 *	@Return
	 */
	bool intersect(const HCAABB& bounds);
	//bool intersect(const Ray& ray, RaycastHit& hit)const;

	/**
	 *
	 */
	bool contains(const HCVector3& point, const HCVector3 worldPosition =
			HCVector3());
	bool contains(const HCAABB& bounds);

	HCVector3 getVertexN(HCVector3& normal) const;
	HCVector3 getVertexP(HCVector3& normal) const;

	friend std::istream &operator>>(std::istream &is, HCVector3& t);
	friend std::ostream &operator<<(std::ostream &os, const HCVector3& t);

	HCAABB& operator=(const HCAABB& bound);
	friend HCAABB& operator*=(const HCAABB& bound, float scalar);
	friend HCAABB& operator/=(const HCAABB& bound, float scalar);

	bool operator==(const HCAABB& bound);
	bool operator!=(const HCAABB& bound);

private:	/*	Attributes.	*/

	HCVector3 mhalfsize;	/*	half size of the box.	*/
	HCVector3 mcenter;	/*	center of the box.	*/

};


#endif
