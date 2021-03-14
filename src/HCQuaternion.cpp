#include"HCQuaternion.h"
#include"HCVector3.h"
#include"HCVector4.h"
using namespace LIBHPM;

Quaternion::Quaternion(const Quaternion& quaternion) {
	*this = quaternion;
}

Quaternion::Quaternion(float w, float x, float y, float z) {
	this->set(w, x, y, z);
}

Quaternion::Quaternion(float pitch, float yaw, float roll) {
	*this = createQuaternionOfAxis(pitch, yaw, roll);
}

void Quaternion::set(float w, float x, float y, float z) {
	hpm_quat_setf(&this->e, w, x, y, z);
}

float Quaternion::x(void) const {
	return hpm_quat_getxf(this->e);
}
float Quaternion::y(void) const {
	return hpm_quat_getyf(this->e);
}
float Quaternion::z(void) const {
	return hpm_quat_getzf(this->e);
}
float Quaternion::w(void) const {
	return hpm_quat_getwf(this->e);
}

void Quaternion::setW(float w) {
	hpm_quat_setwf(this->e, w);
}
void Quaternion::setX(float x) {
	hpm_quat_setxf(this->e, x);
}
void Quaternion::setY(float y) {
	hpm_quat_setyf(this->e, y);
}
void Quaternion::setZ(float z) {
	hpm_quat_setzf(this->e, z);
}

float Quaternion::operator[](int i) const {
	return this->e[i];
}
float& Quaternion::operator[](int i) {
	//return this->e[i];
}

Vector3 Quaternion::up(void) const {
	return this->getVector(Vector3::up());
}

Vector3 Quaternion::forward(void) const {
	return this->getVector(Vector3::forward());
}

Vector3 Quaternion::getVector(void) const {
	Vector3 dir;
	hpm_quat_directionfv(&this->e, (hpmvec3f*)&dir);
	return dir;
}

Vector3 Quaternion::getVector(const Vector3& vector) const {
	Vector3 vec;
	hpm_quat_get_vectorfv(&this->e, (const hpmvec3f*)&vector, (hpmvec3f*)&vec);
	return vec;
}

float Quaternion::magnitude(void) const {
	return hpm_quat_lengthfv(&this->e);
}

float Quaternion::magnitudeSquared(void) {
	return hpm_quat_lengthsqurefv(&this->e);
}

void Quaternion::makeUnitQuaternion(void) {
	hpm_quat_normalizefv(&this->e);
}

Quaternion Quaternion::normalize(void) const {
	Quaternion copy = *this;
	hpm_quat_normalizefv(&copy.e);
	return copy;
}
Quaternion Quaternion::conjugate(void) const {
	Quaternion quat = *this;
	hpm_quat_conjugatefv(&quat.e);
	return quat;
}

Quaternion Quaternion::inverse(void) const {
	Quaternion quat = *this;
	hpm_quat_inversefv(&quat.e);
	return quat;
}

Quaternion Quaternion::exponent(float exponent) const {
	Quaternion quat = *this;
	hpm_quat_powfv(&quat.e, exponent);
	return quat;
}



Quaternion& Quaternion::operator*=(const Quaternion& rh) {
	*this = *this * rh;
	return *this;
}

Quaternion& Quaternion::operator*=(const Vector3& rh) {
	*this = *this * rh;
	return *this;
}

Quaternion& Quaternion::operator*=(float rh) {
	*this = *this * rh;
	return *this;
}

Quaternion& Quaternion::operator=(const Quaternion& rh) {
	hpm_quat_copyfv(&this->e, &rh.e);
	return *this;
}

