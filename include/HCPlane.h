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
#ifndef _HPMCPP_PLANE_H_
#define _HPMCPP_PLANE_H_ 1
#include"HCVector3.h"
#include<iostream>

/**
 *
 */
class HCDECLSPEC HCPlane {
public:
	HCPlane(void);
	HCPlane(const HCVector3& normal);
	HCPlane(const HCVector3& point, const HCVector3& normal);
	HCPlane(const HCPlane& plane);

	/**
	 *	Get normal of plane.
	 *	@Return normalized normal vector.
	 */
	inline HCVector3 getNormal(void){
		return this->normal;
	}

	/**
	 *	Get normal of plane.
	 *	@Return normalized normal vector.
	 */
	inline const HCVector3& getNormal(void) const {
		return this->normal;
	}

	/**
	 *	Set plane normal.
	 */
	inline void setNormal(const HCVector3& normal) {
		this->normal = normal;
	}

	/**
	 *	Compute distance.
	 *	@Return
	 */
	inline float distance(const HCVector3& point) const {
		return dot(normal, point) + d;
	}

	/**
	 *	Get distance.
	 *	@Return
	 */
	inline float distance(void) const {
		return this->d;
	}

	/**
	 *	Get point.
	 *	@Return
	 */
	inline HCVector3 getPoint(void) const {
		return d * this->getNormal();
	}

	/**
	 *	Set normal and point and
	 *	compute internal values.
	 */
	void setNormalAndPoint(const HCVector3& normal, const HCVector3& point) {
		this->normal = normal.normalize();
		this->d = -dot(this->normal, point);
	}

	/**
	 *	Construct plane.
	 */
	void set3DPoints(const HCVector3& v1, const HCVector3& v2, const HCVector3& v3) {
		this->normal = cross((v1 - v2), (v1 - v3)).normalize();
		this->d = -dot(this->normal, v2);
	}

	/**
	 *	@Return stream reference.
	 */
	friend std::istream &operator>>(std::istream& is, HCPlane& t);

	/**
	 *	@Return stream reference.
	 */
	friend std::ostream &operator<<(std::ostream& is, const HCPlane& t);


	/**
	 *	Compare if plane equal each other.
	 *	@Return true if equal.
	 */
	friend bool operator==(const HCPlane& o1, const HCPlane& o2);

	/**
	 *	Compare if plane not equal each other.
	 *	@Return true if equal.
	 */
	friend bool operator!=(const HCPlane& o1, const HCPlane& o2);

protected:	/*	Attributes.	*/

	HCVector3 normal;   /*	*/
	float d;            /*	*/

public:
	/*	Static methods.	*/

	/**
	 *	Create plane from points.
	 *	@Return HCPlane object.
	 */
	static HCPlane HCAPIENTRY fromPoints(const HCVector3& v1, const HCVector3& v2,
			const HCVector3& v3);

};

#endif
