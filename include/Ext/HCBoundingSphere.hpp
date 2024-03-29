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
#ifndef _HPMCPP_BOUNDING_SPHERE_H_
#define _HPMCPP_BOUNDING_SPHERE_H_ 1
#include "../HCVector3.hpp"
#include "HCRay.hpp"

namespace LIBHPM {
	/**
	 * @brief
	 *
	 */
	struct HCDECLSPEC BoundingSphere {
	  public:
		BoundingSphere() = default;
		BoundingSphere(const Vector3 &center, float radius) noexcept {
			this->setCenter(center);
			this->setRadius(radius);
		}
		BoundingSphere(const BoundingSphere &boundingSphere) noexcept { *this = boundingSphere; }

		/**
		 * Get radius size.
		 * @return non-negative size.
		 */
		inline constexpr float getRadius() const noexcept { return this->radius; }

		/**
		 * set radius size of the sphere.
		 * @param radius non-negative radius size.
		 */
		inline void setRadius(float radius) noexcept { this->radius = radius; }

		/**
		 * Get center position.
		 * @return world position.
		 */
		inline const Vector3 &getCenter() const noexcept { return this->center; }

		/**
		 * Set center position.
		 * @param center in world position.
		 */
		inline void setCenter(const Vector3 &center) { this->center = center; }

		/**
		 * Check if object intersects with another sphere.
		 * @param sphere
		 * @return true if object intersects, false otherwise.
		 */
		bool HCAPIENTRY
		intersect(const BoundingSphere &sphere) const { // get box closest point to sphere center by clamping
			// we are using multiplications because it's faster than calling Math.pow
			float distance = std::sqrt(
				(this->getCenter().x() - sphere.getCenter().x()) * (this->getCenter().x() - sphere.getCenter().x()) +
				(this->getCenter().y() - sphere.getCenter().y()) * (this->getCenter().y() - sphere.getCenter().y()) +
				(this->getCenter().z() - sphere.getCenter().z()) * (this->getCenter().z() - sphere.getCenter().z()));
			return distance < (this->getRadius() + sphere.getRadius());
		}

		/**
		 * Check if sphere contains a sphere.
		 * @param sphere sphere inside this sphere.
		 * @return true if object contains, false otherwise.
		 */
		constexpr bool HCAPIENTRY contains(const BoundingSphere &sphere) const { return false; }

		template <typename T> constexpr bool intersect(const Ray &ray) const noexcept {
			Vector3 tmp = ray.getOrigin() - getCenter();
			T t;
			T a = dot(ray.getDirection(), ray.getDirection());
			T b = (T)2.0 * dot(ray.getDirection(), tmp);
			T d = dot(tmp, tmp) - radius * radius;
			T discriminant = b * b - ((T)4.0 * d * a);
			if (discriminant >= 0) {
				discriminant = static_cast<T>(sqrt(discriminant));

				if (t < (T)0)
					t = (-b + discriminant) / ((T)2.0 * a);
				return true;
			}
			return false;
		}
		constexpr bool intersect(const Ray &ray) const noexcept { return intersect<float>(ray); }

		BoundingSphere &operator=(const BoundingSphere &bounds) {
			this->setRadius(bounds.getRadius());
			this->setCenter(bounds.getCenter());
			return *this;
		}

	  private:			/*	Private member attributes.	*/
		float radius;	/*	Radius size.	*/
		Vector3 center; /*	Center position in world space.*/
	};
} // namespace LIBHPM

#endif
