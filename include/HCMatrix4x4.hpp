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
#include "HCQuaternion.hpp"
#include "HCTypes.hpp"
#include "HCVector3.hpp"
#include "HCVector4.hpp"

namespace LIBHPM {
	/**
	 * Right handed 4x4 Matrix
	 * with single precision.
	 */
	struct HCDECLSPEC alignas(alignof(hpmvec4x4f_t)) Matrix4x4 {
	  public:
		Matrix4x4() = default;
		Matrix4x4(const Matrix4x4 &other) { *this = other; }
		~Matrix4x4() = default;

	  private: /*	Attributes.	*/
		hpmvec4x4f_t e;

	  public: /*	Public methods. */
		/**
		 * Check if matrix is an
		 * identity matrix.
		 *
		 * @return true if identity.
		 */
		bool HCAPIENTRY isIdentity() {
			static const Matrix4x4 identity = Matrix4x4::identity();
			return *this == identity;
		}

		/**
		 * Compute determinant of the matrix.
		 *
		 * @return determine of matrix.
		 */
		float HCAPIENTRY determinant() const noexcept { return hpm_mat4x4_determinantfv(this->e); }

		/**
		 * Compute the inverse vector
		 * if possible.
		 *
		 * @return inversed matrix if successful.
		 */
		Matrix4x4 HCAPIENTRY inverse() const {
			Matrix4x4 res;
			hpm_mat4x4_inversefv(this->e, res.e);
			return res;
		}

		/**
		 * Transpose the matrix.
		 *
		 * @return transposed matrix.
		 */
		Matrix4x4 HCAPIENTRY transpose() const {
			Matrix4x4 mat = *this;
			hpm_mat4x4_transposefv(mat.e);
			return mat;
		}

		/**
		 * Get element by index.
		 */
		float operator[](int index) const {
			 return  this->e[index / 4][index % 4];
		}

		/**
		 * Multiply matrix by scale factor.
		 * @return
		 */
		Matrix4x4 operator*(float rh) const {
			Matrix4x4 mat = *this;
			hpm_mat4x4_multiply_scalarf(this->e, rh, mat.e);
			return mat;
		}

		/**
		 * Multiply matrix with matrix.
		 * @return matrix product.
		 */
		Matrix4x4 operator*(const Matrix4x4 &rh) const {
			Matrix4x4 mat;
			hpm_mat4x4_multiply_mat4x4fv(this->e, rh.e, mat.e);
			return mat;
		}

		/**
		 *
		 * @return
		 */
		Vector4 operator*(const Vector4 &rh) const {
			Vector4 vm;
			hpm_mat4x4_multiply_mat1x4fv(this->e, (const hpmvec4f *)&rh, (hpmvec4f *)&vm);
			return vm;
		}

		/**
		 * @return
		 */
		Matrix4x4 operator+(const Matrix4x4 &rh) const {
			Matrix4x4 mat;
			hpm_mat4x4_additition_mat4x4fv(this->e, rh.e, mat.e);
			return mat;
		}

		/**
		 * @return
		 */
		Matrix4x4 operator-(const Matrix4x4 &rh) const {
			Matrix4x4 mat;
			hpm_mat4x4_subraction_mat4x4fv(this->e, rh.e, mat.e);
			return mat;
		}

		/**
		 * Assign matrix.
		 * @return
		 */
		Matrix4x4 &operator=(const Matrix4x4 &rh) {
			hpm_mat4x4_copyfv(this->e, rh.e);
			return *this;
		}
		Matrix4x4 &operator=(Matrix4x4 &&other) = default;

		/**
		 * @return
		 */
		Matrix4x4 &operator+=(const Matrix4x4 &rh) {
			*this = *this + rh;
			return *this;
		}

		/**
		 * @return
		 */
		Matrix4x4 &operator-=(const Matrix4x4 &rh) {
			*this = *this - rh;
			return *this;
		}

		/**
		 * @return
		 */
		Matrix4x4 &operator*=(const Matrix4x4 &rh) {
			*this = *this * rh;
			return *this;
		}

		/**
		 * Equalitiy
		 * @return
		 */
		bool operator==(const Matrix4x4 &rh) { return (bool)hpm_mat4_eqfv(this->e, rh.e); }
		bool operator!=(const Matrix4x4 &rh) { return (bool)hpm_mat4_neqfv(this->e, rh.e); }

