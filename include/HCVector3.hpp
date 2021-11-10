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
#include "HCMath.hpp"
#include "HCTypes.hpp"

namespace LIBHPM {
	/**
	 * Vector3 class. Contains
	 * x, y, z component. Where the
	 * size of the object is 128 bit.
	 */
	struct HCDECLSPEC alignas(alignof(hpmvec3f)) Vector3 {
		friend struct Matrix4x4;
		friend struct Quaternion;

	  public:
		Vector3() = default;
		Vector3(float val) noexcept { hpm_vec4_setf(&this->e, val, val, val, val); }
		Vector3(float e0, float e1, float e2) noexcept { hpm_vec4_setf(&this->e, e0, e1, e2, 0); }
		Vector3(const Vector3 &v) noexcept { *this = v; }

		/**
		 * Get individual component of vector.
		 * @return
		 */
		float HCAPIFASTENTRY x() const noexcept { return hpm_vec4_getxf(this->e); }
		float HCAPIFASTENTRY y() const noexcept { return hpm_vec4_getyf(this->e); }
		float HCAPIFASTENTRY z() const noexcept { return hpm_vec4_getzf(this->e); }

		/**
		 * Set individual
		 */
		void HCAPIFASTENTRY setX(float _x) noexcept { hpm_vec4_setxf(this->e, _x); }
		void HCAPIFASTENTRY setY(float _y) noexcept { hpm_vec4_setyf(this->e, _y); }
		void HCAPIFASTENTRY setZ(float _z) noexcept { hpm_vec4_setzf(this->e, _z); }

		/**
		 *
		 * @return
		 */
		const Vector3 &operator+() const noexcept { return *this; }
		Vector3 operator-() const noexcept {
			Vector3 copy = *this;
			hpm_vec4_negatefv(&copy.e);
			return copy;
		}

		/**
		 *
		 * @param i
		 * @return
		 */
		const float &operator[](int i) const noexcept(noexcept(i >= 2)) {
			const hpmvec4uf *pe = reinterpret_cast<const hpmvec4uf*>(&this->e);
			return pe->vco[i];
		}
		inline operator float *() { return (float *)this; }

		/**
		 * Compute length.
		 * @return non-negative number.
		 */
		float HCAPIENTRY length() const noexcept { return hpm_vec3_lengthfv(&this->e); }

		/**
		 * Compute square length.
		 * @return non-negative number.
		 */
		float HCAPIENTRY squaredLength() const noexcept { return hpm_vec3_lengthsquarefv(&this->e); }

		/**
		 * Make vector to a unite vector.
		 */
		void HCAPIENTRY makeUnitVector() { *this = *this / (*this).length(); }

		/**
		 * Get minimum component.
		 * @return number.
		 */
		float HCAPIFASTENTRY minComponent() const noexcept { return hpm_vec4_min_compfv(&this->e); }

		/**
		 * Get maximum component.
		 * @return number.
		 */
		float HCAPIFASTENTRY maxComponent() const noexcept { return hpm_vec4_max_compfv(&this->e); }

		/**
		 * Get absolute maximum component.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY maxAbsComponent() const noexcept { return fabs(hpm_vec4_max_compfv(&this->e)); }

		/**
		 * Get absolute minimum component.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY minAbsComponent() const noexcept { return fabs(hpm_vec4_min_compfv(&this->e)); }

		/**
		 * Normalize vector.
		 * @return normalized vector.
		 */
		Vector3 HCAPIENTRY normalize() const {
			float l = 1.0f / this->length();
			return (*this * l);
		}

		/**
		 * Check equality.
		 * @return
		 */
		friend bool operator==(const Vector3 &v1, const Vector3 &v2) noexcept {
			if (&v1 == &v2) {
				return true;
			} else {
				if (v1.e[0] != v2.e[0])
					return false;
				if (v1.e[1] != v2.e[1])
					return false;
				if (v1.e[2] != v2.e[2])
					return false;
				return true;
			}
		}

		friend bool operator!=(const Vector3 &v1, const Vector3 &v2) noexcept { return !(v1 == v2); }

		/**
		 * Create input stream for creating vector
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Vector3 &t) {
			float temp;
			is >> temp;
			t.setX(temp);
			is >> temp;
			t.setY(temp);
			is >> temp;
			t.setZ(temp);
			return is;
		}

		/**
		 * Create output stream of vector value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Vector3 &t) {
			os << '(' << t.x() << " " << t.y() << " " << t.z() << ')';
			return os;
		}

		/**
		 * @return
		 */
		friend Vector3 operator+(const Vector3 &v1, const Vector3 &v2) noexcept {
			return Vector3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
		}
		friend Vector3 operator-(const Vector3 &v1, const Vector3 &v2) noexcept {
			return Vector3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
		}

		friend Vector3 operator/(const Vector3 &vec, float scalar) noexcept(noexcept(scalar == 0.0)) {
			return Vector3(vec.x() / scalar, vec.y() / scalar, vec.z() / scalar);
		}
		friend Vector3 operator*(const Vector3 &vec, float scalar) noexcept {
			return Vector3(vec.x() * scalar, vec.y() * scalar, vec.z() * scalar);
		}
		friend Vector3 operator*(float scalar, const Vector3 &vec) noexcept {
			return Vector3(vec.e[0] * scalar, vec.e[1] * scalar, vec.e[2] * scalar);
		}
		friend Vector3 operator*(const Vector3 &vec1, const Vector3 &vec2) noexcept {
			return Vector3(vec1.e[0] * vec2.e[0], vec1.e[1] * vec2.e[1], vec1.e[2] * vec2.e[2]);
		}

