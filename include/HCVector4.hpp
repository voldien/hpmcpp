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
#include "HCTypes.hpp"
namespace LIBHPM {
	/**
	 * Vector4 class. Contains
	 * x, y, z, w component. Where the
	 * size of the object is 128 bit.
	 */
	struct HCDECLSPEC alignas(alignof(hpmvec4f)) Vector4 {
	  public:
		Vector4(void) noexcept = default;
		Vector4(float val) noexcept { hpm_vec4_setsf(&this->e, val); }
		Vector4(float x, float y, float z, float w) noexcept { hpm_vec4_setf(&this->e, x, y, x, w); }
		Vector4(const Vector4 &v) noexcept { *this = v; }

		/**
		 * Get component wise.
		 */
		inline float HCAPIFASTENTRY x(void) const noexcept { return hpm_vec4_getxf(this->e); }
		inline float HCAPIFASTENTRY y(void) const noexcept { return hpm_vec4_getyf(this->e); }
		inline float HCAPIFASTENTRY z(void) const noexcept { return hpm_vec4_getzf(this->e); }
		inline float HCAPIFASTENTRY w(void) const noexcept { return hpm_vec4_getwf(this->e); }

		/**
		 * Set component wise.
		 */
		inline void HCAPIFASTENTRY setX(float x) noexcept { hpm_vec4_setxf(this->e, x); }
		inline void HCAPIFASTENTRY setY(float y) noexcept { hpm_vec4_setyf(this->e, y); }
		inline void HCAPIFASTENTRY setZ(float z) noexcept { hpm_vec4_setzf(this->e, z); }
		inline void HCAPIFASTENTRY setW(float w) noexcept { hpm_vec4_setwf(this->e, w); }

		/**
		 * Get component by index.
		 */
		constexpr float operator[](unsigned int i) const noexcept(noexcept(i >= 3)) {
			if (i > 3)
				throw std::invalid_argument("Index");
			return this->e[i];
		}
		float &operator[](unsigned int i) noexcept(noexcept(i >= 3)) {
			if (i > 3)
				throw std::invalid_argument("Index");
			return this->e[i];
		}

		/**
		 * Negate vector.
		 * @return negated vector.
		 */
		Vector4 operator-(void) const noexcept {
			Vector4 copy = *this;
			hpm_vec4_negatefv(&copy.e);
			return copy;
		}

		/**
		 * Compute length of vector.
		 * @return non-negativ number.
		 */
		float HCAPIFASTENTRY length(void) const noexcept { return hpm_vec4_lengthfv(&this->e); }

		/**
		 * Compute length of vector.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY squaredLength(void) const noexcept { return hpm_vec4_lengthsqurefv(&this->e); }

		/**
		 * Normalize current vector.
		 */
		void HCAPIENTRY makeUnitVector(void) { hpm_vec4_normalizefv(&this->e); }

		/**
		 * Get minimum component.
		 * @return number.
		 */
		float HCAPIFASTENTRY minComponent(void) const noexcept { return hpm_vec4_min_compfv(&this->e); }

		/**
		 * Get maximum component.
		 * @return number.
		 */
		float HCAPIFASTENTRY maxComponent(void) const noexcept { return hpm_vec4_max_compfv(&this->e); }

		/**
		 * Get absolute maximum component.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY maxAbsComponent(void) const noexcept { return abs(hpm_vec4_max_compfv(&this->e)); }

		/**
		 * Get absolute minimum component.
		 * @return non-negative number.
		 */
		float HCAPIFASTENTRY minAbsComponent(void) const noexcept { return abs(hpm_vec4_min_compfv(&this->e)); }

		/**
		 * Create normalized copy.
		 * @return normalize vector of current vector.
		 */
		Vector4 HCAPIENTRY normalize(void) const {
			Vector4 vec = *this;
			hpm_vec4_normalizefv(&vec.e);
			return vec;
		}

