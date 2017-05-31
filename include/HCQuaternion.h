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
 *	Quaternion.
 */
class HCDECLSPEC HCQuaternion{
	friend class HCMatrix4x4;
public:

	HCQuaternion(void);
	HCQuaternion(const HCQuaternion& quaternion);
	HCQuaternion(float w, float x, float y, float z);
	HCQuaternion(float pitch, float yaw, float roll);

	float x(void)const;
	float y(void)const;
	float z(void)const;
	float w(void)const;

	void setW(float w);
	void setX(float x);
	void setY(float y);
	void setZ(float z);

	/**
	 *	Set
	 */
	void set(float w, float x, float y, float z);

	/**
	 *	@Return
	 */
	HCVector3 up(void) const;
	HCVector3 forward(void) const;

	/**
	 *
	 *	@Return
	 */
	HCVector3 getVector(void) const;

	/**
	 *
	 *	@Return
	 */
	HCVector3 getVector(const HCVector3& vector) const;

	/**
	 *	@Return
	 */
	float magnitude(void) const;
	float magnitudeSquared(void);

	/**
	 *	@Return
	 */
	friend float dot(const HCQuaternion& lh, const HCQuaternion& rh);

	/**
	 *	Normalize quaternion.
	 */
	void makeUnitQuaternion(void);

	/**
	 *	@Return
	 */
	HCQuaternion normalize(void) const;

	/**
	 *
	 *	@Return
	 */
	HCQuaternion conjugate(void) const;

	/**
	 *
	 *	@Return
	 */
	HCQuaternion inverse(void) const;

	/**
	 *	@Return
	 */
	HCMatrix4x4 getMatrix4x4(void) const;

	/**
	 *	@Return
	 */
	HCMatrix3x3 getMatrix3x3(void) const;

	/**
	 *	@Return
	 */
	float operator[](int i) const;
	float& operator[](int i);

	/**
	 *	@Return stream.
	 */
	friend std::istream &operator>>(std::istream &is, HCQuaternion& t);
	friend std::ostream &operator<<(std::ostream &os, const HCQuaternion& t);

	/**
	 *	@Return
	 */
	friend HCQuaternion operator+(const HCQuaternion& lh, const HCQuaternion& rh);
	friend HCQuaternion operator-(const HCQuaternion& lh, const HCQuaternion& rh);

	/**
	 *
	 *	@Return
	 */
	friend HCQuaternion operator*(const HCQuaternion& lh, const HCQuaternion& rh);
	friend HCQuaternion operator*(const HCQuaternion& lh, const HCVector3& rh);
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
	 *	@Return
	 */
	friend bool operator==(const HCQuaternion& v1, const HCQuaternion& v2);
	friend bool operator!=(const HCQuaternion& v1, const HCQuaternion& v2);

	/**
	 *	Get rotation of each axis in
	 *	radius.
	 */
	float getPitch(void) const;
	float getYaw(void) const;
	float getRoll(void) const;

private:	/*	Attributes.	*/

	hpmquatf e;

public:	/*	Static utility methods.	*/

	/**
	 *	@Return
	 */
	static HCQuaternion lookRotation(const HCVector3& target, const HCVector3& up);

	/**
	 *
	 *	@Return
	 */
	static HCQuaternion lookAt(const HCVector3& target, const HCVector3& up);

	/**
	 *
	 *	@Return
	 */
	static HCQuaternion createQuaternionOfAxis(float pitch, float yaw,
			float roll);

	/**
	 *
	 *	@Return
	 */
	static HCQuaternion createQuaternionOfAxis(const HCVector3& axis);

	/**
	 *
	 *	@Return
	 */
	static HCQuaternion createFromAxisAngle(const HCVector3& axis, float angle);

	/**
	 *
	 *	@Return
	 */
	static HCQuaternion createQuaternionOfDirection(HCVector3& direction);

	/**
	 *
	 *	@Return
	 */
	static HCQuaternion lerp(const HCQuaternion& from, const HCQuaternion& to,
			float speed);

	/**
	 *
	 *	@Return
	 */
	static HCQuaternion slerp(const HCQuaternion& from, const HCQuaternion& to,
			float speed);

	/**
	 *
	 *	@Return
	 */
	static HCQuaternion identity(void);

};

#endif
