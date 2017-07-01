#include <HCVector2.h>

HCVector2::HCVector2(void) {}
HCVector2::HCVector2(float val) {
	this->setX(val);
	this->setY(val);
}

HCVector2::HCVector2(float m0, float m1) {
	this->setX(m0);
	this->setY(m1);
}

HCVector2::HCVector2(const HCVector2& v) {
	*this = v;
}

float HCVector2::length(void) const {
	//return sqrtf(m[0] * m[0] + m[1] * m[1]);
	return 0;
}
float HCVector2::squaredLength(void) const {
	//return (m[0] * m[0] + m[1] * m[1]);
	return 0;
}
void HCVector2::makeUnitVector(void) {
	//*this /= this->length();
}

void HCVector2::setX(float _x) {
	hpm_vec4_setxf(this->m, _x);
}
void HCVector2::setY(float _y) {
	hpm_vec4_setyf(this->m, _y);
}

float HCVector2::x(void) const {
	return hpm_vec4_getxf(this->m);
}
float HCVector2::y(void) const{
	return hpm_vec4_getyf(this->m);
}

HCVector2 HCVector2::normalize(void) const {
	//return HCVector2(m[0], m[1]) / this->length();
	return HCVector2();
}

float HCVector2::maxComponent(void) const {
	return 0;
}

float HCVector2::maxAbsComponent(void) const {
	return 0;
}

float HCVector2::minAbsComponent(void) const {
	return 0;
}

int HCVector2::indexOfMinComponent(void) const {
	return 0;
}

int HCVector2::indexOfMinAbsComponent(void) const {
	return 0;
}

bool operator==(const HCVector2& v1, const HCVector2& v2) {
	return false;
}
bool operator!=(const HCVector2& v1, const HCVector2& v2) {
	return !(v1 == v2);
}

HCVector2 operator+(const HCVector2& v1, const HCVector2& v2) {
	return HCVector2();
}

HCVector2 operator-(const HCVector2& v1, const HCVector2& v2) {
	return HCVector2();
}

HCVector2 operator/(const HCVector2& vec, float scalar) {
	return HCVector2();
}

HCVector2 operator*(const HCVector2& vec, float scalar) {
	return HCVector2();
}
HCVector2 operator*(float scalar, const HCVector2& vec) {
	return HCVector2();
}

HCVector2 operator*(const HCVector2& vec1, const HCVector2& vec2) {
	return HCVector2();
}

HCVector2& HCVector2::operator=(const HCVector2& v2) {

	return *this;
}
HCVector2& HCVector2::operator+=(const HCVector2& v2) {
	*this += v2;
	return *this;
}
HCVector2& HCVector2::operator-=(const HCVector2& v2) {
	*this -= v2;
	return *this;
}
HCVector2& HCVector2::operator/=(float scalar) {
	*this /= scalar;
	return *this;
}
HCVector2& HCVector2::operator*=(float scalar) {
	*this *= scalar;
	return *this;
}

HCVector2& HCVector2::operator*=(const HCVector2& vec2) {
	*this *= vec2;
	return *this;
}

std::istream& operator>>(std::istream &is, HCVector2& t) {
	float tmp;

	is >> tmp;
	t.setX(tmp);
	is >> tmp;
	t.setY(tmp);

	return is;
}

std::ostream& operator<<(std::ostream& os, const HCVector2& t) {
	os << '(' << t.x() << " " << t.y() << ')';
	return os;
}

