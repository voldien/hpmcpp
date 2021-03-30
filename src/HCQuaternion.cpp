// #include "HCQuaternion.h"
// #include "HCVector3.h"
// #include "HCVector4.h"
// using namespace LIBHPM;

// Quaternion::Quaternion(const Quaternion &quaternion) noexcept { *this = quaternion; }

// Quaternion::Quaternion(float w, float x, float y, float z) noexcept { this->set(w, x, y, z); }

// Quaternion::Quaternion(float pitch, float yaw, float roll) noexcept {
// 	*this = createQuaternionOfAxis(pitch, yaw, roll);
// }

// void Quaternion::set(float w, float x, float y, float z) noexcept { hpm_quat_setf(&this->e, w, x, y, z); }

// float Quaternion::x(void) const noexcept { return hpm_quat_getxf(this->e); }
// float Quaternion::y(void) const noexcept { return hpm_quat_getyf(this->e); }
// float Quaternion::z(void) const noexcept { return hpm_quat_getzf(this->e); }
// float Quaternion::w(void) const noexcept { return hpm_quat_getwf(this->e); }

// void Quaternion::setW(float w) noexcept { hpm_quat_setwf(this->e, w); }
// void Quaternion::setX(float x) noexcept { hpm_quat_setxf(this->e, x); }
// void Quaternion::setY(float y) noexcept { hpm_quat_setyf(this->e, y); }
// void Quaternion::setZ(float z) noexcept { hpm_quat_setzf(this->e, z); }

// float Quaternion::operator[](int i) const { return this->e[i]; }
// float &Quaternion::operator[](int i) {
// 	// return this->e[i];
// }

// Vector3 Quaternion::up(void) const noexcept { return this->getVector(Vector3::up()); }

// Vector3 Quaternion::forward(void) const noexcept { return this->getVector(Vector3::forward()); }

// Vector3 Quaternion::getVector(void) const noexcept {
// 	Vector3 dir;
// 	hpm_quat_directionfv(&this->e, (hpmvec3f *)&dir);
// 	return dir;
// }

// Vector3 Quaternion::getVector(const Vector3 &vector) const noexcept {
// 	Vector3 vec;
// 	hpm_quat_get_vectorfv(&this->e, (const hpmvec3f *)&vector, (hpmvec3f *)&vec);
// 	return vec;
// }

// float Quaternion::magnitude(void) const noexcept { return hpm_quat_lengthfv(&this->e); }

// float Quaternion::magnitudeSquared(void) const noexcept { return hpm_quat_lengthsqurefv(&this->e); }

// void Quaternion::makeUnitQuaternion(void) { hpm_quat_normalizefv(&this->e); }

// Quaternion Quaternion::normalize(void) const {
// 	Quaternion copy = *this;
// 	hpm_quat_normalizefv(&copy.e);
// 	return copy;
// }
// Quaternion Quaternion::conjugate(void) const noexcept {
// 	Quaternion quat = *this;
// 	hpm_quat_conjugatefv(&quat.e);
// 	return quat;
// }

// Quaternion Quaternion::inverse(void) const noexcept {
// 	Quaternion quat = *this;
// 	hpm_quat_inversefv(&quat.e);
// 	return quat;
// }

// Quaternion Quaternion::exponent(float exponent) const noexcept {
// 	Quaternion quat = *this;
// 	hpm_quat_powfv(&quat.e, exponent);
// 	return quat;
// }

// Quaternion &Quaternion::operator*=(const Quaternion &rh) noexcept {
// 	*this = *this * rh;
// 	return *this;
// }

// Quaternion &Quaternion::operator*=(const Vector3 &rh) noexcept {
// 	*this = *this * rh;
// 	return *this;
// }

// Quaternion &Quaternion::operator*=(float rh) noexcept {
// 	*this = *this * rh;
// 	return *this;
// }

// Quaternion &Quaternion::operator=(const Quaternion &rh) noexcept {
// 	hpm_quat_copyfv(&this->e, &rh.e);
// 	return *this;
// }

// std::istream &operator>>(std::istream &is, Quaternion &t) {
// 	float temp;
// 	is >> temp;
// 	t.setX(temp);
// 	is >> temp;
// 	t.setY(temp);
// 	is >> temp;
// 	t.setZ(temp);
// 	is >> temp;
// 	t.setW(temp);
// 	return is;
// }

// std::ostream &operator<<(std::ostream &os, const Quaternion &t) {
// 	os << '(' << t.w() << " " << t.x() << " " << t.y() << " " << t.z() << ')';
// 	return os;
// }

