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

namespace hpmcpp {
	/**
	 * Vector2.
	 */
	class HCDECLSPEC Vector2 {
	public:
		Vector2(void) = default;
		Vector2(float val);
		Vector2(float m0, float m1);
		Vector2(const Vector2& v);

		/**
		 * Negate vector.
		 * @return
		 */
		Vector2& operator-(void) const;

		/**
		 * Get vector component by index.
		 * @return component value.
		 */
		inline float operator[](int i) const;
		/**
		 * Get vector component reference
		 * by index.
		 * @return reference to component.
		 */
		inline float& operator[](int i);

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
		Vector2 normalize(void) const;

		/**
		 * Compare vector equalities.
		 * @return true if vector equal for each component.
		 */
		friend bool operator==(const Vector2& v1, const Vector2& v2);
		/**
		 * Compare vector inequality.
		 * @return true if at least single component is not equal.
		 */
		friend bool operator!=(const Vector2& v1, const Vector2& v2);

		/**
		 * Create input stream for creating vector
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream& operator>>(std::istream &is, Vector2& t);

		/**
		 * Create output stream of vector value.
		 * @return stream reference.
		 */
		friend std::ostream& operator<<(std::ostream &os, const Vector2& t);

		friend Vector2 operator+(const Vector2& v1, const Vector2& v2);
		friend Vector2 operator-(const Vector2& v1, const Vector2& v2);
		friend Vector2 operator/(const Vector2& vec, float scalar);
		friend Vector2 operator*(const Vector2& vec, float scalar);
		friend Vector2 operator*(float scalar, const Vector2& vec);
		friend Vector2 operator*(const Vector2& vec1, const Vector2& vec2);

		Vector2& operator=(const Vector2& v2);
		Vector2& operator+=(const Vector2& v2);
		Vector2& operator-=(const Vector2& v2);
		Vector2& operator/=(float scalar);
		Vector2& operator*=(float scalar);
		Vector2& operator*=(const Vector2& vec2);

		/**
		 *
		 * @param v
		 * @return
		 */
		friend Vector2 unitVector3(const Vector2& v);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector2 minVec(const Vector2& v1, const Vector2& v2);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector2 maxVec(const Vector2& v1, const Vector2& v2);

		/**
		 *
		 * @param vector
		 * @param normal
		 * @return
		 */
		friend Vector2 reflection(const Vector2& vector,
				const Vector2& normal);

		/**
		 * Compute dot product.
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend float dot(const Vector2& v1, const Vector2& v2);

	private:	/*	Attributes.	*/

		hpmvec2f m;

	public:	/*	Static methods.	*/

		/**
		 * Create zero vector.
		 * @return HCVector2 object.
		 */
		static Vector2 zero(void) {
			return Vector2(0.0f);
		}
	};
}

#endif
