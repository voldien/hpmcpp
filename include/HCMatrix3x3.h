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
#ifndef _HPMCPP_MATRIX3X3_H_
#define _HPMCPP_MATRIX3X3_H_ 1
#include "HCTypes.h"

/**
 *	Right handed Matrix3x3.
 */
class HCDECLSPEC HCMatrix3x3{
public:
	HCMatrix3x3(void);
	HCMatrix3x3(const HCMatrix3x3& other);
	explicit HCMatrix3x3(const HCMatrix4x4& Identity);
	explicit HCMatrix3x3(float* matrix);
	explicit HCMatrix3x3(const double* matrix);
	explicit HCMatrix3x3(float identity);

private:	/*	Attributes.	*/

	hpmvec4x4f_t e;

public:	/*	Public methods.	*/

	/**
	 *	Compute determinant.
	 *	@Return
	 */
	float HCAPIENTRY determinant(void) const;

	/**
	 *	@Return
	 */
	HCMatrix3x3 HCAPIENTRY inverse(void);

	/**
	 *	@Return
	 */
	bool HCAPIENTRY isIdentity(void) const;

	/**
	 *	@Return
	 */
	HCMatrix4x4 HCAPIENTRY identity(void);

	/**
	 *	Create transpose matrix.
	 *	@Return
	 */
	HCMatrix3x3 HCAPIENTRY transpose(void) const;

	/**
	 *	@Return
	 */
	HCVector3& operator[](const unsigned int index);
	inline float* operator[](int index)const{return (float*)&this->e[index][0];}

	/**
	 *	@Return
	 */
	HCMatrix3x3 operator*(const HCMatrix3x3& rh) const;
	HCMatrix4x4 operator*(const HCMatrix4x4& rh) const;
	HCMatrix3x3 operator+(const HCMatrix3x3& rh) const;
	HCMatrix3x3 operator-(const HCMatrix3x3& rh) const;
	HCMatrix3x3 operator/(const HCMatrix3x3& rh) const;

	/**
	 *	@Return
	 */
	HCMatrix3x3& operator=(const HCMatrix3x3& rh);
	HCMatrix3x3& operator=(const HCMatrix4x4& rh);
	HCMatrix3x3& operator+=(const HCMatrix3x3& rh);
	HCMatrix3x3& operator-=(const HCMatrix3x3& rh);
	HCMatrix3x3& operator*=(const HCMatrix3x3& rh);
	HCMatrix3x3& operator/=(const HCMatrix3x3& rh);

	/**
	 *	Create input stream for creating matrix
	 *	from input stream.
	 *	@Return stream reference.
	 */
	friend std::istream &operator>>(std::istream &is, HCMatrix3x3& t);

	/**
	 *	Create output stream of matrix value.
	 *	@Return stream reference.
	 */
	friend std::ostream &operator<<(std::ostream &os, const HCMatrix3x3& t);
};

#endif
