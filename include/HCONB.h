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

#define ONB_EPSILON 0.01f

/**
 *	ORTHONORMAL BASED AND FRAMES
 */
class HCDECLSPEC HCONB {
public:
	HCONB(void);
	HCONB(const HCONB& other);
	HCONB(const HCVector3& a, const HCVector3& b, const HCVector3& c);

	/**
	 *
	 */
	void initFromU(const HCVector3& u);
	void initFromV(const HCVector3& v);
	void initFromW(const HCVector3& w);

	/**
	 *
	 */
	void set(const HCVector3& a, const HCVector3& b, const HCVector3& c);
	void setU(const HCVector3& u);
	void setV(const HCVector3& v);
	void setW(const HCVector3& w);

	/**
	 *
	 */
	void initFromUV(const HCVector3& u, const HCVector3& v);
	void initFromVU(const HCVector3& v, const HCVector3& u);

	/**
	 *
	 */
	void initFromUW(const HCVector3& u, const HCVector3& w);
	void initFromWU(const HCVector3& w, const HCVector3& u);

	/**
	 *
	 */
	void initFromVW(const HCVector3& v, const HCVector3& w);
	void initFromWV(const HCVector3& w, const HCVector3& v);

	/**
	 *
	 *	@Return stream reference.
	 */
	friend std::istream &operator>>(std::istream& is, HCONB& t);

	/**
	 *	@Return stream reference.
	 */
	friend std::ostream &operator<<(std::ostream& is, const HCONB& t);

	/**
	 *	Compare 
	 *	@Return true if equal.
	 */
	friend bool operator==(const HCONB& o1, const HCONB& o2);

	/**
	 *	Compare 
	 *	@Return true if equal.
	 */
	friend bool operator!=(const HCONB& o1, const HCONB& o2);

	/**
	 *
	 */
	HCONB& operator=(const HCONB& onb);

	/**
	 *	@Return
	 */
	inline const HCVector3& u(void) const {
		return this->m[0];
	}

	/**
	 *	@Return
	 */
	inline const HCVector3& v(void) const {
		return this->m[1];
	}

	/**
	 *	@Return
	 */
	inline const HCVector3& w(void) const {
		return this->m[2];
	}

private:	/*	Attributes.	*/

	HCVector3 m[3];		/*	*/

};

#endif
