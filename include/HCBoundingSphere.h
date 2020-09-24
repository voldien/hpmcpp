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
#include"HCRay.h"
#include"HCVector3.h"

namespace hpmcpp {
	/**
	 *
	 */
	class HCDECLSPEC BoundingSphere {
	public:
		BoundingSphere(void) = default;
		BoundingSphere(const Vector3& center, float radius){
			this->setCenter(center);
			this->setRadius(radius);
		}
		BoundingSphere(const BoundingSphere& boundingSphere){
			*this = boundingSphere;
		}

		/**
		 * Get radius size.
		 * @return non-negative size.
		 */
		inline float getRadius(void)const{
			return this->radius;
		}

		/**
		 * set radius size of the sphere.
		 * @param radius non-negative radius size.
		 */
		inline void setRadius(float radius) {
			this->radius = radius;
		}

		/**
		 * Get center position.
		 * @return world position.
		 */
		inline const Vector3& getCenter(void) const {
			return this->center;
		}

		/**
		 * Set center position.
		 * @param center in world position.
		 */
		inline void setCenter(const Vector3& center) {
			this->center = center;
		}

		/**
		 * Check if object intersects with another sphere.
		 * @param sphere
		 * @return true if object intersects, false otherwise.
		 */
		bool HCAPIENTRY intersect(const BoundingSphere &sphere) const{
			return false;
		}

		/**
		 * Check if sphere contains a sphere.
		 * @param sphere sphere inside this sphere.
		 * @return true if object contains, false otherwise.
		 */
		bool HCAPIENTRY contains(const BoundingSphere &sphere) const{
			return false;	
		}

		bool intersect(const Ray& ray) const {
			Vector3 tmp = ray.getOrigin() - getCenter();
			double t;
			double a = dot(ray.getDirection(), ray.getDirection());
			double b = 2.0f * dot(ray.getDirection(), tmp);
			double d = dot(tmp, tmp) - radius * radius;
			double discriminant = b * b - (4.0 * d * a);
			if (discriminant >= 0) {
				discriminant = sqrt(discriminant);
				//hit.t = (-b - discriminant) / (2.0 * a);
				if (t < 0)
					t = (-b + discriminant) / (2.0 * a);
				return true;
			}
			return false;
		}

		BoundingSphere& operator=(const BoundingSphere& bounds){
			this->setRadius(bounds.getRadius());
			this->setCenter(bounds.getCenter());
			return *this;
		}

	private:	/*	Private member attributes.	*/

		float radius;			/*	Radius size.	*/
		Vector3 center;		/*	Center position in world space.*/

	};
}

#endif