		/**
		 * Create input stream for creating matrix
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Matrix4x4 &t) {
			// is >> *((Vector4 *)t[0]);
			// is >> *((Vector4 *)t[1]);
			// is >> *((Vector4 *)t[2]);
			// is >> *((Vector4 *)t[3]);
			return is;
		}

		/**
		 * Create output stream of matrix value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Matrix4x4 &t) {

			// os << '|' << *((Vector4 *)t[0]) << "|\n";
			// os << '|' << *((Vector4 *)t[1]) << "|\n";
			// os << '|' << *((Vector4 *)t[2]) << "|\n";
			// os << '|' << *((Vector4 *)t[3]) << "|\n";
			return os;
		}

	  public: /*	Static methods.	*/
		/**
		 * Create translation matrix.
		 *
		 * @return translated matrix.
		 */
		static Matrix4x4 HCAPIENTRY translate(float x, float y, float z) {
			Matrix4x4 mat;
			hpm_mat4x4_translationf(mat.e, x, y, z);
			return mat;
		}

		/**
		 * Create translation matrix.
		 *
		 * @return translated matrix.
		 */
		static Matrix4x4 HCAPIENTRY translate(const Vector3 &translation) {
			Matrix4x4 mat;
			hpm_mat4x4_translationfv(mat.e, (hpmvec3f *)&translation);
			return mat;
		}

		/**
		 * Create rotation matrix from angle around the axis.
		 *
		 * @return rotation matrix.
		 */
		static Matrix4x4 HCAPIENTRY rotate(float angle, const Vector3 &axis) {
			Matrix4x4 mat;
			hpm_mat4x4_rotationfv(mat.e, angle, (hpmvec3f *)&axis);
			return mat;
		}

		/**
		 * Create rotation matrix from quaternion.
		 *
		 * @return rotation matrix.
		 */
		static Matrix4x4 HCAPIENTRY rotate(const Quaternion &quat) {
			Matrix4x4 mat;
			hpm_mat4x4_rotationQfv(mat.e, &quat.e);
			return mat;
		}

		/**
		 * Create scale matrix.
		 *
		 * @return scale matrix.
		 */
		static Matrix4x4 HCAPIENTRY scale(float x, float y, float z) {
			Matrix4x4 mat;
			hpm_mat4x4_scalef(mat.e, x, y, z);
			return mat;
		}

		/**
		 * Create scale matrix.
		 *
		 * @return scale matrix.
		 */
		static Matrix4x4 HCAPIENTRY scale(const Vector3 &scale) {
			Matrix4x4 mat;
			hpm_mat4x4_scalefv(mat.e, (const hpmvec3f *)&scale);
			return mat;
		}

		/**
		 * Create look at matrix.
		 * @return model matrix.
		 */
		static Matrix4x4 HCAPIENTRY lookAt(const Vector3 &lookPosition, const Vector3 &position, const Vector3 &up) {
			Matrix4x4 look;
			hpm_util_lookatfv((hpmvec3f *)&lookPosition, (hpmvec3f *)&position, (hpmvec3f *)&up, look.e);
			return look;
		}

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
		static Matrix4x4 HCAPIENTRY perspective(float fov, float aspect, float near, float far) {
			Matrix4x4 mat;
			hpm_mat4x4_projfv(mat.e, fov, aspect, near, far);
			return mat;
		}

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
		static Matrix4x4 HCAPIENTRY orth(float left, float right, float bottom, float top, float near, float far) {
			Matrix4x4 mat;
			hpm_mat4x4_orthfv(mat.e, left, right, bottom, top, near, far);
			return mat;
		}

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
		static int HCAPIENTRY unProject(float winx, float winy, float winz, const Matrix4x4 &projection,
										const Matrix4x4 &modelview, const int *HPM_RESTRICT viewport,
										Vector3 &HPM_RESTRICT pos) {
			return hpm_mat4x4_unprojf(winx, winy, winz, projection.e, modelview.e, viewport, &pos.e);
		}

		/**
		 * Create bias matrix.
		 * @return bias matrix.
		 */
		static Matrix4x4 HCAPIENTRY biasMatrix() {
			const hpmvec4x4f_t bias = {
				{0.5f, 0.0f, 0.0f, 0.0f},
				{0.0f, 0.5f, 0.0f, 0.0f},
				{0.0f, 0.0f, 0.5f, 0.0f},
				{0.5f, 0.5f, 0.5f, 1.0f},
			};

			Matrix4x4 biasMatrix;
			hpm_mat4x4_copyfv(biasMatrix.e, bias);
			return biasMatrix;
		}

		/**
		 * Create identity matrix.
		 * @return identity matrix.
		 */
		static Matrix4x4 HCAPIENTRY identity() noexcept {
			Matrix4x4 mat;
			hpm_mat4x4_identityfv(mat.e);
			return mat;
		}
	};
} // namespace LIBHPM

#endif
