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

HCVector2& HCVector2::operator-(void) const {
	return -*this;
}

float HCVector2::length(void) const {
	return sqrtf(x() * x() + y() * y());
}
float HCVector2::squaredLength(void) const {
	return (x() * x() + y() * y());
}
void HCVector2::makeUnitVector(void) {
	*this /= this->length();
}

void HCVector2::setX(float _x) {
	this->m[0] = _x;
}
void HCVector2::setY(float _y) {
	this->m[1] = _y;
}

float HCVector2::x(void) const {
	return this->m[0];
}
float HCVector2::y(void) const{
	return this->m[1];
}

HCVector2 HCVector2::normalize(void) const {
	HCVector2 copy = *this;
	copy.makeUnitVector();
	return copy;
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
	return !(v1 == v2);
}
bool operator!=(const HCVector2& v1, const HCVector2& v2) {
	return !(v1 == v2);
}

HCVector2 operator+(const HCVector2& v1, const HCVector2& v2) {
	return HCVector2(v1.x() + v2.x(),v1.y() + v2.y());
}

HCVector2 operator-(const HCVector2& v1, const HCVector2& v2) {
	return HCVector2(v1.x() - v2.x(),v1.y() - v2.y());
}

HCVector2 operator/(const HCVector2& vec, float scalar) {
	return HCVector2(vec.x() / scalar,vec.y() / scalar);
}

HCVector2 operator*(const HCVector2& vec, float scalar) {
	return HCVector2(vec.x() * scalar,vec.y() * scalar);
}
HCVector2 operator*(float scalar, const HCVector2& vec) {
	return HCVector2(vec.x() * scalar,vec.y() * scalar);
}

HCVector2 operator*(const HCVector2& v1, const HCVector2& v2) {
	return HCVector2(v1.x() * v2.x(),v1.y() * v2.y());
}

HCVector2& HCVector2::operator=(const HCVector2& v2) {
	this->setX(v2.x());
	this->setY(v2.y());
	return *this;
}
HCVector2& HCVector2::operator+=(const HCVector2& v2) {
	*this = *this + v2;
	return *this;
}
HCVector2& HCVector2::operator-=(const HCVector2& v2) {
	*this = *this - v2;
	return *this;
}
HCVector2& HCVector2::operator/=(float scalar) {
	*this = *this / scalar;
	return *this;
}
HCVector2& HCVector2::operator*=(float scalar) {
	*this = *this * scalar;
	return *this;
}

HCVector2& HCVector2::operator*=(const HCVector2& vec2) {
	*this = *this * vec2;
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
