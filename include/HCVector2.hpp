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
#include "HCTypes.hpp"

namespace LIBHPM {
	/**
	 * Vector2.
	 */
	struct HCDECLSPEC alignas(alignof(hpmvec2f)) Vector2 {
	  public:
		Vector2(void) = default;
		Vector2(float val) {
			this->setX(val);
			this->setY(val);
		}
		Vector2(float m0, float m1) {
			this->setX(m0);
			this->setY(m1);
		}
		Vector2(const Vector2 &v) { *this = v; }

		/**
		 * Negate vector.
		 * @return
		 */
		Vector2 &operator-(void) const noexcept { return -*this; }

		/**
		 * Get vector component by index.
		 * @return component value.
		 */
		inline float operator[](int i) const noexcept(noexcept(i >= 2)) { return this->m[i]; }

		/**
		 * Compute length.
		 * @return length in decimal.
		 */
		float length(void) const noexcept { return sqrtf(x() * x() + y() * y()); }

		/**
		 * Compute square length.
		 * @return length in decimal.
		 */
		float squaredLength(void) const noexcept { return (x() * x() + y() * y()); }

		/**
		 * Make vector to unit length.
		 */
		void makeUnitVector(void) { *this /= this->length(); }

		/**
		 * Set vector X component value.
		 */
		void HCAPIFASTENTRY setX(float _x) noexcept { this->m[0] = _x; }

		/**
		 * Set vector Y component value.
		 */
		void HCAPIFASTENTRY setY(float _y) noexcept { this->m[1] = _y; }

		/**
		 * Get vector X component value.
		 * @return value of component.
		 */
		float HCAPIFASTENTRY x(void) const noexcept { return this->m[0]; }

		/**
		 * Get vector Y component value.
		 * @return value of component.
		 */
		float HCAPIFASTENTRY y(void) const noexcept { return this->m[1]; }

		/**
		 * @return
		 */
		float minComponent(void) const noexcept { return 0; }
		float maxComponent(void) const noexcept { return 0; }
		float maxAbsComponent(void) const noexcept { return 0; }
		float minAbsComponent(void) const noexcept { return 0; }
		int indexOfMinComponent(void) const noexcept { return 0; }
		int indexOfMaxComponent(void) const noexcept { return 0; }
		int indexOfMinAbsComponent(void) const noexcept { return 0; }
		int indexOfMaxAbsComponent(void) const noexcept { return 0; }

		/**
		 * Create normalize copy
		 * @return
		 */
		Vector2 normalize(void) const {
			Vector2 copy = *this;
			copy.makeUnitVector();
			return copy;
		}

		/**
		 * Compare vector equalities.
		 * @return true if vector equal for each component.
		 */
		friend bool operator==(const Vector2 &v1, const Vector2 &v2) { return !(v1 == v2); }
		/**
		 * Compare vector inequality.
		 * @return true if at least single component is not equal.
		 */
		friend bool operator!=(const Vector2 &v1, const Vector2 &v2) { return !(v1 == v2); }

		/**
		 * Create input stream for creating vector
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Vector2 &t) {

			float tmp;

			is >> tmp;
			t.setX(tmp);
			is >> tmp;
			t.setY(tmp);

			return is;
		}

		/**
		 * Create output stream of vector value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Vector2 &t) {
			os << '(' << t.x() << " " << t.y() << ')';
			return os;
		}

		friend Vector2 operator+(const Vector2 &v1, const Vector2 &v2) {
			return Vector2(v1.x() + v2.x(), v1.y() + v2.y());
		}
		friend Vector2 operator-(const Vector2 &v1, const Vector2 &v2) {
			return Vector2(v1.x() - v2.x(), v1.y() - v2.y());
		}

		friend Vector2 operator/(const Vector2 &vec, float scalar) {
			return Vector2(vec.x() / scalar, vec.y() / scalar);
		}
		friend Vector2 operator*(const Vector2 &vec, float scalar) {
			return Vector2(vec.x() * scalar, vec.y() * scalar);
		}
		friend Vector2 operator*(float scalar, const Vector2 &vec) {
			return Vector2(vec.x() * scalar, vec.y() * scalar);
		}

		friend Vector2 operator*(const Vector2 &v1, const Vector2 &v2) {
			return Vector2(v1.x() * v2.x(), v1.y() * v2.y());
		}

		Vector2 &operator=(const Vector2 &v2) {
			this->setX(v2.x());
			this->setY(v2.y());
			return *this;
		}
		Vector2 &operator+=(const Vector2 &v2) {
			*this = *this + v2;
			return *this;
		}
		Vector2 &operator-=(const Vector2 &v2) {
			*this = *this - v2;
			return *this;
		}
		Vector2 &operator/=(float scalar) {
			*this = *this / scalar;
			return *this;
		}
		Vector2 &operator*=(float scalar) {
			*this = *this * scalar;
			return *this;
		}
		Vector2 &operator*=(const Vector2 &vec2) {
			*this = *this * vec2;
			return *this;
		}

		/**
		 *
		 * @param v
		 * @return
		 */
		friend Vector2 unitVector3(const Vector2 &v) noexcept;

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector2 minVec(const Vector2 &v1, const Vector2 &v2) noexcept;

		/**
		 *
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend Vector2 maxVec(const Vector2 &v1, const Vector2 &v2) noexcept;

		/**
		 *
		 * @param vector
		 * @param normal
		 * @return
		 */
		friend Vector2 reflection(const Vector2 &vector, const Vector2 &normal) noexcept;

		/**
		 * Compute dot product.
		 * @param v1
		 * @param v2
		 * @return
		 */
		friend float dot(const Vector2 &v1, const Vector2 &v2) noexcept;

	  private: /*	Attributes.	*/
		hpmvec2f m;

	  public: /*	Static methods.	*/
			  /**
			   * Create zero vector.
			   * @return HCVector2 object.
			   */
		static Vector2 zero(void) noexcept { return Vector2(0.0f); }
	};
} // namespace LIBHPM

#endif
