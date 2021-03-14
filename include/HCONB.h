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
#ifndef _HPMCPP_ONB_H_
#define _HPMCPP_ONB_H_ 1
#include"HCVector3.h"

namespace LIBHPM {
	#define HPMCPP_ONB_EPSILON 0.01f

	/**
	 *	ORTHONORMAL BASED AND FRAMES
	*/
	class HCDECLSPEC ONB {
	public:
		ONB(void) = default;
		ONB(const ONB& other);
		ONB(const Vector3& a, const Vector3& b, const Vector3& c);

		/**
		 *
		 */
		void initFromU(const Vector3& u);
		void initFromV(const Vector3& v);
		void initFromW(const Vector3& w);

		/**
		 *
		 */
		void set(const Vector3& a, const Vector3& b, const Vector3& c);
		void setU(const Vector3& u);
		void setV(const Vector3& v);
		void setW(const Vector3& w);

		/**
		 *
		 */
		void initFromUV(const Vector3& u, const Vector3& v);
		void initFromVU(const Vector3& v, const Vector3& u);

		/**
		 *
		 */
		void initFromUW(const Vector3& u, const Vector3& w);
		void initFromWU(const Vector3& w, const Vector3& u);

		/**
		 *
		 */
		void initFromVW(const Vector3& v, const Vector3& w);
		void initFromWV(const Vector3& w, const Vector3& v);

		/**
		 *
		 * @param is
		 * @param t
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream& is, ONB& t);

		/**
		 *
		 * @param os
		 * @param t
		 * @return
		 */
		friend std::ostream &operator<<(std::ostream& os, const ONB& t);

		/**
		 *	Compare 
		* @return true if equal.
		*/
		friend bool operator==(const ONB& o1, const ONB& o2);

		/**
		 *	Compare 
		* @return true if equal.
		*/
		friend bool operator!=(const ONB& o1, const ONB& o2);

		ONB& operator=(const ONB& onb);

		/**
		 * @return
		 */
		inline const Vector3& u(void) const {
			return this->m[0];
		}

		/**
		 * @return
		 */
		inline const Vector3& v(void) const {
			return this->m[1];
		}

		/**
		 * @return
		 */
		inline const Vector3& w(void) const {
			return this->m[2];
		}

	private:	/*	Attributes.	*/

		Vector3 m[3];		/*	*/

	};
}

#endif
