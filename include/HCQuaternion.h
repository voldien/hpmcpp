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
#ifndef _HPMCPP_QUATERNION_H_
#define _HPMCPP_QUATERNION_H_ 1
#include "HCTypes.h"

namespace LIBHPM {

	/**
	 * Quaternion class. Contains
	 * w, x, y, z component. Where the
	 * size of the object is 128 bit.
	 */
	struct HCDECLSPEC alignas(alignof(hpmquatf)) Quaternion {
		friend struct Matrix4x4;

	  public:
		Quaternion(void) = default;
		Quaternion(const Quaternion &quaternion);
		Quaternion(float w, float x, float y, float z);
		Quaternion(float pitch, float yaw, float roll);

		/**
		 * Get individual component.
		 */
		float HCAPIFASTENTRY x(void) const noexcept;
		float HCAPIFASTENTRY y(void) const noexcept;
		float HCAPIFASTENTRY z(void) const noexcept;
		float HCAPIFASTENTRY w(void) const noexcept;

		/**
		 * Set individual component.
		 */
		void HCAPIFASTENTRY setW(float w);
		void HCAPIFASTENTRY setX(float x);
		void HCAPIFASTENTRY setY(float y);
		void HCAPIFASTENTRY setZ(float z);

		/**
		 * Set all quaternion components.
		 */
		void HCAPIENTRY set(float w, float x, float y, float z);

		/**
		 * Get up and forward vector
		 * of quaternion.
		 *
		 * @return normalized direction vector.
		 */
		Vector3 HCAPIENTRY up(void) const;
		Vector3 HCAPIENTRY forward(void) const;

		/**
		 * Get
		 * @return
		 */
		Vector3 HCAPIENTRY getVector(void) const;

		/**
		 * Get direction vector from direction
		 * vector.
		 * @return normalized direction vector.
		 */
		Vector3 HCAPIENTRY getVector(const Vector3 &direction) const;

		/**
		 * Compute the magnitude.
		 *
		 * @return non-negativ number.
		 */
		float HCAPIENTRY magnitude(void) const;

		/**
		 * @return non-negativ number.
		 */
		float HCAPIENTRY magnitudeSquared(void);

		/**
		 * Compute dot product from two quaternion.
		 *
		 * @return
		 */
		friend float HCAPIFASTENTRY dot(const Quaternion &lh, const Quaternion &rh);

		/**
		 * Normalize quaternion.
		 */
		void HCAPIENTRY makeUnitQuaternion(void);

		/**
		 * Compute normalized quaternion.
		 *
		 * @return
		 */
		Quaternion HCAPIENTRY normalize(void) const;

		/**
		 * Create conjugate quaternion from
		 * this quaternion.
		 *
		 * @return conjugated quaternion.
		 */
		Quaternion HCAPIENTRY conjugate(void) const;

		/**
		 * Compute quaternion inverse.
		 * @return
		 */
		Quaternion HCAPIENTRY inverse(void) const;

		/**
		 *
		 * @param exponent
		 * @return
		 */
		Quaternion HCAPIENTRY exponent(float exponent) const;

		/**
		 * Get element by index.
		 * @return
		 */
		float operator[](int i) const;
		float &operator[](int i);

		/**
		 * Create input stream for creating quaternion
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Quaternion &t);

		/**
		 * Create output stream of quaternion value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Quaternion &t);

		/**
		 *
		 * @param lh
		 * @param rh
		 * @return
		 */
		friend Quaternion operator+(const Quaternion &lh, const Quaternion &rh);

		/**
		 *
		 * @param lh
		 * @param rh
		 * @return
		 */
		friend Quaternion operator-(const Quaternion &lh, const Quaternion &rh);

		/**
		 *
		 * @return
		 */
		friend Quaternion operator*(const Quaternion &lh, const Quaternion &rh);

		/**
		 * @return
		 */
		friend Quaternion operator*(const Quaternion &lh, const Vector3 &rh);

		/**
		 * @return
		 */
		friend Quaternion operator*(const Quaternion &lh, float rh);

		/**
		 * @return
		 */
		Quaternion &operator*=(const Quaternion &rh);
		Quaternion &operator*=(const Vector3 &rh);
		Quaternion &operator*=(float rh);

		/**
		 * @return
		 */
		Quaternion &operator=(const Quaternion &rh);

		/**
		 * Compare quaternion equality by
		 * checking component wise.
		 * @return true if equal, false otherwise.
		 */
		friend bool operator==(const Quaternion &v1, const Quaternion &v2);
		friend bool operator!=(const Quaternion &v1, const Quaternion &v2);

		/**
		 * Get rotation of each axis in
		 * radius.
		 * @return
		 */
		float HCAPIFASTENTRY getPitch(void) const;

		/**
		 *
		 * @return
		 */
		float HCAPIFASTENTRY getYaw(void) const;

		/**
		 *
		 * @return
		 */
		float HCAPIFASTENTRY getRoll(void) const;

		/**
		 *
		 * @param pitch
		 * @param yaw
		 * @param roll
		 */
		void HCAPIFASTENTRY getEular(float *pitch, float *yaw, float *roll) const;

		/**
		 *
		 * @return
		 */
		Vector3 HCAPIENTRY getEular(void) const;

	  protected: /*	Attributes.	*/
		hpmquatf e;

	  public: /*	Static utility methods.	*/
		/**
		 * Create look rotation quaternion.
		 *
		 * @return
		 */
		static Quaternion HCAPIENTRY lookRotation(const Vector3 &target, const Vector3 &pos, const Vector3 &up);

		/**
		 * Create quaternion from eular rotation.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY createQuaternionOfAxis(float pitch, float yaw, float roll);

		/**
		 * Create quaternion from eular rotation.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY createQuaternionOfAxis(const Vector3 &axis);

		/**
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY createFromAxisAngle(const Vector3 &axis, float angle);

		/**
		 * Convert direction to quaternion.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY createQuaternionOfDirection(Vector3 &direction);

		/**
		 * Linear interpolation.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY lerp(const Quaternion &from, const Quaternion &to, float speed);

		/**
		 * Spherical interpolation.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY slerp(const Quaternion &from, const Quaternion &to, float speed);

		/**
		 * Create quaternion identity.
		 * @return identitiy.
		 */
		static Quaternion HCAPIENTRY identity(void);
	};
} // namespace LIBHPM

#endif