std::istream &operator>>(std::istream &is, Quaternion& t){
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

std::ostream &operator<<(std::ostream &os, const Quaternion& t){
	os << '(' << t.w() << " " << t.x() << " " << t.y() << " " << t.z()
			<< ')';
	return os;
}

namespace LIBHPM{ 
	Quaternion operator*(const Quaternion& lh, const Quaternion& rh) {
		Quaternion quat = lh;
		hpm_quat_multi_quatfv(&lh.e, &rh.e, &quat.e);
		return quat;
	}
	Quaternion operator*(const Quaternion& lh, const Vector3& rh) {
		Quaternion quat = lh;
		hpm_quat_multi_vec3fv(&lh.e, (const hpmvec3f*)&rh, (hpmvec3f*)&quat.e);
		return quat;
	}
	Quaternion operator*(const Quaternion& lh, float rh) {
		Quaternion quat = lh;
		hpm_quat_multi_scalef(&quat.e, rh);
		return quat;
	}

	Quaternion operator-(const Quaternion& lh, const Quaternion& rh) {
		Quaternion quat = lh;
		hpm_vec4_subtractionfv(&quat.e, &rh.e);
		return quat;
	}

	Quaternion operator+(const Quaternion& lh, const Quaternion& rh) {
		Quaternion quat = lh;
		hpm_vec4_addition_scalefv(&quat.e, &rh.e);
		return quat;
	}

	bool operator==(const Quaternion& v1, const Quaternion& v2){
		return (bool)hpm_vec4_eqfv(&v1.e, &v2.e);
	}
	bool operator!=(const Quaternion& v1, const Quaternion& v2){
		return (bool)hpm_vec4_neqfv(&v1.e, &v2.e);
	}
	float dot(const Quaternion& lh, const Quaternion& rh) {
		return hpm_quat_dotfv(&lh.e, &rh.e);
	}
}

float Quaternion::getPitch(void) const {
	return hpm_quat_pitchfv(&this->e);
}

float Quaternion::getYaw(void) const {
	return hpm_quat_yawfv(&this->e);
}

float Quaternion::getRoll(void) const {
	return hpm_quat_rollfv(&this->e);
}

void Quaternion::getEular(float *pitch, float *yaw, float *roll) const {
	hpm_quat_eularfv(&this->e, pitch, yaw, roll);
}

Vector3 Quaternion::getEular(void) const {

	float pitch, yaw, roll;
	hpm_quat_eularfv(&this->e, &pitch, &yaw, &roll);
	return Vector3(pitch, yaw, roll);
}



Quaternion Quaternion::lookRotation(const Vector3& target,const Vector3& pos,  const Vector3& up) {
	Quaternion quat;
	hpm_quat_lookatfv((const hpmvec3f*)&target, (const hpmvec3f*)&pos.e, (const hpmvec3f*)&up.e, &quat.e);
	return quat;
}

Quaternion Quaternion::createQuaternionOfAxis(const Vector3& axis) {
	return createQuaternionOfAxis(axis.x(), axis.y(), axis.z());
}

Quaternion Quaternion::createQuaternionOfAxis(float pitch, float yaw,
		float roll) {
	Quaternion quat;
	hpm_quat_axisf(&quat.e, pitch, yaw, roll);
	return quat;
}

Quaternion Quaternion::createFromAxisAngle(const Vector3& axis, float angle) {
	Quaternion quat;
	hpm_quat_axis_anglefv(&quat.e, (hpmvec3f*)&axis, angle);
	return quat;
}


Quaternion HCAPIENTRY Quaternion::createQuaternionOfDirection(Vector3 &direction) {
	return createQuaternionOfAxis(0, 0, 0);
}


Quaternion Quaternion::lerp(const Quaternion& from, const Quaternion& to,
		float time) {
	Quaternion quat;
	hpm_quat_lerpfv(&from.e, &to.e, time, &quat.e);
	return quat;
}

Quaternion Quaternion::slerp(const Quaternion& q1, const Quaternion& q2,
		float time) {
	Quaternion quat;
	hpm_quat_slerpfv(&q1.e, &q2.e, time, &quat.e);
	return quat;
}

Quaternion Quaternion::identity(void) {
	Quaternion quat;
	hpm_quat_identityfv(&quat.e);
	return quat;
}

