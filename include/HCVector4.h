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
#ifndef _HPMCPP_VECTOR4_H_
#define _HPMCPP_VECTOR4_H_ 1
#include "HCTypes.h"

/**
 *	Vector4 class. Contains
 *	x, y, z, w component. Where the
 *	size of the object is 128 bit.
 */
class HCDECLSPEC HCVector4{
public:

	HCVector4(void);
	HCVector4(float val);
	HCVector4(float m0, float m1, float m2, float m3);
	HCVector4(const HCVector4& v);

	/**
	 *
	 */
	float HCAPIFASTENTRY x(void) const;
	float HCAPIFASTENTRY y(void) const;
	float HCAPIFASTENTRY z(void) const;
	float HCAPIFASTENTRY w(void) const;

	/**
	 *
	 */
	void HCAPIFASTENTRY setX(float x);
	void HCAPIFASTENTRY setY(float y);
	void HCAPIFASTENTRY setZ(float z);
	void HCAPIFASTENTRY setW(float w);

	/**
	 *	Get component by index.
	 */
	float operator[](int i) const;
	float& operator[](int i);

	/**
	 *	Negate vector.
	 *	@Return negated vector.
	 */
	HCVector4 operator-(void) const;

	/**
	 *	Compute length of vector.
	 *	@Return non-negativ number.
	 */
	float HCAPIFASTENTRY length(void) const;

	/**
	 *	Compute length of vector.
	 *	@Return non-negativ number.
	 */
	float HCAPIFASTENTRY squaredLength(void) const;

	/**
	 *	Normalize current vector.
	 */
	void HCAPIENTRY makeUnitVector(void);

	/**
	 *	@Return
	 */
	float HCAPIFASTENTRY minComponent(void) const;
	float HCAPIFASTENTRY maxComponent(void) const;
	float HCAPIFASTENTRY maxAbsComponent(void) const;
	float HCAPIFASTENTRY minAbsComponent(void) const;

	/**
	 *  Create nomralized copy.
	 *
	 *	@Return normalize vector of current vector.
	 */
	HCVector4 HCAPIENTRY normalize(void) const;

	/**
	 *  Equality
	 *	@Return logic
	 */
	friend bool operator==(const HCVector4& v1, const HCVector4& v2);
	friend bool operator!=(const HCVector4& v1, const HCVector4& v2);

	/**
	 *	Create input stream for creating vector
	 *	from input stream.
	 *	@Return stream reference.
	 */
	friend std::istream &operator>>(std::istream &is, HCVector4& t);

	/**
	 *	Create output stream of vector value.
	 *	@Return stream reference.
	 */
	friend std::ostream &operator<<(std::ostream &os, const HCVector4& t);

	friend HCVector4 operator+(const HCVector4& v1, const HCVector4& v2);
	friend HCVector4 operator-(const HCVector4& v1, const HCVector4& v2);
	friend HCVector4 operator/(const HCVector4& vec, float scalar);
    friend HCVector4 operator/(const HCVector4& v1, const HCVector4& v2);
	friend HCVector4 operator*(const HCVector4& vec, float scalar);
	friend HCVector4 operator*(float scalar, const HCVector4& vec);

	HCVector4& operator=(const HCVector4& v2);
	HCVector4& operator+=(const HCVector4& v2);
	HCVector4& operator-=(const HCVector4& v2);
	HCVector4& operator/=(float scalar);
	HCVector4& operator*=(float scalar);

	/**
	 * Compute unit vector.
	 * @param v
	 * @return
	 */
	friend HCVector4 HCAPIENTRY unitVector3(const HCVector4& v);

	/**
	 *
	 * @param v1
	 * @param v2
	 * @return
	 */
	friend HCVector4 HCAPIENTRY minVec(const HCVector4& v1, const HCVector4& v2);

	/**
	 *	@Return
	 */
	friend HCVector4 HCAPIENTRY maxVec(const HCVector4& v1, const HCVector4& v2);

	/**
	 *	@Return
	 */
	friend float HCAPIENTRY dot(const HCVector4& v1, const HCVector4& v2);

protected:	/*	Attributes.	*/

		hpmvec4f e;

public:	/*	Static methods.	*/

	/**
	 * Linear interpolation.
	 * @param vec1
	 * @param vec2
	 * @param speed
	 * @return
	 */
	static HCVector4 HCAPIENTRY lerp(const HCVector4& vec1, const HCVector4& vec2, float speed);

	/**
	 * Spherical interpolation.
	 * @param vec1
	 * @param vec2
	 * @param speed
	 * @return
	 */
	static HCVector4 HCAPIENTRY slerp(const HCVector4& vec1, const HCVector4& vec2, float speed);
};

#endif
