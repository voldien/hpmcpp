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
#ifndef _HC_VECTOR2_H_
#define _HC_VECTOR2_H_ 1
#include "HCTypes.h"

/**
 *	Vector2.
 */
class HCDECLSPEC HCVector2 {
public:
	HCVector2(void);
	HCVector2(float val);
	HCVector2(float m0, float m1);
	HCVector2(const HCVector2& v);

	/**
	 *
	 */
	HCVector2 operator-(void) const;

	/**
	 *
	 */
	inline float operator[](int i) const {
		return this->m[i];
	}
	inline float& operator[](int i) {
		return this->m[i];
	}

	float* operator*(void) {
		return (float*) this;
	}

	/**
	 *	Compute length.
	 */
	float length(void) const;
	float squaredLength(void) const;

	void makeUnitVector(void);

	inline void setX(float _x) {
		m[0] = _x;
	}
	inline void setY(float _y) {
		m[1] = _y;
	}

	inline float x(void) const {
		return m[0];
	}
	inline float y(void) const {
		return m[1];
	}

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

	HCVector2 normalize(void) const;

	/**
	 *	@Return
	 */
	friend bool operator==(const HCVector2& v1, const HCVector2& v2);
	friend bool operator!=(const HCVector2& v1, const HCVector2& v2);

	/**
	 *	@Return
	 */
	friend std::istream &operator>>(std::istream &is, HCVector2& t);
	friend std::ostream &operator<<(std::ostream &os, const HCVector2& t);

	/**
	 *	@Return
	 */
	friend HCVector2 operator+(const HCVector2& v1, const HCVector2& v2);
	friend HCVector2 operator-(const HCVector2& v1, const HCVector2& v2);
	friend HCVector2 operator/(const HCVector2& vec, float scalar);
	friend HCVector2 operator*(const HCVector2& vec, float scalar);
	friend HCVector2 operator*(float scalar, const HCVector2& vec);
	friend HCVector2 operator*(const HCVector2& vec1, const HCVector2& vec2);

	/**
	 *	@Return
	 */
	HCVector2& operator=(const HCVector2& v2);
	HCVector2& operator+=(const HCVector2& v2);
	HCVector2& operator-=(const HCVector2& v2);
	HCVector2& operator/=(float scalar);
	HCVector2& operator*=(float scalar);
	HCVector2& operator*=(const HCVector2& vec2);

	/**
	 *	@Return
	 */
	friend HCVector2 unitVector3(const HCVector2& v);
	friend HCVector2 minVec(const HCVector2& v1, const HCVector2& v2);
	friend HCVector2 maxVec(const HCVector2& v1, const HCVector2& v2);
	friend HCVector2 reflection(const HCVector2& vector, const HCVector2& normal);
	friend float dot(const HCVector2& v1, const HCVector2& v2);

private:	/*	Attributes.	*/

	hpmvec2f m;

public:

	/**
	 *	@Return
	 */
	static HCVector2 zero(void) {
		return HCVector2(0.0f);
	}
};

#endif
