#include <HCVector3.h>

HCVector3::HCVector3(void) {}

HCVector3::HCVector3(float val){
	this->setX(val);
	this->setY(val);
	this->setZ(val);
}
HCVector3::HCVector3(float e0, float e1, float e2) {
	this->setX(e0);
	this->setY(e1);
	this->setZ(e2);
}
HCVector3::HCVector3(const HCVector3& v){
	*this = v;
}

HCVector3 HCVector3::operator-(void) const {
	HCVector3 copy = *this;
	hpm_vec4_negatefv(&copy.e);
	return copy;
}

float HCVector3::length(void) const {
	return hpm_vec3_lengthfv(&this->e);
}
float HCVector3::squaredLength(void) const {
	return hpm_vec3_lengthsquarefv(&this->e);
}
void HCVector3::makeUnitVector(void) {
	*this = *this / (*this).length();
}
float HCVector3::minComponent(void) const {
	float temp = e[0];
	if (e[1] < temp)
		temp = e[1];
	if (e[2] < temp)
		temp = e[2];

	return temp;

}

HCVector3 HCVector3::normalize(void) const {
	float l = 1.0f / this->length();
	return (*this * l);
}

float HCVector3::maxComponent(void) const {
	return 0;
}

float HCVector3::maxAbsComponent(void) const {
	return 0;
}

float HCVector3::minAbsComponent(void) const {
	return 0;
}

int HCVector3::indexOfMinComponent(void) const {
	return 0;
}

int HCVector3::indexOfMinAbsComponent(void) const {
	return 0;
}

bool operator==(const HCVector3& v1, const HCVector3& v2) {
	if (v1.e[0] != v2.e[0])
		return false;
	if (v1.e[1] != v2.e[1])
		return false;
	if (v1.e[2] != v2.e[2])
		return false;
	return true;
}

bool operator!=(const HCVector3& v1, const HCVector3& v2) {
	return !(v1 == v2);
}

HCVector3 operator*(float scalar, const HCVector3& vec) {
	return HCVector3(vec.e[0] * scalar, vec.e[1] * scalar, vec.e[2] * scalar);
}

HCVector3 operator*(const HCVector3& vec1, const HCVector3& vec2) {
	return HCVector3(vec1.e[0] * vec2.e[0], vec1.e[1] * vec2.e[1],
			vec1.e[2] * vec2.e[2]);
}

HCVector3 operator+(const HCVector3& v1, const HCVector3& v2) {
	return HCVector3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

HCVector3 operator-(float v1, const HCVector3& v2) {
	return HCVector3(v1 - v2.x(), v1 - v2.y(), v1 - v2.z());
}
HCVector3 operator-(const HCVector3& v1, const HCVector3& v2) {
	return HCVector3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

float dot(const HCVector3& v1, const HCVector3& v2) {
	return hpm_vec3_dotfv(&v1.e, &v2.e);
}

HCVector3 cross(const HCVector3& v1, const HCVector3& v2) {
	HCVector3 cr;
	hpm_vec3_crossproductfv(&v1.e, &v2.e, &cr.e);
	return cr;
}

HCVector3 unitVector(const HCVector3& v) {
	float length = v.length();
	return v / length;
}

HCVector3 minVec(const HCVector3& v1, const HCVector3& v2) {
	HCVector3 vec(v1);
	if (v2.x() < v1.x())
		vec.setX(v2.x());
	if (v2.y() < v1.y())
		vec.setY(v2.y());
	if (v2.z() < v1.z())
		vec.setZ(v2.z());
	return vec;
}

HCVector3 maxVec(const HCVector3& v1, const HCVector3& v2) {
	HCVector3 vec(v1);
	if (v2.x() > v1.x())
		vec.setX(v2.x());
	if (v2.y() > v1.y())
		vec.setY(v2.y());
	if (v2.z() > v1.z())
		vec.setZ(v2.z());
	return vec;
}

HCVector3 reflection(const HCVector3& v1, const HCVector3& normal) {
	return 2.0f * dot(v1, normal) * normal - v1;
}

HCVector3 refraction(const HCVector3& v1, const HCVector3& normal, float refraction) {
	return HCVector3();
}

HCVector3 tangent(const HCVector3& normal) {
	HCVector3 tangent = cross(normal, HCVector3::forward());

	if (tangent.length() == 0.0f) {	// if magnitude == is equal to 0
		tangent = cross(normal, HCVector3::up());
	}
	return tangent;

	HCVector3 t1 = cross(normal, HCVector3::forward());
	HCVector3 t2 = cross(normal, HCVector3::up());

	if (t1.length() > t2.length()) {
		return t1;
	} else {
		return t2;
	}
}


HCVector3 biTangent(const HCVector3& normal, const HCVector3& tangent) {
	return cross(normal, tangent);
}

HCVector3 biNormal(const HCVector3& normal, const HCVector3& tangent) {
	return cross(tangent, normal);
}

HCVector3 operator*(const HCVector3&vec, float scalar) {
	return HCVector3(vec.x() * scalar, vec.y() * scalar, vec.z() * scalar);
}

HCVector3 operator/(const HCVector3&vec, float scalar) {
	return HCVector3(vec.x() / scalar, vec.y() / scalar, vec.z() / scalar);
}

HCVector3& HCVector3::operator=(const HCVector3& v2) {
	hpm_vec4_copyfv(&this->e, &v2.e);
	return *this;
}

HCVector3& HCVector3::operator+=(const HCVector3& vec2) {
	*this = *this + vec2;
	return *this;
}

HCVector3& HCVector3::operator-=(const HCVector3& vec2) {
	*this = *this - vec2;
	return *this;
}

HCVector3& HCVector3::operator*=(float scalar) {
	*this = *this * scalar;
	return *this;
}


float tripleProduct(const HCVector3& v1, const HCVector3& v2, const HCVector3& v3) {
	return hpm_vec3_tripleProductfv(&v1.e, &v2.e, &v3.e);
}

HCVector3 HCVector3::lerp(const HCVector3& vec1, const HCVector3& vec2, float t) {
	return (vec1 + (vec2 - vec1) * t);
}

HCVector3 HCVector3::slerp(const HCVector3& vec1, const HCVector3& vec2, float t) {
	return HCVector3();
}

std::istream & operator>>(std::istream &is, HCVector3 &t) {
	float temp;
	is >> temp;
	t.setX(temp);
	is >> temp;
	t.setY(temp);
	is >> temp;
	t.setZ(temp);
	return is;
}

std::ostream & operator<<(std::ostream& os, const HCVector3&t) {
	os << '(' << t.x() << " " << t.y() << " " << t.z() << ')';
	return os;
}


