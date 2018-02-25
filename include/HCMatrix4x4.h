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
#ifndef _HPMCPP_MATRIX4X4_H_
#define _HPMCPP_MATRIX4X4_H_ 1
#include "HCTypes.h"

/**
 *	Right handed 4x4 Matrix
 *	with single precision.
 */
class HCDECLSPEC HCMatrix4x4{
public:
	HCMatrix4x4(void);
	HCMatrix4x4(const HCMatrix4x4& other);

private:	/*	Attributes.	*/

	hpmvec4x4f_t e;

public:	/*	Public methods. */

	/**
	 *	Check if matrix is an
	 *	identity matrix.
	 *
	 *	@Return true if identity.
	 */
	bool HCAPIENTRY isIdentity(void);

	/**
	 *	Compute determinant of the matrix.
	 *
	 *	@Return determine of matrix.
	 */
	float HCAPIENTRY determinant(void) const;

	/**
	 *	Compute the inverse vector
	 *	if possible.
	 *
	 *	@Return inversed matrix if successful.
	 */
	HCMatrix4x4 HCAPIENTRY inverse(void) const;

	/**
	 *	Transpose the matrix.
	 *
	 *	@Return transposed matrix.
	 */
	HCMatrix4x4 HCAPIENTRY transpose(void) const;

	/**
	 *  Get element by index.
	 */
	inline float* operator[](int index) const {
		return (float*) &this->e[index][0];
	}
	inline float* operator[](int index) {
		return (float*) &this->e[index][0];
	}

	/**
	 *	Multiply matrix by scale factor.
	 *
	 *	@Return
	 */
	HCMatrix4x4 operator*(float rh) const;

	/**
	 *	Multiply matrix with matrix.
	 *	@Return matrix product.
	 */
	HCMatrix4x4 operator*(const HCMatrix4x4& rh) const;

	/**
	 *
	 *	@Return
	 */
	HCVector4 operator*(const HCVector4& rh) const;

	/**
	 *	@Return
	 */
	HCMatrix4x4 operator+(const HCMatrix4x4& rh) const;

	/**
	 *	@Return
	 */
	HCMatrix4x4 operator-(const HCMatrix4x4& rh) const;

	/**
	 *	Assign matrix.
	 *	@Return
	 */
	HCMatrix4x4& operator=(const HCMatrix4x4& rh);

	/**
	 *	@Return
	 */
	HCMatrix4x4& operator+=(const HCMatrix4x4& rh);

	/**
	 *	@Return
	 */
	HCMatrix4x4& operator-=(const HCMatrix4x4& rh);

	/**
	 *	@Return
	 */
	HCMatrix4x4& operator*=(const HCMatrix4x4& rh);

	/**
	 *	Equalitiy
	 *	@Return
	 */
	bool operator==(const HCMatrix4x4& rh);
	bool operator!=(const HCMatrix4x4& rh);

	/**
	 *	Create input stream for creating matrix
	 *	from input stream.
	 *	@Return stream reference.
	 */
	friend std::istream &operator>>(std::istream &is, HCMatrix4x4& t);

	/**
	 *	Create output stream of matrix value.
	 *	@Return stream reference.
	 */
	friend std::ostream &operator<<(std::ostream &os, const HCMatrix4x4& t);


public:	/*	Static methods.	*/

	/**
	 *	Create translation matrix.
	 *
	 *	@Return translated matrix.
	 */
	static HCMatrix4x4 HCAPIENTRY translate(float x, float y, float z);

	/**
	 *	Create translation matrix.
	 *
	 *	@Return translated matrix.
	 */
	static HCMatrix4x4 HCAPIENTRY translate(const HCVector3& translation);

	/**
	 *	Create rotation matrix from angle around the axis.
	 *
	 *	@Return rotation matrix.
	 */
	static HCMatrix4x4 HCAPIENTRY rotate(float angle, const HCVector3& axis);

	/**
	 *	Create rotation matrix from quaternion.
	 *
	 *	@Return rotation matrix.
	 */
	static HCMatrix4x4 HCAPIENTRY rotate(const HCQuaternion& quat);

	/**
	 *	Create scale matrix.
	 *
	 *	@Return scale matrix.
	 */
	static HCMatrix4x4 HCAPIENTRY scale(float x, float y, float z);

	/**
	 *	Create scale matrix.
	 *
	 *	@Return scale matrix.
	 */
	static HCMatrix4x4 HCAPIENTRY scale(const HCVector3& scale);

	/**
	 *	Create look at matrix.
	 *	@Return model matrix.
	 */
	static HCMatrix4x4 HCAPIENTRY lookAt(const HCVector3& lookPosition,
	        const HCVector3& position, const HCVector3& up);

	/**
	 *	Create perspectice matrix.
	 *
	 *	\fov field of view in radius.
	 *
	 *	\aspect view ratio.
	 *
	 *	\near near plane.
	 *
	 *	\far far plane.
	 *
	 *	@Return
	 */
	static HCMatrix4x4 HCAPIENTRY perspective(float fov, float aspect,
	        float near, float far);

	/**
	 *	Create orthographic perspectice.
	 *
	 *	\left
	 *
	 *	\right
	 *
	 *	\bottom
	 *
	 *	\top
	 *
	 *	\near
	 *
	 *	\far
	 *
	 *	@Return
	 */
	static HCMatrix4x4 HCAPIENTRY orth(float left, float right, float bottom,
	        float top, float near, float far);

	/**
	 *	Create bias matrix.
	 */
	static HCMatrix4x4 HCAPIENTRY biasMatrix(void);

	/**
	 *	Create identity matrix.
	 *
	 *	@Return
	 */
	static HCMatrix4x4 HCAPIENTRY identity(void);
};

#endif