		/**
		 *
		 */
		Vector3 &operator=(const Vector3 &v2) noexcept {
			hpm_vec4_copyfv(&this->e, &v2.e);
			return *this;
		}
		Vector3 &operator+=(const Vector3 &v2) noexcept {
			*this = *this + v2;
			return *this;
		}
		Vector3 &operator-=(const Vector3 &v2) noexcept {
			*this = *this - v2;
			return *this;
		}
		Vector3 &operator/=(float scalar) noexcept {
			*this = *this * scalar;
			return *this;
		}
		Vector3 &operator*=(float scalar) noexcept {
			*this = *this / scalar;
			return *this;
		}

		/**
		 *
		 * @param v
		 * @return
		 */
		friend Vector3 HCAPIENTRY unitVector3(const Vector3 &v) {
			Vector3 unit = v;
			hpm_vec4_setwf(unit.e, 0.0f);
			hpm_vec4_normalizefv(&unit.e);
			return unit;
		}

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector3 HCAPIENTRY minVec(const Vector3 &v1, const Vector3 &v2) noexcept {
			Vector3 vec(v1);
			if (v2.x() < v1.x())
				vec.setX(v2.x());
			if (v2.y() < v1.y())
				vec.setY(v2.y());
			if (v2.z() < v1.z())
				vec.setZ(v2.z());
			return vec;
		}

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector3 HCAPIENTRY maxVec(const Vector3 &v1, const Vector3 &v2) noexcept {
			Vector3 vec(v1);
			if (v2.x() > v1.x())
				vec.setX(v2.x());
			if (v2.y() > v1.y())
				vec.setY(v2.y());
			if (v2.z() > v1.z())
				vec.setZ(v2.z());
			return vec;
		}

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector3 HCAPIENTRY cross(const Vector3 &v1, const Vector3 &v2) noexcept {
			Vector3 cr;
			hpm_vec3_crossproductfv(&v1.e, &v2.e, &cr.e);
			return cr;
		}

		/**
		 *
		 * @param vector
		 * @param normal
		 * @return
		 */
		friend Vector3 HCAPIENTRY reflection(const Vector3 &vector, const Vector3 &normal) noexcept {
			Vector3 vec;
			hpm_vec3_reflectfv(&vector.e, &normal.e, &vec.e);
			return vec;
		}

		/**
		 *
		 * @param v1
		 * @param normal
		 * @param refraction
		 * @return
		 */
		friend Vector3 HCAPIENTRY refraction(const Vector3 &v1, const Vector3 &normal, float refraction) noexcept {
			Vector3 vec;
			hpm_vec3_refractfv(&v1.e, &normal.e, refraction, &vec.e);
			return vec;
		}

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend float HCAPIENTRY dot(const Vector3 &v1, const Vector3 &v2) noexcept {
			return hpm_vec3_dotfv(&v1.e, &v2.e);
		}

		/**
		 *
		 * @param v1
		 * @param v2
		 * @param v3
		 * @return
		 */
		friend float HCAPIENTRY tripleProduct(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3) noexcept {
			return hpm_vec3_tripleProductfv(&v1.e, &v2.e, &v3.e);
		}

		/**
		 *
		 * @param normal
		 * @return
		 */
		friend Vector3 HCAPIENTRY tangent(const Vector3 &normal) noexcept {
			Vector3 tangent = cross(normal, Vector3::forward());

			if (tangent.length() <= Math::Epsilon) { // if magnitude == is equal to 0
				tangent = cross(normal, Vector3::up());
			}
			return tangent;
		}

		/**
		 *
		 * @param normal
		 * @param tangent
		 * @return
		 */
		friend Vector3 HCAPIENTRY biTangent(const Vector3 &normal, const Vector3 &tangent) noexcept {
			return cross(normal, tangent);
		}

		/**
		 *
		 * @param normal
		 * @param tangent
		 * @return
		 */
		friend Vector3 HCAPIENTRY biNormal(const Vector3 &normal, const Vector3 &tangent) noexcept {
			return cross(tangent, normal);
		}

	  private: /*	Private method.	*/
		hpmvec3f e;

	  public: /*	Static methods.	*/
		/**
		 * Create predefined vector3.
		 */
		inline static Vector3 forward() noexcept { return Vector3(0.0f, 0.0f, 1.0f); }
		inline static Vector3 back() noexcept { return Vector3(0.0f, 0.0f, -1.0f); }
		inline static Vector3 right() noexcept { return Vector3(1.0f, 0.0f, 0.0f); }
		inline static Vector3 left() noexcept { return Vector3(-1.0f, 0.0f, 0.0f); }
		inline static Vector3 up() noexcept { return Vector3(0.0f, 1.0f, 0.0f); }
		inline static Vector3 down() noexcept { return Vector3(0.0f, -1.0f, 0.0f); }
		inline static Vector3 zero() noexcept { return Vector3(0.0f, 0.0, 0.0f); }

		/**
		 * Linear interpolation between v1 and v2 based on t.
		 * @param vec1
		 * @param vec2
		 * @param t [0,1]
		 * @return interpolated position.
		 */
		template <typename T = float>
		static Vector3 HCAPIENTRY lerp(const Vector3 &vec1, const Vector3 &vec2, T t) noexcept {
			return (vec1 + (vec2 - vec1) * t);
		}

		/**
		 * Spherical interpolation.
		 * @param vec1 start position.
		 * @param vec2 end position.
		 * @param t [0,1]
		 * @return interpolated position.
		 */
		template <typename T = float>
		static Vector3 HCAPIENTRY slerp(const Vector3 &vec1, const Vector3 &vec2, T t) noexcept {
			return Vector3();
		}
	};
} // namespace LIBHPM

#endif
