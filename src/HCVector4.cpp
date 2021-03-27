#include <HCVector4.h>
#include <utility>

using namespace LIBHPM;

Vector4::Vector4(void) noexcept {}
Vector4::Vector4(float val) noexcept { hpm_vec4_setsf(&this->e, val); }
Vector4::Vector4(float x, float y, float z, float w) noexcept { hpm_vec4_setf(&this->e, x, y, x, w); }
Vector4::Vector4(const Vector4 &v) noexcept { *this = v; }

float Vector4::x(void) const noexcept { return hpm_vec4_getxf(this->e); }
float Vector4::y(void) const noexcept { return hpm_vec4_getyf(this->e); }
float Vector4::z(void) const noexcept { return hpm_vec4_getzf(this->e); }
float Vector4::w(void) const noexcept { return hpm_vec4_getwf(this->e); }

void Vector4::setX(float x) noexcept { hpm_vec4_setxf(this->e, x); }
void Vector4::setY(float y) noexcept { hpm_vec4_setyf(this->e, y); }
void Vector4::setZ(float z) noexcept { hpm_vec4_setzf(this->e, z); }
void Vector4::setW(float w) noexcept { hpm_vec4_setwf(this->e, w); }

float Vector4::operator[](unsigned int i) const noexcept {
	if(i > 3)
		throw std::invalid_argument("Index");
	return this->e[i];
}
float &Vector4::operator[](unsigned int i) noexcept {
	if (i > 3)
		throw std::invalid_argument("Index");
	return this->e[i];
}

Vector4 Vector4::operator-(void) const noexcept {
	Vector4 copy = *this;
	hpm_vec4_negatefv(&copy.e);
	return copy;
}

float Vector4::length(void) const noexcept { return hpm_vec4_lengthfv(&this->e); }

float Vector4::squaredLength(void) const noexcept { return hpm_vec4_lengthsqurefv(&this->e); }

void Vector4::makeUnitVector(void) { hpm_vec4_normalizefv(&this->e); }

Vector4 Vector4::normalize(void) const {
	Vector4 vec = *this;
	hpm_vec4_normalizefv(&vec.e);
	return vec;
}

float Vector4::minComponent(void) const noexcept { return hpm_vec4_min_compfv(&this->e); }

float Vector4::maxComponent(void) const noexcept { return hpm_vec4_max_compfv(&this->e); }

float Vector4::maxAbsComponent(void) const noexcept { return abs(hpm_vec4_max_compfv(&this->e)); }

float Vector4::minAbsComponent(void) const noexcept { return abs(hpm_vec4_min_compfv(&this->e)); }
namespace LIBHPM {

	bool operator==(const Vector4 &v1, const Vector4 &v2) { return (bool)hpm_vec4_eqfv(&v1.e, &v2.e); }

	bool operator!=(const Vector4 &v1, const Vector4 &v2) { return (bool)hpm_vec4_neqfv(&v1.e, &v2.e); }

	Vector4 operator*(float scaler, const Vector4 &vec) {
		Vector4 copy = vec;
		hpm_vec4_multi_scalef(&copy.e, scaler);
		return copy;
	}
	Vector4 operator*(const Vector4 &vec, float scalar) {
		Vector4 copy = vec;
		hpm_vec4_multi_scalef(&copy.e, scalar);
		return copy;
	}
	Vector4 operator/(const Vector4 &vec, float scalar) {
		Vector4 copy = vec;
		hpm_vec4_multi_scalef(&copy.e, 1.0f / scalar);
		return copy;
	}

	Vector4 operator/(const Vector4 &v1, const Vector4 &v2) {
		Vector4 copy = v1;
		Vector4 c3 = 1.0f / v2;
		hpm_vec4_multifv(&copy.e, &c3.e);
		return copy;
	}

	Vector4 operator+(const Vector4 &v1, const Vector4 &v2) {
		Vector4 copy = v1;
		hpm_vec4_addition_scalefv(&copy.e, &v2.e);
		return copy;
	}

	Vector4 operator-(float v1, const Vector4 &v2) {
		Vector4 copy = Vector4(v1);
		hpm_vec4_subtractionfv((hpmvec4f *)&copy, (const hpmvec4f *)&v2);
		return copy;
	}
	Vector4 operator-(const Vector4 &v1, const Vector4 &v2) {
		Vector4 copy = v1;
		hpm_vec4_subtractionfv(&copy.e, &v2.e);
		return copy;
	}

	float dot(const Vector4 &v1, const Vector4 &v2) noexcept { return hpm_vec4_dotfv(&v1.e, &v2.e); }

	Vector4 unitVector(const Vector4 &v) {
		Vector4 vec = v;
		hpm_vec4_normalizefv((hpmvec4f *)&vec);
		return vec;
	}

	Vector4 minVec(const Vector4 &v1, const Vector4 &v2) noexcept {
		Vector4 vec;
		hpm_vec4_minfv(&v1.e, &v2.e, &vec.e);
		return vec;
	}

	Vector4 maxVec(const Vector4 &v1, const Vector4 &v2) noexcept {
		Vector4 vec;
		hpm_vec4_maxfv(&v1.e, &v2.e, &vec.e);
		return vec;
	}

	Vector4 &Vector4::operator=(const Vector4 &v2) noexcept {
		hpm_vec4_copyfv(&this->e, &v2.e);
		return *this;
	}

	std::istream &operator>>(std::istream &is, Vector4 &t) {
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

	std::ostream &operator<<(std::ostream &os, const Vector4 &t) {
		os << '(' << t.x() << " " << t.y() << " " << t.z() << " " << t.y() << ')';
		return os;
	}
} // namespace LIBHPM

Vector4 Vector4::lerp(const Vector4 &vec1, const Vector4 &vec2, float speed) noexcept {
	Vector4 vec;
	hpm_vec4_lerpfv(&vec1.e, &vec2.e, speed, &vec.e);
	return vec;
}
Vector4 Vector4::slerp(const Vector4 &vec1, const Vector4 &vec2, float speed) noexcept {
	Vector4 vec;
	hpm_vec4_slerpfv(&vec1.e, &vec2.e, speed, &vec.e);
	return vec;
}

Vector4 &Vector4::operator+=(const Vector4 &v2) noexcept {
	*this = *this + v2;
	return *this;
}

Vector4 &Vector4::operator-=(const Vector4 &v2) noexcept {
	*this = *this - v2;
	return *this;
}

Vector4 &Vector4::operator/=(float scalar) noexcept {
	*this = *this / scalar;
	return *this;
}

Vector4 &Vector4::operator*=(float scalar) noexcept {
	*this = *this * scalar;
	return *this;
}

Vector4 unitVector4(const Vector4 &v) {
	Vector4 copy = v;
	return v.normalize();
}
