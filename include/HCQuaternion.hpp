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
#include "HCTypes.hpp"
#include"HCVector3.hpp"

namespace LIBHPM {

	/**
	 * Quaternion class. Contains
	 * w, x, y, z component. Where the
	 * size of the object is 128 bit.
	 */

	/**
	 * @brief 
	 * 
	 */
	struct HCDECLSPEC alignas(alignof(hpmquatf)) Quaternion {
		friend struct Matrix4x4;

	  public:
		Quaternion(void) = default;
		Quaternion(const Quaternion &quaternion) noexcept { *this = quaternion; }
		Quaternion(float w, float x, float y, float z) noexcept { this->set(w, x, y, z); }
		Quaternion(float pitch, float yaw, float roll) noexcept { *this = createQuaternionOfAxis(pitch, yaw, roll); }

		/**
		 * Get individual component.
		 */
		float HCAPIFASTENTRY x(void) const noexcept { return hpm_quat_getxf(this->e); }
		float HCAPIFASTENTRY y(void) const noexcept { return hpm_quat_getyf(this->e); }
		float HCAPIFASTENTRY z(void) const noexcept { return hpm_quat_getzf(this->e); }
		float HCAPIFASTENTRY w(void) const noexcept { return hpm_quat_getwf(this->e); }

		/**
		 * Set individual component.
		 */
		void HCAPIFASTENTRY setW(float w) noexcept { hpm_quat_setxf(this->e, w); }
		void HCAPIFASTENTRY setX(float x) noexcept { hpm_quat_setyf(this->e, x); }
		void HCAPIFASTENTRY setY(float y) noexcept { hpm_quat_setzf(this->e, y); }
		void HCAPIFASTENTRY setZ(float z) noexcept { hpm_quat_setwf(this->e, z); }

		/**
		 * Set all quaternion components.
		 */
		void HCAPIENTRY set(float w, float x, float y, float z) noexcept { hpm_quat_setf(&this->e, w, x, y, z); }

		/**
		 * Get up and forward vector
		 * of quaternion.
		 *
		 * @return normalized direction vector.
		 */
		Vector3 HCAPIENTRY up(void) const noexcept { return this->getVector(Vector3::up()); }
		Vector3 HCAPIENTRY forward(void) const noexcept { return this->getVector(Vector3::forward()); }

		/**
		 * Get
		 * @return
		 */
		Vector3 HCAPIENTRY getVector(void) const noexcept {
			Vector3 dir;
			hpm_quat_directionfv(&this->e, (hpmvec3f *)&dir);
			return dir;
		}

		/**
		 * Get direction vector from direction
		 * vector.
		 * @return normalized direction vector.
		 */
		Vector3 HCAPIENTRY getVector(const Vector3 &direction) const noexcept {
			Vector3 vec;
			hpm_quat_get_vectorfv(&this->e, (const hpmvec3f *)&direction, (hpmvec3f *)&vec);
			return vec;
		}

		/**
		 * Compute the magnitude.
		 *
		 * @return non-negativ number.
		 */
		float HCAPIENTRY magnitude(void) const noexcept { return hpm_quat_lengthfv(&this->e); }

		/**
		 * @return non-negativ number.
		 */
		float HCAPIENTRY magnitudeSquared(void) const noexcept { return hpm_quat_lengthsqurefv(&this->e); }

		/**
		 * Compute dot product from two quaternion.
		 *
		 * @return
		 */
		friend float HCAPIFASTENTRY dot(const Quaternion &lh, const Quaternion &rh) noexcept {
			return hpm_quat_dotfv(&lh.e, &rh.e);
		}

		/**
		 * Normalize quaternion.
		 */
		void HCAPIENTRY makeUnitQuaternion(void) { hpm_quat_normalizefv(&this->e); }

		/**
		 * Compute normalized quaternion.
		 *
		 * @return
		 */
		Quaternion HCAPIENTRY normalize(void) const {
			Quaternion copy = *this;
			hpm_quat_normalizefv(&copy.e);
			return copy;
		}

