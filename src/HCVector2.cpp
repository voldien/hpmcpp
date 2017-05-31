#include <HCVector2.h>

HCVector2::HCVector2(void) {
}
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
	float temp;
	is >> temp;
	t.setX( temp );
	is >> temp;
	t.setY(temp);
	return is;
}

std::ostream& operator<<(std::ostream& os, const HCVector2& t) {
	os << '(' << t.x() << " " << t.y() << ')';
	return os;
}

