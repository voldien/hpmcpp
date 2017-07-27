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
 *	Right handed 4x4 Matrix.
 */
class HCDECLSPEC HCMatrix4x4{
public:
	HCMatrix4x4(void);
	HCMatrix4x4(const HCMatrix4x4& other);

private:	/*	Attributes.	*/

	hpmvec4x4f_t e;

public:		/*	*/

	/**
	 *	@Return
	 */
	bool isIdentity(void);

	/**
	 *	Compute determinant of the matrix.
	 */
	float determinant(void) const;

	/**
	 *	Compute the inverse vector
	 *	if possible.
	 */
	HCMatrix4x4 inverse(void) const;

	/**
	 *	Transpose the matrix.
	 */
	HCMatrix4x4 transpose(void) const;

	/**
	 *
	 */
	inline float* operator[](int index) const {
		return (float*) &this->e[index][0];
	}
	inline float* operator[](int index) {
		return (float*) &this->e[index][0];
	}

	/**
	 *	@Return
	 */
    HCMatrix4x4 operator*(float rh) const;
	HCMatrix4x4 operator*(const HCMatrix4x4& rh) const;
	HCVector4 operator*(const HCVector4& rh) const;
	HCMatrix4x4 operator+(const HCMatrix4x4& rh) const;
	HCMatrix4x4 operator-(const HCMatrix4x4& rh) const;

	/**
	 *
	 *	@Return
	 */
	HCMatrix4x4& operator=(const HCMatrix4x4& rh);
	HCMatrix4x4& operator+=(const HCMatrix4x4& rh);
	HCMatrix4x4& operator-=(const HCMatrix4x4& rh);
	HCMatrix4x4& operator*=(const HCMatrix4x4& rh);

	/**
	 *
	 *	@Return
	 */
	bool operator==(const HCMatrix4x4& rh);
	bool operator!=(const HCMatrix4x4& rh);


	/**
	 *
	 *	@Return
	 */
	friend std::istream &operator>>(std::istream &is, HCMatrix4x4& t);
	friend std::ostream &operator<<(std::ostream &os, const HCMatrix4x4& t);


public:	/*	Static methods.	*/

	/**
	 *	Create translation matrix.
	 *
	 *	@Return translated matrix
	 */
	static HCMatrix4x4 translate(float x, float y, float z);

	/**
	 *	Create translation matrix.
	 *
	 *	@Return translated matrix
	 */
	static HCMatrix4x4 translate(const HCVector3& translation);

	/**
	 *	Create rotation matrix from angle around the axis.
	 *
	 *	@Return
	 */
	static HCMatrix4x4 rotate(float angle, const HCVector3& axis);

	/**
	 *	Create rotation matrix from quaternion.
	 *
	 *	@Return
	 */
	static HCMatrix4x4 rotate(const HCQuaternion& quat);

	/**
	 *	Create scale matrix.
	 *
	 *	@Return
	 */
	static HCMatrix4x4 scale(float x, float y, float z);

	/**
	 *	Create scale matrix.
	 *
	 *	@Return
	 */
	static HCMatrix4x4 scale(const HCVector3& scale);

	/**
	 *	Create perspectice matrix.
	 *
	 *	@Return
	 */
	static HCMatrix4x4 perspective(float fov, float aspect, float near,
			float far);

	/**
	 *
	 *
	 *	@Return
	 */
	static HCMatrix4x4 lookAt(const HCVector3& lookPosition,
			const HCVector3& position, const HCVector3& forward);

	/**
	 *	Create orthographic perspectice.
	 *
	 *	@Return
	 */
	static HCMatrix4x4 orth(float left, float right, float bottom, float top,
			float near, float far);

	/**
	 *	Create bias matrix.
	 */
	static HCMatrix4x4 biasMatrix(void);

	/**
	 *	Create identity matrix.
	 */
	static HCMatrix4x4 identity(void);
};

#endif
