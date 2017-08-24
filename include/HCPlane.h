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
	inline HCPlane(void) {
	}
	inline HCPlane(const HCVector3& normal) {
		this->normal = normal;
		this->d = 0;
	}
	HCPlane(const HCVector3& point, const HCVector3& normal) {
		this->setNormalAndPoint(normal, point);
	}
	inline HCPlane(const HCPlane& plane) {
		*this = plane;
	}

	/**
	 *	@Return
	 */
	inline HCVector3 getNormal(void){
		return this->normal;
	}

	/**
	 *	@Return
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
	 *
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
	 *
	 */
	friend std::istream &operator>>(std::istream& is, HCPlane& t);

	/**
	 *
	 */
	friend std::ostream &operator<<(std::ostream& is, const HCPlane& t);


	/**
	 *	Compare 
	 *	@Return true if equal.
	 */
	friend bool operator==(const HCPlane& o1, const HCPlane& o2);

	/**
	 *	Compare 
	 *	@Return true if equal.
	 */
	friend bool operator!=(const HCPlane& o1, const HCPlane& o2);

protected:	/*	Attributes.	*/

	HCVector3 normal;		/*	*/
	float d;			/*	*/

public:
	/*	Static methods.	*/

	/**
	 *	Create plane from points.
	 *	@Return
	 */
	static HCPlane fromPoints(const HCVector3& v1, const HCVector3& v2,
			const HCVector3& v3) {
		HCPlane tmp;
		HCVector3 e1 = v2 - v1;
		HCVector3 e2 = v3 - v1;

		tmp.normal = cross(e1, e2).normalize();
		tmp.d = -dot(tmp.normal, v2);
		return tmp;
	}

};

#endif
