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
namespace LIBHPM {
	/**
	 * Vector4 class. Contains
	 * x, y, z, w component. Where the
	 * size of the object is 128 bit.
	 */
	class HCDECLSPEC Vector4 {
	public:

		Vector4(void);
		Vector4(float val);
		Vector4(float m0, float m1, float m2, float m3);
		Vector4(const Vector4& v);

		/**
		 * Get component wise.
		 */
		float HCAPIFASTENTRY x(void) const;
		float HCAPIFASTENTRY y(void) const;
		float HCAPIFASTENTRY z(void) const;
		float HCAPIFASTENTRY w(void) const;

		/**
		 * Set component wise.
		 */
		void HCAPIFASTENTRY setX(float x);
		void HCAPIFASTENTRY setY(float y);
		void HCAPIFASTENTRY setZ(float z);
		void HCAPIFASTENTRY setW(float w);

		/**
		 * Get component by index.
		 */
		float operator[](int i) const;
		float& operator[](int i);

		/**
		 * Negate vector.
		 * @return negated vector.
		 */
		Vector4 operator-(void) const;

		/**
		 * Compute length of vector.
		 * @return non-negativ number.
		 */
		float HCAPIFASTENTRY length(void) const;

		/**
		 * Compute length of vector.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY squaredLength(void) const;

		/**
		 * Normalize current vector.
		 */
		void HCAPIENTRY makeUnitVector(void);

		/**
		 * Get minimum component.
		 * @return number.
		 */
		float HCAPIFASTENTRY minComponent(void) const;

		/**
		 * Get maximum component.
		 * @return number.
		 */
		float HCAPIFASTENTRY maxComponent(void) const;

		/**
		 * Get absolute maximum component.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY maxAbsComponent(void) const;

		/**
		 * Get absolute minimum component.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY minAbsComponent(void) const;

		/**
		 * Create normalized copy.
		 * @return normalize vector of current vector.
		 */
		Vector4 HCAPIENTRY normalize(void) const;

		/**
		 * Equality
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend bool operator==(const Vector4& v1, const Vector4& v2);
		friend bool operator!=(const Vector4& v1, const Vector4& v2);

		/**
		 * Create input stream for creating vector
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Vector4& t);

		/**
		 * Create output stream of vector value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Vector4& t);

		friend Vector4 operator+(const Vector4& v1, const Vector4& v2);
		friend Vector4 operator-(const Vector4& v1, const Vector4& v2);
		friend Vector4 operator/(const Vector4& vec, float scalar);
		friend Vector4 operator/(const Vector4& v1, const Vector4& v2);
		friend Vector4 operator*(const Vector4& vec, float scalar);
		friend Vector4 operator*(float scalar, const Vector4& vec);

		Vector4& operator=(const Vector4& v2);
		Vector4& operator+=(const Vector4& v2);
		Vector4& operator-=(const Vector4& v2);
		Vector4& operator/=(float scalar);
		Vector4& operator*=(float scalar);

		/**
		 * Compute unit vector.
		 * @param v vector.
		 * @return unite vector.
		 */
		friend Vector4 HCAPIENTRY unitVector4(const Vector4& v);

		/**
		 * Compute min vector component.
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector4 HCAPIENTRY minVec(const Vector4& v1, const Vector4& v2);

		/**
		 * Compute max vector component.
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector4 HCAPIENTRY maxVec(const Vector4& v1, const Vector4& v2);

		/**
		 * Computer inner dot product.
		 * @param v1
		 * @param v2
		 * @return inner product.
		 */
		friend float HCAPIENTRY dot(const Vector4& v1, const Vector4& v2);

	protected:	/*	Attributes.	*/

			hpmvec4f e;

	public:	/*	Static methods.	*/

		/**
		 * Linear interpolation.
		 * @param vec1 start position.
		 * @param vec2 end position.
		 * @param speed [0, 1]
		 * @return interpolated position.
		 */
		static Vector4 HCAPIENTRY lerp(const Vector4& vec1, const Vector4& vec2, float speed);

		/**
		 * Spherical interpolation.
		 * @param vec1 start position.
		 * @param vec2 end position.
		 * @param speed [0, 1]
		 * @return interpolated position.
		 */
		static Vector4 HCAPIENTRY slerp(const Vector4& vec1, const Vector4& vec2, float speed);
	};
}

#endif
