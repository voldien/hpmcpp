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
	struct HCDECLSPEC alignas(alignof(hpmvec4f)) Vector4 {
	  public:
		Vector4(void) noexcept ;
		Vector4(float val) noexcept;
		Vector4(float m0, float m1, float m2, float m3) noexcept;
		Vector4(const Vector4 &v) noexcept;

		/**
		 * Get component wise.
		 */
		float HCAPIFASTENTRY x(void) const noexcept;
		float HCAPIFASTENTRY y(void) const noexcept;
		float HCAPIFASTENTRY z(void) const noexcept;
		float HCAPIFASTENTRY w(void) const noexcept;

		/**
		 * Set component wise.
		 */
		void HCAPIFASTENTRY setX(float x) noexcept;
		void HCAPIFASTENTRY setY(float y) noexcept;
		void HCAPIFASTENTRY setZ(float z) noexcept;
		void HCAPIFASTENTRY setW(float w) noexcept;

		/**
		 * Get component by index.
		 */
		float operator[](unsigned int i) const noexcept(noexcept(i > 3));
		float &operator[](unsigned int i) noexcept(noexcept(i > 3));

		/**
		 * Negate vector.
		 * @return negated vector.
		 */
		Vector4 operator-(void) const noexcept;

		/**
		 * Compute length of vector.
		 * @return non-negativ number.
		 */
		float HCAPIFASTENTRY length(void) const noexcept;

		/**
		 * Compute length of vector.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY squaredLength(void) const noexcept;

		/**
		 * Normalize current vector.
		 */
		void HCAPIENTRY makeUnitVector(void);

		/**
		 * Get minimum component.
		 * @return number.
		 */
		float HCAPIFASTENTRY minComponent(void) const noexcept;

		/**
		 * Get maximum component.
		 * @return number.
		 */
		float HCAPIFASTENTRY maxComponent(void) const noexcept;

		/**
		 * Get absolute maximum component.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY maxAbsComponent(void) const noexcept;

		/**
		 * Get absolute minimum component.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY minAbsComponent(void) const noexcept;

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
		friend bool operator==(const Vector4 &v1, const Vector4 &v2);
		friend bool operator!=(const Vector4 &v1, const Vector4 &v2);

		/**
		 * Create input stream for creating vector
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Vector4 &t);

		/**
		 * Create output stream of vector value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Vector4 &t);

		friend Vector4 operator+(const Vector4 &v1, const Vector4 &v2);
		friend Vector4 operator-(const Vector4 &v1, const Vector4 &v2);
		friend Vector4 operator/(const Vector4 &vec, float scalar);
		friend Vector4 operator/(const Vector4 &v1, const Vector4 &v2);
		friend Vector4 operator*(const Vector4 &vec, float scalar);
		friend Vector4 operator*(float scalar, const Vector4 &vec);

		Vector4 &operator=(const Vector4 &v2) noexcept;
		Vector4 &operator+=(const Vector4 &v2) noexcept;
		Vector4 &operator-=(const Vector4 &v2) noexcept;
		Vector4 &operator/=(float scalar) noexcept;
		Vector4 &operator*=(float scalar) noexcept;

		/**
		 * Compute unit vector.
		 * @param v vector.
		 * @return unite vector.
		 */
		friend Vector4 HCAPIENTRY unitVector4(const Vector4 &v);

		/**
		 * Compute min vector component.
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector4 HCAPIENTRY minVec(const Vector4 &v1, const Vector4 &v2) noexcept;

		/**
		 * Compute max vector component.
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector4 HCAPIENTRY maxVec(const Vector4 &v1, const Vector4 &v2) noexcept;

		/**
		 * Computer inner dot product.
		 * @param v1
		 * @param v2
		 * @return inner product.
		 */
		friend float HCAPIENTRY dot(const Vector4 &v1, const Vector4 &v2) noexcept;

	  protected: /*	Attributes.	*/
		hpmvec4f e;

	  public: /*	Static methods.	*/
		/**
		 * Linear interpolation.
		 * @param vec1 start position.
		 * @param vec2 end position.
		 * @param speed [0, 1]
		 * @return interpolated position.
		 */
		static Vector4 HCAPIENTRY lerp(const Vector4 &vec1, const Vector4 &vec2, float speed) noexcept;

		/**
		 * Spherical interpolation.
		 * @param vec1 start position.
		 * @param vec2 end position.
		 * @param speed [0, 1]
		 * @return interpolated position.
		 */
		static Vector4 HCAPIENTRY slerp(const Vector4 &vec1, const Vector4 &vec2, float speed) noexcept;
	};
} // namespace LIBHPM

#endif
