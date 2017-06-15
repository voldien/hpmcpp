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
 *	Vector4
 */
class HCDECLSPEC HCVector4{
public:

	HCVector4(void);
	HCVector4(float val);
	HCVector4(float m0, float m1, float m2, float m3);
	HCVector4(const HCVector4& v);

	float x(void) const;
	float y(void) const;
	float z(void) const;
	float w(void) const;

	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void setW(float w);

	/**
	 *	Get component by index.
	 */
	float operator[](int i) const;
	float& operator[](int i);

	/**
	 *	Negate vector.
	 */
	HCVector4 operator-(void) const;

	/**
	 *	Compute length of vector.
	 *	@Return
	 */
	float length(void) const;
	float squaredLength(void) const;

	/**
	 *	Normalize current vector.
	 */
	void makeUnitVector(void);

	/**
	 *	@Return
	 */
	float minComponent(void) const;
	float maxComponent(void) const;
	float maxAbsComponent(void) const;
	float minAbsComponent(void) const;
	int indexOfMinComponent(void) const;
	int indexOfMaxComponent(void) const;
	int indexOfMinAbsComponent(void) const;
	int indexOfMaxAbsComponent(void) const;

	/**
	 *	@Return normalize vector of current vector.
	 */
	HCVector4 normalize(void) const;

	/**
	 *
	 *	@Return logic
	 */
	friend bool operator==(const HCVector4& v1, const HCVector4& v2);
	friend bool operator!=(const HCVector4& v1, const HCVector4& v2);

	/**
	 *	@Return stream.
	 */
	friend std::istream &operator>>(std::istream &is, HCVector4& t);
	friend std::ostream &operator<<(std::ostream &os, const HCVector4& t);

	/**
	 *
	 *	@Return
	 */
	friend HCVector4 operator+(const HCVector4& v1, const HCVector4& v2);
	friend HCVector4 operator-(const HCVector4& v1, const HCVector4& v2);
	friend HCVector4 operator/(const HCVector4& vec, float scalar);
	friend HCVector4 operator*(const HCVector4& vec, float scalar);
	friend HCVector4 operator*(float scalar, const HCVector4& vec);

	/**
	 *
	 *	@Return
	 */
	HCVector4& operator=(const HCVector4& v2);
	HCVector4& operator+=(const HCVector4& v2);
	HCVector4& operator-=(const HCVector4& v2);
	HCVector4& operator/=(float scalar);
	HCVector4& operator*=(float scalar);

	/**
	 *
	 *	@Return
	 */
	friend HCVector4 unitVector3(const HCVector4& v);
	friend HCVector4 minVec(const HCVector4& v1, const HCVector4& v2);
	friend HCVector4 maxVec(const HCVector4& v1, const HCVector4& v2);
	friend HCVector4 reflection(const HCVector4& vector, const HCVector4& normal);
	friend float dot(const HCVector4& v1, const HCVector4& v2);

//protected:	/*	Attributes.	*/

		hpmvec4f e;

public:	/*	Static methods.	*/

	/**
	 *	@Return
	 */
	static HCVector4 lerp(const HCVector4& vec1, const HCVector4& vec2, float speed);

	/**
	 *	@Return
	 */
	static HCVector4 slerp(const HCVector4& vec1, const HCVector4& vec2, float speed);
};

#endif
