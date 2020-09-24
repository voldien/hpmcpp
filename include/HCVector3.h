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
#ifndef _HPMCPP_VECTOR_3D_H_
#define _HPMCPP_VECTOR_3D_H_ 1
#include "HCTypes.h"

namespace hpmcpp {
	/**
	 * Vector3 class. Contains
	 * x, y, z component. Where the
	 * size of the object is 128 bit.
	 */
	class HCDECLSPEC Vector3 {
		friend class Matrix4x4;
		friend class Quaternion;
	public:
		Vector3(void) = default;
		Vector3(float val);
		Vector3(float e0, float e1, float e2);
		Vector3(const Vector3& v);

		/**
		 * Get individual component of vector.
		 * @return
		 */
		float HCAPIFASTENTRY x(void) const;
		float HCAPIFASTENTRY y(void) const;
		float HCAPIFASTENTRY z(void) const;

		/**
		 * Set individual
		 */
		void HCAPIFASTENTRY setX(float _x);
		void HCAPIFASTENTRY setY(float _y);
		void HCAPIFASTENTRY setZ(float _z);

		/**
		 *
		 * @return
		 */
		const Vector3& operator+(void) const;
		Vector3 operator-(void) const;

		/**
		 *
		 * @param i
		 * @return
		 */
		float operator[](int i) const;
		float& operator[](int i);
		inline operator float*(void) {
			return (float*) this;
		}

		/**
		 * Compute length.
		 * @return non-negative number.
		 */
		float HCAPIENTRY length(void) const;

		/**
		 * Compute square length.
		 * @return non-negative number.
		 */
		float HCAPIENTRY squaredLength(void) const;

		/**
		 * Make vector to a unite vector.
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
		 * Normalize vector.
		 * @return normalized vector.
		 */
		Vector3 HCAPIENTRY normalize(void) const;

		/**
		 * Check equality.
		 * @return
		 */
		friend bool operator==(const Vector3& v1, const Vector3& v2);
		friend bool operator!=(const Vector3& v1, const Vector3& v2);

		/**
		 * Create input stream for creating vector
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Vector3& t);

		/**
		 * Create output stream of vector value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Vector3& t);

		/**
		 * @return
		 */
		friend Vector3 operator+(const Vector3& v1, const Vector3& v2);
		friend Vector3 operator-(const Vector3& v1, const Vector3& v2);
		friend Vector3 operator/(const Vector3& vec, float scalar);
		friend Vector3 operator*(const Vector3& vec, float scalar);
		friend Vector3 operator*(float scalar, const Vector3& vec);
		friend Vector3 operator*(const Vector3& vec1, const Vector3& vec2);

		/**
		 *
		 */
		Vector3& operator=(const Vector3& v2);
		Vector3& operator+=(const Vector3& v2);
		Vector3& operator-=(const Vector3& v2);
		Vector3& operator/=(float scalar);
		Vector3& operator*=(float scalar);

		/**
		 *
		 * @param v
		 * @return
		 */
		friend Vector3 HCAPIENTRY unitVector3(const Vector3& v);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector3 HCAPIENTRY minVec(const Vector3& v1,
				const Vector3& v2);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector3 HCAPIENTRY maxVec(const Vector3& v1,
				const Vector3& v2);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector3 HCAPIENTRY cross(const Vector3& v1, const Vector3& v2);

		/**
		 *
		 * @param vector
		 * @param normal
		 * @return
		 */
		friend Vector3 HCAPIENTRY reflection(const Vector3& vector,
				const Vector3& normal);

		/**
		 *
		 * @param v1
		 * @param normal
		 * @param refraction
		 * @return
		 */
		friend Vector3 HCAPIENTRY refraction(const Vector3& v1,
				const Vector3& normal, float refraction);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend float HCAPIENTRY dot(const Vector3& v1, const Vector3& v2);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @param v3
		 * @return
		 */
		friend float HCAPIENTRY tripleProduct(const Vector3& v1,
				const Vector3& v2, const Vector3& v3);

		/**
		 *
		 * @param normal
		 * @return
		 */
		friend Vector3 HCAPIENTRY tangent(const Vector3& normal);

		/**
		 *
		 * @param normal
		 * @param tangent
		 * @return
		 */
		friend Vector3 HCAPIENTRY biTangent(const Vector3& normal,
				const Vector3& tangent);

		/**
		 *
		 * @param normal
		 * @param tangent
		 * @return
		 */
		friend Vector3 HCAPIENTRY biNormal(const Vector3& normal,
				const Vector3& tangent);

	private:	/*	Private method.	*/

		hpmvec3f e;

	public:	/*	Static methods.	*/

		/**
		 * Create predefined vector3.
		 */
		inline static Vector3 forward(void){return Vector3(0.0f, 0.0f, 1.0f);}
		inline static Vector3 back(void){return Vector3(0.0f, 0.0f, -1.0f);}
		inline static Vector3 right(void){return Vector3(1.0f, 0.0f, 0.0f);}
		inline static Vector3 left(void){return Vector3(-1.0f, 0.0f, 0.0f);}
		inline static Vector3 up(void){return Vector3(0.0f, 1.0f, 0.0f);}
		inline static Vector3 down(void){return Vector3(0.0f, -1.0f, 0.0f);}
		inline static Vector3 zero(void){return Vector3(0.0f, 0.0, 0.0f);}

		/**
		 * Linear interpolation between v1 and v2 based on t.
		 * @param vec1
		 * @param vec2
		 * @param t [0,1]
		 * @return interpolated position.
		 */
		static Vector3 HCAPIENTRY lerp(const Vector3& vec1,
				const Vector3& vec2, float t);

		/**
		 * Spherical interpolation.
		 * @param vec1 start position.
		 * @param vec2 end position.
		 * @param t [0,1]
		 * @return interpolated position.
		 */
		static Vector3 HCAPIENTRY slerp(const Vector3& vec1,
				const Vector3& vec2, float t);
	};
}

#endif