		/**
		 * Create conjugate quaternion from
		 * this quaternion.
		 *
		 * @return conjugated quaternion.
		 */
		Quaternion HCAPIENTRY conjugate(void) const noexcept {
			Quaternion quat = *this;
			hpm_quat_conjugatefv(&quat.e);
			return quat;
		}

		/**
		 * Compute quaternion inverse.
		 * @return
		 */
		Quaternion HCAPIENTRY inverse(void) const noexcept {
			Quaternion quat = *this;
			hpm_quat_inversefv(&quat.e);
			return quat;
		}

		/**
		 *
		 * @param exponent
		 * @return
		 */
		Quaternion HCAPIENTRY exponent(float exponent) const noexcept {
			Quaternion quat = *this;
			hpm_quat_powfv(&quat.e, exponent);
			return quat;
		}

		/**
		 * Get element by index.
		 * @return
		 */
		float operator[](int i) const { return this->e[i]; }
		// float &operator[](int i) {
		// 	return this->e[i];
		// }

		/**
		 * Create input stream for creating quaternion
		 * from input stream.
		 * @return stream reference.
		 */
		friend std::istream &operator>>(std::istream &is, Quaternion &t) {
			float temp;
			is >> temp;
			t.setX(temp);
			is >> temp;
			t.setY(temp);
			is >> temp;
			t.setZ(temp);
			is >> temp;
			t.setW(temp);
			return is;
		}

		/**
		 * Create output stream of quaternion value.
		 * @return stream reference.
		 */
		friend std::ostream &operator<<(std::ostream &os, const Quaternion &t) {
			os << '(' << t.w() << " " << t.x() << " " << t.y() << " " << t.z() << ')';
			return os;
		}

		/**
		 *
		 * @param lh
		 * @param rh
		 * @return
		 */
		friend Quaternion operator+(const Quaternion &lh, const Quaternion &rh) noexcept {
			Quaternion quat = lh;
			hpm_vec4_addition_scalefv(&quat.e, &rh.e);
			return quat;
		}

		/**
		 *
		 * @param lh
		 * @param rh
		 * @return
		 */
		friend Quaternion operator-(const Quaternion &lh, const Quaternion &rh) noexcept {
			Quaternion quat = lh;
			hpm_vec4_subtractionfv(&quat.e, &rh.e);
			return quat;
		}

		/**
		 *
		 * @return
		 */
		friend Quaternion operator*(const Quaternion &lh, const Quaternion &rh) noexcept {
			Quaternion quat = lh;
			hpm_quat_multi_quatfv(&lh.e, &rh.e, &quat.e);
			return quat;
		}

		/**
		 * @return
		 */
		friend Quaternion operator*(const Quaternion &lh, const Vector3 &rh) noexcept {
			Quaternion quat = lh;
			hpm_quat_multi_vec3fv(&lh.e, (const hpmvec3f *)&rh, (hpmvec3f *)&quat.e);
			return quat;
		}

		/**
		 * @return
		 */
		friend Quaternion operator*(const Quaternion &lh, float rh) noexcept {
			Quaternion quat = lh;
			hpm_quat_multi_scalef(&quat.e, rh);
			return quat;
		}

		/**
		 * @return
		 */
		Quaternion &operator*=(const Quaternion &rh) noexcept {
			*this = *this * rh;
			return *this;
		}
		Quaternion &operator*=(const Vector3 &rh) noexcept {
			*this = *this * rh;
			return *this;
		}
		Quaternion &operator*=(float rh) noexcept {
			*this = *this * rh;
			return *this;
		}

		/**
		 * @return
		 */
		Quaternion &operator=(const Quaternion &rh) noexcept {
			hpm_quat_copyfv(&this->e, &rh.e);
			return *this;
		}

