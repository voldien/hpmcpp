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
#ifndef _HPMCPP_BOUNDING_SPHERE_H_
#define _HPMCPP_BOUNDING_SPHERE_H_ 1
#include"HCRay.h"
#include"HCVector3.h"

/**
 *
 */
class HCDECLSPEC HCBoundingSphere{
public:
	HCBoundingSphere(void);
	HCBoundingSphere(const HCVector3& center, float radius);
	HCBoundingSphere(const HCBoundingSphere& boundingSphere);

	inline float getRadius(void)const{
		return this->radius;
	}
	inline void setRadius(float radius){
		this->radius = radius;
	}


	inline HCVector3 getCenter(void)const{
		return this->center;
	}
	inline void setCenter(const HCVector3& center){
		this->center = center;
	}

	/**
	 *	@Return
	 */
	bool intersect(const HCBoundingSphere& sphere)const;
	bool contains(const HCBoundingSphere& sphere)const;

	/**
	 *	@Return
	 */
	HCBoundingSphere& operator=(const HCBoundingSphere& bounds);

private:	/*	Private member attributes.	*/

	float radius;		/**/
	HCVector3 center;		/**/

};

#endif
