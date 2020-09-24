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
namespace hpmcpp {
	/**
	 * Right handed 4x4 Matrix
	 * with single precision.
	 */
	class HCDECLSPEC Matrix4x4{
	public:
		Matrix4x4(void) = default;
		Matrix4x4(const Matrix4x4& other);
		~Matrix4x4(void) = default;

	private:	/*	Attributes.	*/
		hpmvec4x4f_t e;

	public:	/*	Public methods. */

		/**
		 * Check if matrix is an
		 * identity matrix.
		 *
		 * @return true if identity.
		 */
		bool HCAPIENTRY isIdentity(void);

		/**
		 * Compute determinant of the matrix.
		 *
		 * @return determine of matrix.
		 */
		float HCAPIENTRY determinant(void) const;

		/**
		 * Compute the inverse vector
		 * if possible.
		 *
		 * @return inversed matrix if successful.
		 */
		Matrix4x4 HCAPIENTRY inverse(void) const;

		/**
		 * Transpose the matrix.
		 *
		 * @return transposed matrix.
		 */
		Matrix4x4 HCAPIENTRY transpose(void) const;

		/**
		 * Get element by index.
		 */
		float* operator[](int index) const;
		float* operator[](int index);

		/**
		 * Multiply matrix by scale factor.
		 * @return
		 */
		Matrix4x4 operator*(float rh) const;

		/**
		 * Multiply matrix with matrix.
		 * @return matrix product.
		 */
		Matrix4x4 operator*(const Matrix4x4& rh) const;

		/**
		 *
		 * @return
		 */
		Vector4 operator*(const Vector4& rh) const;

		/**
		 * @return
		 */
		Matrix4x4 operator+(const Matrix4x4& rh) const;

		/**
		 * @return
		 */
		Matrix4x4 operator-(const Matrix4x4& rh) const;

		/**
		 * Assign matrix.
		 * @return
		 */
		Matrix4x4& operator=(const Matrix4x4& rh);

		/**
		 * @return
		 */
		Matrix4x4& operator+=(const Matrix4x4& rh);

		/**
		 * @return
		 */
		Matrix4x4& operator-=(const Matrix4x4& rh);

		/**
		 * @return
		 */
		Matrix4x4& operator*=(const Matrix4x4& rh);

		/**
		 * Equalitiy
		 * @return
		 */
		bool operator==(const Matrix4x4& rh);
		bool operator!=(const Matrix4x4& rh);

		/**
		 * Create input stream for creating matrix
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Matrix4x4& t);

		/**
		 * Create output stream of matrix value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Matrix4x4& t);


	public:	/*	Static methods.	*/

		/**
		 * Create translation matrix.
		 *
		 * @return translated matrix.
		 */
		static Matrix4x4 HCAPIENTRY translate(float x, float y, float z);

		/**
		 * Create translation matrix.
		 *
		 * @return translated matrix.
		 */
		static Matrix4x4 HCAPIENTRY translate(const Vector3& translation);

		/**
		 * Create rotation matrix from angle around the axis.
		 *
		 * @return rotation matrix.
		 */
		static Matrix4x4 HCAPIENTRY rotate(float angle, const Vector3& axis);

		/**
		 * Create rotation matrix from quaternion.
		 *
		 * @return rotation matrix.
		 */
		static Matrix4x4 HCAPIENTRY rotate(const Quaternion& quat);

		/**
		 * Create scale matrix.
		 *
		 * @return scale matrix.
		 */
		static Matrix4x4 HCAPIENTRY scale(float x, float y, float z);

		/**
		 * Create scale matrix.
		 *
		 * @return scale matrix.
		 */
		static Matrix4x4 HCAPIENTRY scale(const Vector3& scale);

		/**
		 * Create look at matrix.
		 * @return model matrix.
		 */
		static Matrix4x4 HCAPIENTRY lookAt(const Vector3& lookPosition,
				const Vector3& position, const Vector3& up);

		/**
		 * Create perspectice matrix.
		 *
		 * @fov field of view in radius.
		 *
		 * @aspect view ratio.
		 *
		 * @near near plane.
		 *
		 * @far far plane.
		 *
		 * @return
		 */
		static Matrix4x4 HCAPIENTRY perspective(float fov, float aspect,
				float near, float far);

		/**
		 * Create orthographic perspectice.
		 *
		 * @left
		 * @right
		 * @bottom
		 * @top
		 * @near
		 * @far
		 * @return
		 */
		static Matrix4x4 HCAPIENTRY orth(float left, float right, float bottom,
				float top, float near, float far);

		/**
		 * Unproject matrix.
		 *
		 * @param winx x coordinate position.
		 * @param winy y coordinate position.
		 * @param winz z coordinate position.
		 * @param projection project matrix.
		 * @param modelview model-view matrix.
		 * @param viewport viewport of the screen (x, y, width, height)
		 * @param pos position inside the projection space.
		 * @return non-zero if successfully unproject.
		 */
		static int HCAPIENTRY unProject(float winx, float winy, float winz, const Matrix4x4 *projection,
										const Matrix4x4 *modelview, const int *HPM_RESTRICT viewport,
										HCVector3 *HPM_RESTRICT pos);

		/**
		 * Create bias matrix.
		 * @return bias matrix.
		 */
		static Matrix4x4 HCAPIENTRY biasMatrix(void);

		/**
		 * Create identity matrix.
		 * @return identity matrix.
		 */
		static Matrix4x4 HCAPIENTRY identity(void);
	};
}

#endif
