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
#ifndef _HPMCPP_BOUNDS_H_
#define _HPMCPP_BOUNDS_H_ 1
#include"HCRay.h"
#include"HCVector3.h"

namespace hpmcpp{
	/**
	 * Axis aligned bounding
	 * box.
	 */
	class HCDECLSPEC AABB {
	public:

		AABB(void) {}
		AABB(const Vector3& size, const Vector3& center);
		AABB(const AABB& bounds) {
			*this = bounds;
		}

		/**
		 *
		 * @param i
		 * @return
		 */
		inline Vector3 operator[](int i) const {
			return ((Vector3*) this)[i];
		}

		/**
		 *
		 * @return
		 */
		inline Vector3& operator[](int i) {
			return ((Vector3*) this)[i];
		}

		/**
		 * Check if object is valid.
		 * @return true if valid, false otherwise.
		 */
		inline bool isValid(void) const {
			return !(this->mhalfsize.x() != 0.0f || this->mhalfsize.y() != 0.0f
					|| this->mhalfsize.z() != 0.0f);
		}

		/**
		 *
		 */
		inline float maxX(void) const {
			return (this->mcenter.x() + this->mhalfsize.x());
		}
		inline float minX(void) const {
			return (this->mcenter.x() - this->mhalfsize.x());
		}
		inline float maxY(void) const {
			return (this->mcenter.y() + this->mhalfsize.y());
		}
		inline float minY(void) const {
			return (this->mcenter.y() - this->mhalfsize.y());
		}
		inline float maxZ(void) const {
			return (this->mcenter.z() + this->mhalfsize.z());
		}
		inline float minZ(void) const {
			return (this->mcenter.z() - this->mhalfsize.z());
		}

		/**
		 * Compute minimum position.
		 * @return vector position.
		 */
		inline Vector3 min(void) const {
			return this->getCenter() - this->getSize();
		}

		/**
		 * Compute max position.
		 * @return vector position.
		 */
		inline Vector3 max(void) const {
			return this->getCenter() + this->getSize();
		}

		/**
		 * Get half size.
		 * @return half size vector.
		 */
		inline const Vector3& getSize(void) const {
			return this->mhalfsize;
		}

		/**
		 * Set half size.
		 */
		inline void setSize(const Vector3& size) {
			this->mhalfsize = size;
		}

		/**
		 * Get center position.
		 * @return
		 */
		inline const Vector3& getCenter(void) const {
			return this->mcenter;
		}

		/**
		 * Set center position.
		 */
		inline void setCenter(const Vector3& center) {
			this->mcenter = center;
		}

		/**
		 * Check if object intersect.
		 * @param bounds intersect this bound.
		 * @return true if object intersects.
		 */
		bool intersect(const AABB& bounds);

		/**
		 *
		 * @param point
		 * @param worldPosition
		 * @return  true if object contains.
		 */
		bool HCAPIENTRY contains(const Vector3& point, const Vector3 worldPosition =
				Vector3());

		/**
		 * Check if object contains bound
		 * object.
		 * @param bounds
		 * @return true if completly contains, false otherwise.
		 */
		bool HCAPIENTRY contains(const AABB& bounds);

		/**
		 *
		 * @param normal
		 * @return
		 */
		Vector3 HCAPIENTRY getVertexN(Vector3& normal) const;

		/**
		 *
		 * @param normal
		 * @return
		 */
		Vector3 HCAPIENTRY getVertexP(Vector3& normal) const;

		/**
		 * Create input stream for creating AABB
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Vector3& t);

		/**
		 * Create output stream of AABB values.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Vector3& t);

		/**
		 * Assign bound object.
		 * @return reference of object.
		 */
		AABB& operator=(const AABB& bound);

		/**
		 *
		 * @return reference of object.
		 */
		friend AABB operator*(const AABB& bound, float scalar);

		/**
		 * Divide the size by scalar.
		 * @param bound
		 * @param divisor
		 * @return reference of object.
		 */
		friend AABB operator/(const AABB& bound, float divisor);

		/**
		 * Factor the bound size of the bound.
		 * @param scalar real number.
		 * @return reference of object.
		 */
		AABB& operator*=(float scalar);

		/**
		 * Divide the size by scalar.
		 * @param divisor non-zero.
		 * @return reference of object.
		 */
		AABB& operator/=(float divisor);

		/**
		 * Compare if objects are equal.
		 * @param bound
		 * @return true if object are equal, false otherwise.
		 */
		bool operator==(const AABB& bound);

		/**
		 * Compare if object are not equal.
		 * @param bound
		 * @return false if object are equal, true otherwise.
		 */
		bool operator!=(const AABB& bound);

	private:	/*	Attributes.	*/

		Vector3 mhalfsize;    /*	half size of the box.	*/
		Vector3 mcenter;      /*	center of the box.	*/
	};
}

#endif
