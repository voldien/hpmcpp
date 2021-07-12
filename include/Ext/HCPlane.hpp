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
#ifndef _HPMCPP_PLANE_H_
#define _HPMCPP_PLANE_H_ 1
#include "HCVector3.hpp"
#include <iostream>

namespace LIBHPM {
	/**
	 *
	 */
	struct HCDECLSPEC Plane {
	  public:
		Plane(void) = default;
		Plane(const Vector3 &normal) noexcept {
			this->normal = normal;
			this->d = 0;
		}
		Plane(const Vector3 &point, const Vector3 &normal) noexcept { this->setNormalAndPoint(normal, point); }
		Plane(const Plane &plane) noexcept = default;

		/**
		 * Get normal of plane.
		 * @return normalized normal vector.
		 */
		inline Vector3 getNormal(void) noexcept { return this->normal; }

		/**
		 * Get normal of plane.
		 * @return normalized normal vector.
		 */
		inline const Vector3 &getNormal(void) const noexcept { return this->normal; }

		/**
		 * Set plane normal.
		 * @param normal
		 */
		inline void setNormal(const Vector3 &normal) noexcept { this->normal = normal; }

		/**
		 * Compute distance.
		 * @param point
		 * @return
		 */
		inline float distance(const Vector3 &point) const noexcept { return dot(normal, point) + d; }

		/**
		 * Get distance.
		 * @return
		 */
		inline float distance(void) const noexcept { return this->d; }

		/**
		 * Get point.
		 * @return
		 */
		inline Vector3 getPoint(void) const noexcept { return d * this->getNormal(); }

		/**
		 * Set normal and point and
		 * compute internal values.
		 */
		void setNormalAndPoint(const Vector3 &normal, const Vector3 &point) noexcept {
			this->normal = normal.normalize();
			this->d = -dot(this->normal, point);
		}

		/**
		 * Construct plane.
		 */
		void set3DPoints(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3) noexcept {
			this->normal = cross((v1 - v2), (v1 - v3)).normalize();
			this->d = -dot(this->normal, v2);
		}

		/**
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Plane &t) { return is; }

		/**
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Plane &t) { return os; }

		/**
		 * Compare if plane equal each other.
		 * @return true if equal.
		 */
		friend bool operator==(const Plane &o1, const Plane &o2) noexcept { return false; }

		/**
		 * Compare if plane not equal each other.
		 * @return true if equal.
		 */
		friend bool operator!=(const Plane &o1, const Plane &o2) noexcept { return false; }

	  protected:		/*	Attributes.	*/
		Vector3 normal; /*	*/
		float d;		/*	*/

	  public: /*	Static methods.	*/
		/**
		 * Create plane from points.
		 * @param v1
		 * @param v2
		 * @param v3
		 * @return
		 */
		static Plane HCAPIENTRY fromPoints(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3) noexcept {
			Plane tmp;
			Vector3 e1 = v2 - v1;
			Vector3 e2 = v3 - v1;

			tmp.normal = cross(e1, e2).normalize();
			tmp.d = -dot(tmp.normal, v2);
			return tmp;
		}
	};
} // namespace LIBHPM
#endif
