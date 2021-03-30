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
#include "../HCVector3.h"
#include"../HCMath.h"

namespace LIBHPM {
	/**
	 *	ORTHONORMAL BASED AND FRAMES
	 */
	struct HCDECLSPEC ONB {
	  public:
		ONB(void) = default;
		ONB(const ONB &other) { *this = other; }
		ONB(const Vector3 &a, const Vector3 &b, const Vector3 &c) { this->set(a, b, c); }

		/**
		 *
		 */
		void initFromU(const Vector3 &u) {
			Vector3 n(1.0f, 0.0f, 0.0f);
			Vector3 m(0.0f, 1.0f, 0.0f);

			this->setU(u.normalize());
			this->setV(cross(this->u(), n));
			if (this->v().length() < Math::Epsilon) {
				this->setV(cross(this->u(), m));
			}
			this->setW(cross(this->u(), this->v()));
		}
		void initFromV(const Vector3 &v) {
			Vector3 n(1.0f, 0.0f, 0.0f);
			Vector3 m(0.0f, 1.0f, 0.0f);

			this->setV(v.normalize());
			this->setU(cross(this->v(), n));
			if (this->u().length() < Math::Epsilon) {
				this->setU(cross(this->v(), m));
			}
			this->setW(cross(this->u(), this->v()));
		}
		void initFromW(const Vector3 &w) {
			Vector3 n(1.0f, 0.0f, 0.0f);
			Vector3 m(0.0f, 1.0f, 0.0f);

			this->setW(w.normalize());
			this->setU(cross(this->w(), n));
			if (this->u().length() < Math::Epsilon) {
				this->setU(cross(this->w(), m));
			}
			this->setW(cross(this->w(), this->v()));
		}

		/**
		 *
		 */
		void set(const Vector3 &a, const Vector3 &b, const Vector3 &c){
			this->m[0] = a;
			this->m[1] = b;
			this->m[2] = c;
		}
		void setU(const Vector3 &u) { this->m[0] = u; }
		void setV(const Vector3 &v) { this->m[1] = v; }
		void setW(const Vector3 &w) { this->m[2] = w; }

		/**
		 *
		 */
		void initFromUV(const Vector3 &u, const Vector3 &v) {}
		void initFromVU(const Vector3 &v, const Vector3 &u) {}

		/**
		 *
		 */
		void initFromUW(const Vector3 &u, const Vector3 &w) {}
		void initFromWU(const Vector3 &w, const Vector3 &u) {}

		/**
		 *
		 */
		void initFromVW(const Vector3 &v, const Vector3 &w) {}
		void initFromWV(const Vector3 &w, const Vector3 &v) {}

		/**
		 *
		 * @param is
		 * @param t
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, ONB &t){

		}

		/**
		 *
		 * @param os
		 * @param t
		 * @return
		 */
		friend std::ostream &operator<<(std::ostream &os, const ONB &t){
			os << t.u() << t.v() << t.w();
			return os;
		}

		/**
		 *	Compare
		 * @return true if equal.
		 */
		friend bool operator==(const ONB &o1, const ONB &o2) {
			return (o1.u() == o2.u()) && (o1.v() == o2.v()) && (o1.w() == o2.w());
		}

		/**
		 *	Compare
		 * @return true if equal.
		 */
		friend bool operator!=(const ONB &o1, const ONB &o2) {
			return (o1.u() != o2.u()) && (o1.v() != o2.v()) && (o1.w() != o2.w());
		}

		ONB &operator=(const ONB &onb) {
			setU(onb.u());
			setV(onb.v());
			setW(onb.w());
			return *this;
		}

		/**
		 * @return
		 */
		inline const Vector3 &u(void) const { return this->m[0]; }

		/**
		 * @return
		 */
		inline const Vector3 &v(void) const { return this->m[1]; }

		/**
		 * @return
		 */
		inline const Vector3 &w(void) const { return this->m[2]; }

	  private:		  /*	Attributes.	*/
		Vector3 m[3]; /*	*/
	};
} // namespace LIBHPM

#endif