		/**
		 * Equality
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend bool operator==(const Vector4 &v1, const Vector4 &v2) noexcept {
			return (bool)hpm_vec4_eqfv(&v1.e, &v2.e);
		}
		friend bool operator!=(const Vector4 &v1, const Vector4 &v2) noexcept {
			return (bool)hpm_vec4_neqfv(&v1.e, &v2.e);
		}

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

		friend Vector4 operator+(const Vector4 &v1, const Vector4 &v2) noexcept {
			Vector4 copy = v1;
			hpm_vec4_addition_scalefv(&copy.e, &v2.e);
			return copy;
		}
		friend Vector4 operator-(const Vector4 &v1, const Vector4 &v2) noexcept {
			Vector4 copy = Vector4(v1);
			hpm_vec4_subtractionfv((hpmvec4f *)&copy, (const hpmvec4f *)&v2);
			return copy;
		}
		friend Vector4 operator/(const Vector4 &vec, float scalar) noexcept {
			Vector4 copy = vec;
			hpm_vec4_multi_scalef(&copy.e, 1.0f / scalar);
			return copy;
		}
		friend Vector4 operator/(const Vector4 &v1, const Vector4 &v2) noexcept {
			Vector4 copy = v1;
			Vector4 c3 = 1.0f / v2;
			hpm_vec4_multifv(&copy.e, &c3.e);
			return copy;
		}
		friend Vector4 operator*(const Vector4 &vec, float scalar) noexcept {
			Vector4 copy = vec;
			hpm_vec4_multi_scalef(&copy.e, scalar);
			return copy;
		}
		friend Vector4 operator*(float scalar, const Vector4 &vec) noexcept {
			Vector4 copy = vec;
			hpm_vec4_multi_scalef(&copy.e, scalar);
			return copy;
		}

		Vector4 &operator=(const Vector4 &v2) noexcept {
			hpm_vec4_copyfv(&this->e, &v2.e);
			return *this;
		}
		Vector4 &operator+=(const Vector4 &v2) noexcept {
			*this = *this + v2;
			return *this;
		}
		Vector4 &operator-=(const Vector4 &v2) noexcept {
			*this = *this - v2;
			return *this;
		}
		Vector4 &operator/=(float scalar) noexcept {
			*this = *this / scalar;
			return *this;
		}
		Vector4 &operator*=(float scalar) noexcept {
			*this = *this * scalar;
			return *this;
		}

		/**
		 * Compute unit vector.
		 * @param v vector.
		 * @return unite vector.
		 */
		friend Vector4 HCAPIENTRY unitVector4(const Vector4 &v) {
			Vector4 copy = v;
			return v.normalize();
		}

		/**
		 * Compute min vector component.
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector4 HCAPIENTRY minVec(const Vector4 &v1, const Vector4 &v2) noexcept {
			Vector4 vec;
			hpm_vec4_minfv(&v1.e, &v2.e, &vec.e);
			return vec;
		}

		/**
		 * Compute max vector component.
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector4 HCAPIENTRY maxVec(const Vector4 &v1, const Vector4 &v2) noexcept {
			Vector4 vec;
			hpm_vec4_maxfv(&v1.e, &v2.e, &vec.e);
			return vec;
		}

		/**
		 * Computer inner dot product.
		 * @param v1
		 * @param v2
		 * @return inner product.
		 */
		friend float HCAPIENTRY dot(const Vector4 &v1, const Vector4 &v2) noexcept {
			return hpm_vec4_dotfv(&v1.e, &v2.e);
		}

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
		static Vector4 HCAPIENTRY lerp(const Vector4 &vec1, const Vector4 &vec2, float speed) noexcept {
			Vector4 vec;
			hpm_vec4_lerpfv(&vec1.e, &vec2.e, speed, &vec.e);
			return vec;
		}

		/**
		 * Spherical interpolation.
		 * @param vec1 start position.
		 * @param vec2 end position.
		 * @param speed [0, 1]
		 * @return interpolated position.
		 */
		static Vector4 HCAPIENTRY slerp(const Vector4 &vec1, const Vector4 &vec2, float speed) noexcept {
			Vector4 vec;
			hpm_vec4_slerpfv(&vec1.e, &vec2.e, speed, &vec.e);
			return vec;
		}
	};
} // namespace LIBHPM

#endif
