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
#ifndef _HPMCPP_QUATERNION_H_
#define _HPMCPP_QUATERNION_H_ 1
#include "HCTypes.h"

/**
 *	Quaternion class. Contains
 *	w, x, y, z component. Where the
 *	size of the object is 128 bit.
 */
class HCDECLSPEC HCQuaternion{
	friend class HCMatrix4x4;
public:

	HCQuaternion(void);
	HCQuaternion(const HCQuaternion& quaternion);
	HCQuaternion(float w, float x, float y, float z);
	HCQuaternion(float pitch, float yaw, float roll);

	/**
	 *	Get individual component.
	 */
	float HCAPIFASTENTRY x(void) const;
	float HCAPIFASTENTRY y(void) const;
	float HCAPIFASTENTRY z(void) const;
	float HCAPIFASTENTRY w(void) const;

	/**
	 *	Set individual component.
	 */
	void HCAPIFASTENTRY setW(float w);
	void HCAPIFASTENTRY setX(float x);
	void HCAPIFASTENTRY setY(float y);
	void HCAPIFASTENTRY setZ(float z);

	/**
	 *	Set all quaternion components.
	 */
	void HCAPIENTRY set(float w, float x, float y, float z);

	/**
	 *	Get up and forward vector
	 *	of quaternion.
	 *
	 *	@Return normalized direction vector.
	 */
	HCVector3 HCAPIENTRY up(void) const;
	HCVector3 HCAPIENTRY forward(void) const;

	/**
	 *	Get
	 *	@Return
	 */
	HCVector3 HCAPIENTRY getVector(void) const;

	/**
	 *	Get direction vector from direction
	 *	vector.
	 *	@Return normalized direction vector.
	 */
	HCVector3 HCAPIENTRY getVector(const HCVector3& direction) const;

	/**
	 *	Compute the magnitude.
	 *
	 *	@Return non-negativ number.
	 */
	float HCAPIENTRY magnitude(void) const;

	/**
	 *	@Return non-negativ number.
	 */
	float HCAPIENTRY magnitudeSquared(void);

	/**
	 *	Compute dot product from two quaternion.
	 *
	 *	@Return
	 */
	friend float HCAPIFASTENTRY dot(const HCQuaternion& lh, const HCQuaternion& rh);

	/**
	 *	Normalize quaternion.
	 */
	void HCAPIENTRY makeUnitQuaternion(void);

	/**
	 *	Compute normalized quaternion.
	 *
	 *	@Return
	 */
	HCQuaternion HCAPIENTRY normalize(void) const;

	/**
	 *	Create conjugate quaternion from
	 *	this quaternion.
	 *
	 *	@Return conjugated quaternion.
	 */
	HCQuaternion HCAPIENTRY conjugate(void) const;

	/**
	 *  Compute quaternion inverse.
	 *	@Return
	 */
	HCQuaternion HCAPIENTRY inverse(void) const;

	/**
	 *  Get element by index.
	 *	@Return
	 */
	float operator[](int i) const;
	float& operator[](int i);

	/**
	 *	Create input stream for creating quaternion
	 *	from input stream.
	 *	@Return stream reference.
	 */
	friend std::istream &operator>>(std::istream &is, HCQuaternion& t);

	/**
	 *	Create output stream of quaternion value.
	 *	@Return stream reference.
	 */
	friend std::ostream &operator<<(std::ostream &os, const HCQuaternion& t);

	/**
	 *
	 * @param lh
	 * @param rh
	 * @return
	 */
	friend HCQuaternion operator+(const HCQuaternion& lh,
	        const HCQuaternion& rh);

	/**
	 *
	 * @param lh
	 * @param rh
	 * @return
	 */
	friend HCQuaternion operator-(const HCQuaternion& lh,
	        const HCQuaternion& rh);

	/**
	 *
	 *	@Return
	 */
	friend HCQuaternion operator*(const HCQuaternion& lh,
	        const HCQuaternion& rh);

	/**
	 *	@Return
	 */
	friend HCQuaternion operator*(const HCQuaternion& lh, const HCVector3& rh);

	/**
	 *	@Return
	 */
	friend HCQuaternion operator*(const HCQuaternion& lh, float rh);

	/**
	 *	@Return
	 */
	HCQuaternion& operator*=(const HCQuaternion& rh);
	HCQuaternion& operator*=(const HCVector3& rh);
	HCQuaternion& operator*=(float rh);

	/**
	 *	@Return
	 */
	HCQuaternion& operator=(const HCQuaternion& rh);

	/**
	 *	Compare quaternion equality by
	 *	checking component wise.
	 *	@Return true if equal, false otherwise.
	 */
	friend bool operator==(const HCQuaternion& v1, const HCQuaternion& v2);
	friend bool operator!=(const HCQuaternion& v1, const HCQuaternion& v2);

	/**
	 *	Get rotation of each axis in
	 *	radius.
	 */
	float HCAPIFASTENTRY getPitch(void) const;

	/**
	 *
	 */
	float HCAPIFASTENTRY getYaw(void) const;

	/**
	 *
	 */
	float HCAPIFASTENTRY getRoll(void) const;

private:	/*	Attributes.	*/

	hpmquatf e;

public:	/*	Static utility methods.	*/

	/**
	 *	Create look rotation quaternion.
	 *
	 *	@Return
	 */
	static HCQuaternion HCAPIENTRY lookRotation(const HCVector3& target,
	        const HCVector3& up);

	/**
	 *  Create quaternion from eular rotation.
	 *
	 *	@Return normalized quaternion.
	 */
	static HCQuaternion HCAPIENTRY createQuaternionOfAxis(float pitch,
	        float yaw, float roll);

	/**
	 *	Create quaternion from eular rotation.
	 *
	 *	@Return normalized quaternion.
	 */
	static HCQuaternion HCAPIENTRY createQuaternionOfAxis(
	        const HCVector3& axis);

	/**
	 *
	 *	@Return normalized quaternion.
	 */
	static HCQuaternion HCAPIENTRY createFromAxisAngle(const HCVector3& axis,
	        float angle);

	/**
	 *  Convert direction to quaternion.
	 *
	 *	@Return normalized quaternion.
	 */
	static HCQuaternion HCAPIENTRY createQuaternionOfDirection(
	        HCVector3& direction);

	/**
	 *	Linear interpolation.
	 *
	 *	@Return normalized quaternion.
	 */
	static HCQuaternion HCAPIENTRY lerp(const HCQuaternion& from,
	        const HCQuaternion& to, float speed);

	/**
	 *	Spherical interpolation.
	 *
	 *	@Return normalized quaternion.
	 */
	static HCQuaternion HCAPIENTRY slerp(const HCQuaternion& from,
	        const HCQuaternion& to, float speed);

	/**
	 *	Create quaternion identity.
	 *	@Return identitiy.
	 */
	static HCQuaternion HCAPIENTRY identity(void);

};

#endif