		/**
		 * Compare quaternion equality by
		 * checking component wise.
		 * @return true if equal, false otherwise.
		 */
		friend bool operator==(const Quaternion &v1, const Quaternion &v2) noexcept {
			return (bool)hpm_vec4_eqfv(&v1.e, &v2.e);
		}
		friend bool operator!=(const Quaternion &v1, const Quaternion &v2) noexcept {
			return (bool)hpm_vec4_neqfv(&v1.e, &v2.e);
		}

		/**
		 * Get rotation of each axis in
		 * radius.
		 * @return
		 */
		float HCAPIFASTENTRY getPitch(void) const noexcept { return hpm_quat_pitchfv(&this->e); }

		/**
		 *
		 * @return
		 */
		float HCAPIFASTENTRY getYaw(void) const noexcept { return hpm_quat_yawfv(&this->e); }

		/**
		 *
		 * @return
		 */
		float HCAPIFASTENTRY getRoll(void) const noexcept { return hpm_quat_rollfv(&this->e); }

		/**
		 *
		 * @param pitch
		 * @param yaw
		 * @param roll
		 */
		void HCAPIFASTENTRY getEular(float *pitch, float *yaw, float *roll) const noexcept {
			hpm_quat_eularfv(&this->e, pitch, yaw, roll);
		}

		/**
		 *
		 * @return
		 */
		Vector3 HCAPIENTRY getEular(void) const noexcept {

			float pitch, yaw, roll;
			hpm_quat_eularfv(&this->e, &pitch, &yaw, &roll);
			return Vector3(pitch, yaw, roll);
		}

	  protected: /*	Attributes.	*/
		hpmquatf e;

	  public: /*	Static utility methods.	*/
		/**
		 * Create look rotation quaternion.
		 *
		 * @return
		 */
		static Quaternion HCAPIENTRY lookRotation(const Vector3 &target, const Vector3 &pos,
												  const Vector3 &up) noexcept {
			Quaternion quat;
			hpm_quat_lookatfv((const hpmvec3f *)&target, (const hpmvec3f *)&pos.e, (const hpmvec3f *)&up.e, &quat.e);
			return quat;
		}

		/**
		 * Create quaternion from eular rotation.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY createQuaternionOfAxis(float pitch, float yaw, float roll) noexcept {
			Quaternion quat;
			hpm_quat_axisf(&quat.e, pitch, yaw, roll);
			return quat;
		}

		/**
		 * Create quaternion from eular rotation.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY createQuaternionOfAxis(const Vector3 &axis) noexcept {
			return createQuaternionOfAxis(axis.x(), axis.y(), axis.z());
		}

		/**
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY createFromAxisAngle(const Vector3 &axis, float angle) noexcept {
			Quaternion quat;
			hpm_quat_axis_anglefv(&quat.e, (hpmvec3f *)&axis, angle);
			return quat;
		}

		/**
		 * Convert direction to quaternion.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY createQuaternionOfDirection(const Vector3 &direction) noexcept {
			return createQuaternionOfAxis(0, 0, 0);
		}

		/**
		 * Linear interpolation.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY lerp(const Quaternion &from, const Quaternion &to, float t) noexcept {
			Quaternion quat;
			hpm_quat_lerpfv(&from.e, &to.e, t, &quat.e);
			return quat;
		}

		/**
		 * Spherical interpolation.
		 *
		 * @return normalized quaternion.
		 */
		static Quaternion HCAPIENTRY slerp(const Quaternion &from, const Quaternion &to, float t) noexcept {
			Quaternion quat;
			hpm_quat_slerpfv(&from.e, &to.e, t, &quat.e);
			return quat;
		}

		/**
		 * Create quaternion identity.
		 * @return identitiy.
		 */
		static Quaternion HCAPIENTRY identity(void) noexcept {
			Quaternion quat;
			hpm_quat_identityfv(&quat.e);
			return quat;
		}
	};
} // namespace LIBHPM

#endif
