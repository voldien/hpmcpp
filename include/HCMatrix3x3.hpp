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
#include "HCTypes.hpp"

namespace LIBHPM {
	/**
	 *	Right handed Matrix3x3.
	 */
	struct HCDECLSPEC alignas(alignof(hpmvec4x4f_t)) Matrix3x3 {
	  public:
		Matrix3x3() = default;
		Matrix3x3(const Matrix3x3 &other);
		explicit Matrix3x3(const Matrix4x4 &Identity);
		explicit Matrix3x3(const float *matrix);
		explicit Matrix3x3(const double *matrix);
		explicit Matrix3x3(float identity);
		~Matrix3x3() = default;

	  private: /*	Attributes.	*/
		hpmvec4x4f_t e;

	  public: /*	Public methods.	*/
		/**
		 * Compute determinant.
		 * @return
		 */
		float HCAPIENTRY determinant() const;

		/**
		 * @return
		 */
		Matrix3x3 HCAPIENTRY inverse();

		/**
		 * @return
		 */
		bool HCAPIENTRY isIdentity() const;

		/**
		 * @return
		 */
		Matrix4x4 HCAPIENTRY identity();

		/**
		 * Create transpose matrix.
		 * @return
		 */
		Matrix3x3 HCAPIENTRY transpose() const;

		/**
		 * @return
		 */
		Vector3 &operator[](const unsigned int index);
		float *operator[](int index) const;

		/**
		 * @return
		 */
		Matrix3x3 operator*(const Matrix3x3 &rh) const;
		Matrix4x4 operator*(const Matrix4x4 &rh) const;
		Matrix3x3 operator+(const Matrix3x3 &rh) const;
		Matrix3x3 operator-(const Matrix3x3 &rh) const;
		Matrix3x3 operator/(const Matrix3x3 &rh) const;

		/**
		 * @return
		 */
		Matrix3x3 &operator=(const Matrix3x3 &rh);
		Matrix3x3 &operator=(const Matrix4x4 &rh);
		Matrix3x3 &operator+=(const Matrix3x3 &rh);
		Matrix3x3 &operator-=(const Matrix3x3 &rh);
		Matrix3x3 &operator*=(const Matrix3x3 &rh);
		Matrix3x3 &operator/=(const Matrix3x3 &rh);

		/**
		 * Create input stream for creating matrix
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Matrix3x3 &t);

		/**
		 * Create output stream of matrix value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Matrix3x3 &t);
	};
} // namespace LIBHPM

#endif
