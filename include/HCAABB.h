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

	/**
	 *	@Return
	 */
	inline HCVector3 operator[](int i) const {
		return ((HCVector3*) this)[i];
	}

	/**
	 *
	 *	@Return
	 */
	inline HCVector3& operator[](int i) {
		return ((HCVector3*) this)[i];
	}

	/**
	 *	Check if object is valid.
	 */
	inline bool isValid(void) const {
		return !(this->mhalfsize.x() != 0.0f || this->mhalfsize.y() != 0.0f
				|| this->mhalfsize.z() != 0.0f);
	}

	/**
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
	 *	Compute minimum position.
	 *	@Return
	 */
	inline HCVector3 min(void) const {
		return this->getCenter() - this->getSize();
	}

	/**
	 *	Compute max position.
	 *	@Return
	 */
	inline HCVector3 max(void) const {
		return this->getCenter() + this->getSize();
	}

	/**
	 *	Get half size.
	 *	@Return half size vector.
	 */
	inline const HCVector3& getSize(void) const {
		return this->mhalfsize;
	}

	/**
	 *	Set half size.
	 */
	void setSize(const HCVector3& size) {
		this->mhalfsize = size;
	}

	/**
	 *	Get center position.
	 *	@Return
	 */
	inline const HCVector3& getCenter(void) const {
		return this->mcenter;
	}
	inline void setCenter(const HCVector3& center) {
		this->mcenter = center;
	}

	/**
	 *	@Return
	 */
	bool intersect(const HCAABB& bounds);

	/**
	 *	@Return
	 */
	bool HCAPIENTRY contains(const HCVector3& point, const HCVector3 worldPosition =
			HCVector3());

	/**
	 *	@Return
	 */
	bool HCAPIENTRY contains(const HCAABB& bounds);

	/**
	 *	@Return
	 */
	HCVector3 HCAPIENTRY getVertexN(HCVector3& normal) const;

	/**
	 *	@Return
	 */
	HCVector3 HCAPIENTRY getVertexP(HCVector3& normal) const;

	/**
	 *	@Return
	 */
	friend std::istream &operator>>(std::istream &is, HCVector3& t);

	/**
	 *	@Return
	 */
	friend std::ostream &operator<<(std::ostream &os, const HCVector3& t);

	/**
	 *	@Return
	 */
	HCAABB& operator=(const HCAABB& bound);

	/**
	 *	@Return
	 */
	friend HCAABB& operator*=(const HCAABB& bound, float scalar);

	/**
	 *	@Return
	 */
	friend HCAABB& operator/=(const HCAABB& bound, float scalar);

	/**
	 *	@Return
	 */
	bool operator==(const HCAABB& bound);

	/**
	 *	@Return
	 */
	bool operator!=(const HCAABB& bound);

private:	/*	Attributes.	*/

	HCVector3 mhalfsize;	/*	half size of the box.	*/
	HCVector3 mcenter;	/*	center of the box.	*/

};


#endif
