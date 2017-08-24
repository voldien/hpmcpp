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
#ifndef _HPMCPP_RAY_H_
#define _HPMCPP_RAY_H_ 1
#include"HCVector3.h"

/**
 *	Ray data type. Contains
 *	a position and a direction.
 */
class HCDECLSPEC HCRay {
public:
	HCRay(void);
	HCRay(const HCVector3& origin, const HCVector3& direction);
	HCRay(const HCRay& ray);

	/**
	 *	@Return get origin position.
	 */
	inline const HCVector3& getOrigin(void) const {
		return this->m[0];
	}

	/**
	 *	Set origin position.
	 */
	inline void setOrigin(const HCVector3& origin) {
		this->m[0] = origin;
	}

	/**
	 *	Get direction.
	 *
	 *	@Return normalized direction.
	 */
	inline const HCVector3& getDirection(void) const {
		return this->m[1];
	}

	/**
	 *	Set direction vector.
	 *
	 *	\direction has to be a normalized vector.
	 */
	inline void setDirection(const HCVector3& direction) {
		this->m[1] = direction;
	}

	/**
	 *	Get position from distance from point
	 *	in respect to direction.
	 *	@Return point on the ray.
	 */
	inline HCVector3 pointAtParameter(float t) const {
		return this->getOrigin() + t * this->getDirection();
	}

private:
	/*	Attributes.	*/

	/**
	 *	#0 origin
	 *	#1 direction
	 */
	HCVector3 m[2];

};

inline HCRay::HCRay(void) {
}

inline HCRay::HCRay(const HCVector3& origin, const HCVector3& direction) {
	this->setOrigin(origin);
	this->setDirection(direction);
}

inline HCRay::HCRay(const HCRay& ray) {
	this->setOrigin(ray.getOrigin());
	this->setDirection(ray.getDirection());
}

#endif
