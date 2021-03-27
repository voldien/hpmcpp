#include "HCVector2.h"

using namespace LIBHPM;

Vector2::Vector2(float val) {
	this->setX(val);
	this->setY(val);
}

Vector2::Vector2(float m0, float m1) {
	this->setX(m0);
	this->setY(m1);
}

Vector2::Vector2(const Vector2 &v) { *this = v; }

Vector2 &Vector2::operator-(void) const noexcept { return -*this; }

float Vector2::operator[](int i) const noexcept { return this->m[i]; }
float &Vector2::operator[](int i) noexcept {
	// return this->m[i];
}

float Vector2::length(void) const noexcept { return sqrtf(x() * x() + y() * y()); }
float Vector2::squaredLength(void) const noexcept { return (x() * x() + y() * y()); }
void Vector2::makeUnitVector(void) { *this /= this->length(); }

void Vector2::setX(float _x) noexcept { this->m[0] = _x; }
void Vector2::setY(float _y) noexcept { this->m[1] = _y; }

float Vector2::x(void) const noexcept { return this->m[0]; }
float Vector2::y(void) const noexcept { return this->m[1]; }

Vector2 Vector2::normalize(void) const {
	Vector2 copy = *this;
	copy.makeUnitVector();
	return copy;
}

float Vector2::maxComponent(void) const noexcept { return 0; }

float Vector2::maxAbsComponent(void) const noexcept { return 0; }

float Vector2::minAbsComponent(void) const noexcept { return 0; }

int Vector2::indexOfMinComponent(void) const noexcept { return 0; }

int Vector2::indexOfMinAbsComponent(void) const noexcept { return 0; }

namespace LIBHPM {
	bool operator==(const Vector2 &v1, const Vector2 &v2) { return !(v1 == v2); }
	bool operator!=(const Vector2 &v1, const Vector2 &v2) { return !(v1 == v2); }

	Vector2 operator+(const Vector2 &v1, const Vector2 &v2) { return Vector2(v1.x() + v2.x(), v1.y() + v2.y()); }

	Vector2 operator-(const Vector2 &v1, const Vector2 &v2) { return Vector2(v1.x() - v2.x(), v1.y() - v2.y()); }

	Vector2 operator/(const Vector2 &vec, float scalar) { return Vector2(vec.x() / scalar, vec.y() / scalar); }

	Vector2 operator*(const Vector2 &vec, float scalar) { return Vector2(vec.x() * scalar, vec.y() * scalar); }
	Vector2 operator*(float scalar, const Vector2 &vec) { return Vector2(vec.x() * scalar, vec.y() * scalar); }

	Vector2 operator*(const Vector2 &v1, const Vector2 &v2) { return Vector2(v1.x() * v2.x(), v1.y() * v2.y()); }
} // namespace LIBHPM

Vector2 &Vector2::operator=(const Vector2 &v2) {
	this->setX(v2.x());
	this->setY(v2.y());
	return *this;
}
Vector2 &Vector2::operator+=(const Vector2 &v2) {
	*this = *this + v2;
	return *this;
}
Vector2 &Vector2::operator-=(const Vector2 &v2) {
	*this = *this - v2;
	return *this;
}
Vector2 &Vector2::operator/=(float scalar) {
	*this = *this / scalar;
	return *this;
}
Vector2 &Vector2::operator*=(float scalar) {
	*this = *this * scalar;
	return *this;
}

Vector2 &Vector2::operator*=(const Vector2 &vec2) {
	*this = *this * vec2;
	return *this;
}

std::istream &operator>>(std::istream &is, Vector2 &t) {

	float tmp;

	is >> tmp;
	t.setX(tmp);
	is >> tmp;
	t.setY(tmp);

	return is;
}
std::ostream &operator<<(std::ostream &os, const Vector2 &t) {
	os << '(' << t.x() << " " << t.y() << ')';
	return os;
}
