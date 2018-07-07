#include <HCQuaternion.h>
#include <HCVector3.h>
#include <HCVector4.h>

HCQuaternion::HCQuaternion(void) {}
HCQuaternion::HCQuaternion(const HCQuaternion& quaternion) {
	*this = quaternion;
}

HCQuaternion::HCQuaternion(float w, float x, float y, float z) {
	this->set(w, x, y, z);
}

HCQuaternion::HCQuaternion(float pitch, float yaw, float roll) {
	*this = createQuaternionOfAxis(pitch, yaw, roll);
}

void HCQuaternion::set(float w, float x, float y, float z) {
	hpm_quat_setf(&this->e, w, x, y, z);
}

float HCQuaternion::x(void) const {
	return hpm_quat_getxf(this->e);
}
float HCQuaternion::y(void) const {
	return hpm_quat_getyf(this->e);
}
float HCQuaternion::z(void) const {
	return hpm_quat_getzf(this->e);
}
float HCQuaternion::w(void) const {
	return hpm_quat_getwf(this->e);
}

void HCQuaternion::setW(float w) {
	hpm_quat_setwf(this->e, w);
}
void HCQuaternion::setX(float x) {
	hpm_quat_setxf(this->e, x);
}
void HCQuaternion::setY(float y) {
	hpm_quat_setyf(this->e, y);
}
void HCQuaternion::setZ(float z) {
	hpm_quat_setzf(this->e, z);
}

float HCQuaternion::operator[](int i) const {
	return this->e[i];
}
float& HCQuaternion::operator[](int i) {
	return this->e[i];
}

HCVector3 HCQuaternion::up(void) const {
	return this->getVector(HCVector3::up());
}

HCVector3 HCQuaternion::forward(void) const {
	return this->getVector(HCVector3::forward());
}

HCVector3 HCQuaternion::getVector(void) const {
	HCVector3 dir;
	hpm_quat_directionfv(&this->e, (hpmvec3f*)&dir);
	return dir;
}

HCVector3 HCQuaternion::getVector(const HCVector3& vector) const {
	HCVector3 vec;
	hpm_quat_get_vectorfv(&this->e, (const hpmvec3f*)&vector, (hpmvec3f*)&vec);
	return vec;
}

float HCQuaternion::magnitude(void) const {
	return hpm_quat_lengthfv(&this->e);
}

float HCQuaternion::magnitudeSquared(void) {
	return hpm_quat_lengthsqurefv(&this->e);
}

void HCQuaternion::makeUnitQuaternion(void) {
	hpm_quat_normalizefv(&this->e);
}

HCQuaternion HCQuaternion::normalize(void) const {
	HCQuaternion copy = *this;
	hpm_quat_normalizefv(&copy.e);
	return copy;
}
HCQuaternion HCQuaternion::conjugate(void) const {
	HCQuaternion quat = *this;
	hpm_quat_conjugatefv(&quat.e);
	return quat;
}
HCQuaternion HCQuaternion::inverse(void) const {
	HCQuaternion quat = *this;
	hpm_quat_inversefv(&quat.e);
	return quat;
}

HCQuaternion operator*(const HCQuaternion& lh, const HCQuaternion& rh) {
	HCQuaternion quat = lh;
	hpm_quat_multi_quatfv(&lh.e, &rh.e, &quat.e);
	return quat;
}
HCQuaternion operator*(const HCQuaternion& lh, const HCVector3& rh) {
	HCQuaternion quat = lh;
	hpm_quat_multi_vec3fv(&lh.e, (const hpmvec3f*)&rh, (hpmvec3f*)&quat.e);
	return quat;
}
HCQuaternion operator*(const HCQuaternion& lh, float rh) {
	HCQuaternion quat = lh;
	hpm_quat_multi_scalef(&quat.e, rh);
	return quat;
}

HCQuaternion& HCQuaternion::operator*=(const HCQuaternion& rh) {
	*this = *this * rh;
	return *this;
}

HCQuaternion& HCQuaternion::operator*=(const HCVector3& rh) {
	*this = *this * rh;
	return *this;
}

HCQuaternion& HCQuaternion::operator*=(float rh) {
	*this = *this * rh;
	return *this;
}

HCQuaternion& HCQuaternion::operator=(const HCQuaternion& rh) {
	hpm_quat_copyfv(&this->e, &rh.e);
	return *this;
}

std::istream &operator>>(std::istream &is, HCQuaternion& t){
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

std::ostream &operator<<(std::ostream &os, const HCQuaternion& t){
	os << '(' << t.w() << " " << t.x() << " " << t.y() << " " << t.z()
			<< ')';
	return os;
}


HCQuaternion operator-(const HCQuaternion &lh, const HCQuaternion &rh) {
	HCQuaternion quat = lh;
	hpm_vec4_subtractionfv(&quat.e, &rh.e);
	return quat;
}

HCQuaternion operator+(const HCQuaternion &lh, const HCQuaternion &rh) {
	HCQuaternion quat = lh;
	hpm_vec4_addition_scalefv(&quat.e, &rh.e);
	return quat;
}

bool operator==(const HCQuaternion& v1, const HCQuaternion& v2){
	return (bool)hpm_vec4_eqfv(&v1.e, &v2.e);
}
bool operator!=(const HCQuaternion& v1, const HCQuaternion& v2){
	return (bool)hpm_vec4_neqfv(&v1.e, &v2.e);
}

float HCQuaternion::getPitch(void) const {
	return hpm_quat_pitchfv(&this->e);
}

float HCQuaternion::getYaw(void) const {
	return hpm_quat_yawfv(&this->e);
}

float HCQuaternion::getRoll(void) const {
	return hpm_quat_rollfv(&this->e);
}

float dot(const HCQuaternion& lh, const HCQuaternion& rh) {
	return hpm_quat_dotfv(&lh.e, &rh.e);
}

HCQuaternion HCQuaternion::lookRotation(const HCVector3& target, const HCVector3& up) {
	HCQuaternion quat;
	hpm_quat_lookatfv((const hpmvec3f*)&target, (const hpmvec3f*)&up, &quat.e);
	return quat;
}

HCQuaternion HCQuaternion::createQuaternionOfAxis(const HCVector3& axis) {
	return createQuaternionOfAxis(axis.x(), axis.y(), axis.z());
}

HCQuaternion HCQuaternion::createQuaternionOfAxis(float pitch, float yaw,
		float roll) {
	HCQuaternion quat;
	hpm_quat_axisf(&quat.e, pitch, yaw, roll);
	return quat;
}

HCQuaternion HCQuaternion::createFromAxisAngle(const HCVector3& axis, float angle) {
	HCQuaternion quat;
	hpm_quat_axis_anglefv(&quat.e, (hpmvec3f*)&axis, angle);
	return quat;
}


HCQuaternion HCAPIENTRY HCQuaternion::createQuaternionOfDirection(HCVector3 &direction) {
	return createQuaternionOfAxis(0, 0, 0);
}


HCQuaternion HCQuaternion::lerp(const HCQuaternion& from, const HCQuaternion& to,
		float time) {
	HCQuaternion quat;
	hpm_quat_lerpfv(&from.e, &to.e, time, &quat.e);
	return quat;
}

HCQuaternion HCQuaternion::slerp(const HCQuaternion& q1, const HCQuaternion& q2,
		float time) {
	HCQuaternion quat;
	hpm_quat_slerpfv(&q1.e, &q2.e, time, &quat.e);
	return quat;
}

HCQuaternion HCQuaternion::identity(void) {
	HCQuaternion quat;
	hpm_quat_identityfv(&quat.e);
	return quat;
}

