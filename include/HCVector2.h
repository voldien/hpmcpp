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
 * Vector2.
 */
class HCDECLSPEC HCVector2 {
public:
	HCVector2(void);
	HCVector2(float val);
	HCVector2(float m0, float m1);
	HCVector2(const HCVector2& v);

	/**
	 * Negate vector.
	 * @return
	 */
	HCVector2& operator-(void) const;

	/**
	 * Get vector component by index.
	 * @return component value.
	 */
	inline float operator[](int i) const {
		return this->m[i];
	}
	/**
	 * Get vector component reference
	 * by index.
	 * @return reference to component.
	 */
	inline float& operator[](int i) {
		return this->m[i];
	}

	/**
	 * Compute length.
	 * @return length in decimal.
	 */
	float length(void) const;

	/**
	 * Compute square length.
	 * @return length in decimal.
	 */
	float squaredLength(void) const;

	/**
	 * Make vector to unit length.
	 */
	void makeUnitVector(void);

	/**
	 * Set vector X component value.
	 */
	void HCAPIFASTENTRY setX(float x);

	/**
	 * Set vector Y component value.
	 */
	void HCAPIFASTENTRY setY(float y);

	/**
	 * Get vector X component value.
	 * @return value of component.
	 */
	float HCAPIFASTENTRY x(void) const;

	/**
	 * Get vector Y component value.
	 * @return value of component.
	 */
	float HCAPIFASTENTRY y(void) const;

	/**
	 * @return
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
	 * Create normalize copy
	 * @return
	 */
	HCVector2 normalize(void) const;

	/**
	 * Compare vector equalities.
	 * @return true if vector equal for each component.
	 */
	friend bool operator==(const HCVector2& v1, const HCVector2& v2);
	/**
	 * Compare vector inequality.
	 * @return true if at least single component is not equal.
	 */
	friend bool operator!=(const HCVector2& v1, const HCVector2& v2);

	/**
	 * Create input stream for creating vector
	 * from input stream.
	 * @return stream reference.
	 */
	friend std::istream& operator>>(std::istream &is, HCVector2& t);

	/**
	 * Create output stream of vector value.
	 * @return stream reference.
	 */
	friend std::ostream& operator<<(std::ostream &os, const HCVector2& t);

	friend HCVector2 operator+(const HCVector2& v1, const HCVector2& v2);
	friend HCVector2 operator-(const HCVector2& v1, const HCVector2& v2);
	friend HCVector2 operator/(const HCVector2& vec, float scalar);
	friend HCVector2 operator*(const HCVector2& vec, float scalar);
	friend HCVector2 operator*(float scalar, const HCVector2& vec);
	friend HCVector2 operator*(const HCVector2& vec1, const HCVector2& vec2);

	HCVector2& operator=(const HCVector2& v2);
	HCVector2& operator+=(const HCVector2& v2);
	HCVector2& operator-=(const HCVector2& v2);
	HCVector2& operator/=(float scalar);
	HCVector2& operator*=(float scalar);
	HCVector2& operator*=(const HCVector2& vec2);

	/**
	 *
	 * @param v
	 * @return
	 */
	friend HCVector2 unitVector3(const HCVector2& v);

	/**
	 *
	 * @param v1
	 * @param v2
	 * @return
	 */
	friend HCVector2 minVec(const HCVector2& v1, const HCVector2& v2);

	/**
	 *
	 * @param v1
	 * @param v2
	 * @return
	 */
	friend HCVector2 maxVec(const HCVector2& v1, const HCVector2& v2);

	/**
	 *
	 * @param vector
	 * @param normal
	 * @return
	 */
	friend HCVector2 reflection(const HCVector2& vector,
	        const HCVector2& normal);

	/**
	 * Compute dot product.
	 * @param v1
	 * @param v2
	 * @return
	 */
	friend float dot(const HCVector2& v1, const HCVector2& v2);

private:	/*	Attributes.	*/

	hpmvec2f m;

public:	/*	Static methods.	*/

	/**
	 * Create zero vector.
	 * @return HCVector2 object.
	 */
	static HCVector2 zero(void) {
		return HCVector2(0.0f);
	}
};

#endif
