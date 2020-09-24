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
	class HCDECLSPEC HCVector3 {
		friend class HCMatrix4x4;
		friend class HCQuaternion;
	public:
		HCVector3(void) = default;
		HCVector3(float val);
		HCVector3(float e0, float e1, float e2);
		HCVector3(const HCVector3& v);

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
		const HCVector3& operator+(void) const;
		HCVector3 operator-(void) const;

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
		HCVector3 HCAPIENTRY normalize(void) const;

		/**
		 * Check equality.
		 * @return
		 */
		friend bool operator==(const HCVector3& v1, const HCVector3& v2);
		friend bool operator!=(const HCVector3& v1, const HCVector3& v2);

		/**
		 * Create input stream for creating vector
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, HCVector3& t);

		/**
		 * Create output stream of vector value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const HCVector3& t);

		/**
		 * @return
		 */
		friend HCVector3 operator+(const HCVector3& v1, const HCVector3& v2);
		friend HCVector3 operator-(const HCVector3& v1, const HCVector3& v2);
		friend HCVector3 operator/(const HCVector3& vec, float scalar);
		friend HCVector3 operator*(const HCVector3& vec, float scalar);
		friend HCVector3 operator*(float scalar, const HCVector3& vec);
		friend HCVector3 operator*(const HCVector3& vec1, const HCVector3& vec2);

		/**
		 *
		 */
		HCVector3& operator=(const HCVector3& v2);
		HCVector3& operator+=(const HCVector3& v2);
		HCVector3& operator-=(const HCVector3& v2);
		HCVector3& operator/=(float scalar);
		HCVector3& operator*=(float scalar);

		/**
		 *
		 * @param v
		 * @return
		 */
		friend HCVector3 HCAPIENTRY unitVector3(const HCVector3& v);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend HCVector3 HCAPIENTRY minVec(const HCVector3& v1,
				const HCVector3& v2);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend HCVector3 HCAPIENTRY maxVec(const HCVector3& v1,
				const HCVector3& v2);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend HCVector3 HCAPIENTRY cross(const HCVector3& v1, const HCVector3& v2);

		/**
		 *
		 * @param vector
		 * @param normal
		 * @return
		 */
		friend HCVector3 HCAPIENTRY reflection(const HCVector3& vector,
				const HCVector3& normal);

		/**
		 *
		 * @param v1
		 * @param normal
		 * @param refraction
		 * @return
		 */
		friend HCVector3 HCAPIENTRY refraction(const HCVector3& v1,
				const HCVector3& normal, float refraction);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend float HCAPIENTRY dot(const HCVector3& v1, const HCVector3& v2);

		/**
		 *
		 * @param v1
		 * @param v2
		 * @param v3
		 * @return
		 */
		friend float HCAPIENTRY tripleProduct(const HCVector3& v1,
				const HCVector3& v2, const HCVector3& v3);

		/**
		 *
		 * @param normal
		 * @return
		 */
		friend HCVector3 HCAPIENTRY tangent(const HCVector3& normal);

		/**
		 *
		 * @param normal
		 * @param tangent
		 * @return
		 */
		friend HCVector3 HCAPIENTRY biTangent(const HCVector3& normal,
				const HCVector3& tangent);

		/**
		 *
		 * @param normal
		 * @param tangent
		 * @return
		 */
		friend HCVector3 HCAPIENTRY biNormal(const HCVector3& normal,
				const HCVector3& tangent);

	private:	/*	Private method.	*/

		hpmvec3f e;

	public:	/*	Static methods.	*/

		/**
		 * Create predefined vector3.
		 */
		inline static HCVector3 forward(void){return HCVector3(0.0f, 0.0f, 1.0f);}
		inline static HCVector3 back(void){return HCVector3(0.0f, 0.0f, -1.0f);}
		inline static HCVector3 right(void){return HCVector3(1.0f, 0.0f, 0.0f);}
		inline static HCVector3 left(void){return HCVector3(-1.0f, 0.0f, 0.0f);}
		inline static HCVector3 up(void){return HCVector3(0.0f, 1.0f, 0.0f);}
		inline static HCVector3 down(void){return HCVector3(0.0f, -1.0f, 0.0f);}
		inline static HCVector3 zero(void){return HCVector3(0.0f, 0.0, 0.0f);}

		/**
		 * Linear interpolation between v1 and v2 based on t.
		 * @param vec1
		 * @param vec2
		 * @param t [0,1]
		 * @return interpolated position.
		 */
		static HCVector3 HCAPIENTRY lerp(const HCVector3& vec1,
				const HCVector3& vec2, float t);

		/**
		 * Spherical interpolation.
		 * @param vec1 start position.
		 * @param vec2 end position.
		 * @param t [0,1]
		 * @return interpolated position.
		 */
		static HCVector3 HCAPIENTRY slerp(const HCVector3& vec1,
				const HCVector3& vec2, float t);
	};
}

#endif