// namespace LIBHPM {
// 	Quaternion operator*(const Quaternion &lh, const Quaternion &rh) noexcept {
// 		Quaternion quat = lh;
// 		hpm_quat_multi_quatfv(&lh.e, &rh.e, &quat.e);
// 		return quat;
// 	}
// 	Quaternion operator*(const Quaternion &lh, const Vector3 &rh) noexcept {
// 		Quaternion quat = lh;
// 		hpm_quat_multi_vec3fv(&lh.e, (const hpmvec3f *)&rh, (hpmvec3f *)&quat.e);
// 		return quat;
// 	}
// 	Quaternion operator*(const Quaternion &lh, float rh) noexcept {
// 		Quaternion quat = lh;
// 		hpm_quat_multi_scalef(&quat.e, rh);
// 		return quat;
// 	}

// 	Quaternion operator-(const Quaternion &lh, const Quaternion &rh) noexcept {
// 		Quaternion quat = lh;
// 		hpm_vec4_subtractionfv(&quat.e, &rh.e);
// 		return quat;
// 	}

// 	Quaternion operator+(const Quaternion &lh, const Quaternion &rh) noexcept {
// 		Quaternion quat = lh;
// 		hpm_vec4_addition_scalefv(&quat.e, &rh.e);
// 		return quat;
// 	}

// 	bool operator==(const Quaternion &v1, const Quaternion &v2) noexcept { return (bool)hpm_vec4_eqfv(&v1.e, &v2.e); }
// 	bool operator!=(const Quaternion &v1, const Quaternion &v2) noexcept { return (bool)hpm_vec4_neqfv(&v1.e, &v2.e); }
// 	float dot(const Quaternion &lh, const Quaternion &rh) noexcept { return hpm_quat_dotfv(&lh.e, &rh.e); }
// } // namespace LIBHPM

// float Quaternion::getPitch(void) const noexcept { return hpm_quat_pitchfv(&this->e); }

// float Quaternion::getYaw(void) const noexcept { return hpm_quat_yawfv(&this->e); }

// float Quaternion::getRoll(void) const noexcept { return hpm_quat_rollfv(&this->e); }

// void Quaternion::getEular(float *pitch, float *yaw, float *roll) const noexcept {
// 	hpm_quat_eularfv(&this->e, pitch, yaw, roll);
// }

// Vector3 Quaternion::getEular(void) const noexcept {

// 	float pitch, yaw, roll;
// 	hpm_quat_eularfv(&this->e, &pitch, &yaw, &roll);
// 	return Vector3(pitch, yaw, roll);
// }

// Quaternion Quaternion::lookRotation(const Vector3 &target, const Vector3 &pos, const Vector3 &up) noexcept {
// 	Quaternion quat;
// 	hpm_quat_lookatfv((const hpmvec3f *)&target, (const hpmvec3f *)&pos.e, (const hpmvec3f *)&up.e, &quat.e);
// 	return quat;
// }

// Quaternion Quaternion::createQuaternionOfAxis(const Vector3 &axis) noexcept {
// 	return createQuaternionOfAxis(axis.x(), axis.y(), axis.z());
// }

// Quaternion Quaternion::createQuaternionOfAxis(float pitch, float yaw, float roll) noexcept {
// 	Quaternion quat;
// 	hpm_quat_axisf(&quat.e, pitch, yaw, roll);
// 	return quat;
// }

// Quaternion Quaternion::createFromAxisAngle(const Vector3 &axis, float angle) noexcept {
// 	Quaternion quat;
// 	hpm_quat_axis_anglefv(&quat.e, (hpmvec3f *)&axis, angle);
// 	return quat;
// }

// Quaternion HCAPIENTRY Quaternion::createQuaternionOfDirection(Vector3 &direction) noexcept {
// 	return createQuaternionOfAxis(0, 0, 0);
// }

// Quaternion Quaternion::lerp(const Quaternion &from, const Quaternion &to, float time) noexcept {
// 	Quaternion quat;
// 	hpm_quat_lerpfv(&from.e, &to.e, time, &quat.e);
// 	return quat;
// }

// Quaternion Quaternion::slerp(const Quaternion &q1, const Quaternion &q2, float time) noexcept {
// 	Quaternion quat;
// 	hpm_quat_slerpfv(&q1.e, &q2.e, time, &quat.e);
// 	return quat;
// }

// Quaternion Quaternion::identity(void) noexcept {
// 	Quaternion quat;
// 	hpm_quat_identityfv(&quat.e);
// 	return quat;
// }
