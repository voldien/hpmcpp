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
#ifndef _HPMCPP_OBB_H_
#define _HPMCPP_OBB_H_ 1
#include"HCONB.h"
#include"HCVector3.h"

namespace hpmcpp {
	/**
	 *	Oriented bounding box.
	*/
	class HCDECLSPEC OBB {
	public:

		OBB(void);

		OBB(const OBB &obb);

		OBB(const Vector3 &u, const Vector3 &v, const Vector3 &w);

		OBB(const Vector3 &u, const Vector3 &v, const Vector3 &w, const Vector3 &size);

		OBB(const Vector3 &u, const Vector3 &v, const Vector3 &w, const Vector3 &center, const Vector3 &size);

		/**
		 * Get U axis.
		 * @return normalized axis.
		 */
		const Vector3 &HCAPIENTRY getU(void) const;

		/**
		 *	Get V axis.
		* @return normalized axis.
		*/

		/**
		 *
		 * @return
		 */
		const Vector3 &HCAPIENTRY getV(void) const;

		/**
		 * Get W axis.
		 * @return normalized axis.
		 */
		const Vector3 &HCAPIENTRY getW(void) const;

		/**
		 * Set size of box.
		 * @param size
		 */
		void setSize(const Vector3 &size) {
			this->size = size;
		}

		/**
		 * Get half size.
		 * @return non-negative vector of the size.
		 */
		inline Vector3 getSize(void) {
			return size;
		}

		/**
		 *
		 * @return
		 */
		inline const Vector3 &getSize(void) const {
			return this->size;
		}

		/**
		 *
		 * @param size
		 */
		inline void setCenter(const Vector3 &size) {

		}

		/**
		 *
		 * @return
		 */
		inline Vector3 getCenter(void) const {
			return Vector3(this->halfu, this->halfv, this->halfw);
		}

		OBB &operator=(const OBB &obb);

		/**
		 *
		 * @param is
		 * @param t
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, OBB &t);

		/**
		 *
		 * @param is
		 * @param t
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const OBB &t);

	private:    /*	Attributes.	*/

		ONB onb;          /*	*/
		Vector3 size;     /*	*/
		float halfu;        /*	*/
		float halfv;        /*	*/
		float halfw;        /*	*/
	};
}

#endif
