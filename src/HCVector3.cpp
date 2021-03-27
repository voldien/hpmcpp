#include "HCVector3.h"

using namespace LIBHPM;

Vector3::Vector3(float val) noexcept { hpm_vec4_setf(&this->e, val, val, val, val); }
Vector3::Vector3(float e0, float e1, float e2) noexcept { hpm_vec4_setf(&this->e, e0, e1, e2, 0); }
Vector3::Vector3(const Vector3 &v) noexcept { *this = v; }

float Vector3::x(void) const noexcept { return hpm_vec4_getxf(this->e); }
float Vector3::y(void) const noexcept { return hpm_vec4_getyf(this->e); }
float Vector3::z(void) const noexcept { return hpm_vec4_getzf(this->e); }

void Vector3::setX(float _x) noexcept { hpm_vec4_setxf(this->e, _x); }
void Vector3::setY(float _y) noexcept { hpm_vec4_setyf(this->e, _y); }
void Vector3::setZ(float _z) noexcept { hpm_vec4_setzf(this->e, _z); }

const Vector3 &Vector3::operator+(void) const noexcept { return *this; }

Vector3 Vector3::operator-(void) const noexcept {
	Vector3 copy = *this;
	hpm_vec4_negatefv(&copy.e);
	return copy;
}

float Vector3::operator[](int i) const noexcept { return this->e[i]; }
float &Vector3::operator[](int i) noexcept {
	// return this->e[i];
}

float Vector3::length(void) const noexcept { return hpm_vec3_lengthfv(&this->e); }
float Vector3::squaredLength(void) const noexcept { return hpm_vec3_lengthsquarefv(&this->e); }
void Vector3::makeUnitVector(void) { *this = *this / (*this).length(); }
float Vector3::minComponent(void) const noexcept { return hpm_vec4_min_compfv(&this->e); }

Vector3 Vector3::normalize(void) const {
	float l = 1.0f / this->length();
	return (*this * l);
}

float Vector3::maxComponent(void) const noexcept { return hpm_vec4_max_compfv(&this->e); }

float Vector3::maxAbsComponent(void) const noexcept { return fabs(hpm_vec4_max_compfv(&this->e)); }

float Vector3::minAbsComponent(void) const noexcept { return fabs(hpm_vec4_min_compfv(&this->e)); }

namespace LIBHPM {

	bool operator==(const Vector3 &v1, const Vector3 &v2) noexcept {
		if (v1.e[0] != v2.e[0])
			return false;
		if (v1.e[1] != v2.e[1])
			return false;
		if (v1.e[2] != v2.e[2])
			return false;
		return true;
	}

	bool operator!=(const Vector3 &v1, const Vector3 &v2) noexcept { return !(v1 == v2); }

	Vector3 operator*(float scalar, const Vector3 &vec) noexcept {
		return Vector3(vec.e[0] * scalar, vec.e[1] * scalar, vec.e[2] * scalar);
	}

	Vector3 operator*(const Vector3 &vec1, const Vector3 &vec2) noexcept {
		return Vector3(vec1.e[0] * vec2.e[0], vec1.e[1] * vec2.e[1], vec1.e[2] * vec2.e[2]);
	}

	Vector3 operator+(const Vector3 &v1, const Vector3 &v2) noexcept {
		return Vector3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
	}

	Vector3 operator-(float v1, const Vector3 &v2) noexcept { return Vector3(v1 - v2.x(), v1 - v2.y(), v1 - v2.z()); }
	Vector3 operator-(const Vector3 &v1, const Vector3 &v2) noexcept {
		return Vector3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
	}

	float dot(const Vector3 &v1, const Vector3 &v2) noexcept { return hpm_vec3_dotfv(&v1.e, &v2.e); }

	Vector3 cross(const Vector3 &v1, const Vector3 &v2) noexcept {
		Vector3 cr;
		hpm_vec3_crossproductfv(&v1.e, &v2.e, &cr.e);
		return cr;
	}

	Vector3 unitVector(const Vector3 &v) {
		Vector3 vec = v;
		hpm_vec3_normalizefv((hpmvec3f *)&vec);
		return vec;
	}

	Vector3 minVec(const Vector3 &v1, const Vector3 &v2) noexcept {
		Vector3 vec(v1);
		if (v2.x() < v1.x())
			vec.setX(v2.x());
		if (v2.y() < v1.y())
			vec.setY(v2.y());
		if (v2.z() < v1.z())
			vec.setZ(v2.z());
		return vec;
	}

	Vector3 maxVec(const Vector3 &v1, const Vector3 &v2) noexcept {
		Vector3 vec(v1);
		if (v2.x() > v1.x())
			vec.setX(v2.x());
		if (v2.y() > v1.y())
			vec.setY(v2.y());
		if (v2.z() > v1.z())
			vec.setZ(v2.z());
		return vec;
	}

	Vector3 reflection(const Vector3 &vector, const Vector3 &normal) noexcept {
		Vector3 vec;
		hpm_vec3_reflectfv(&vector.e, &normal.e, &vec.e);
		return vec;
	}

	Vector3 refraction(const Vector3 &v1, const Vector3 &normal, float refraction) noexcept { return Vector3(); }

	Vector3 tangent(const Vector3 &normal) noexcept {
		Vector3 tangent = cross(normal, Vector3::forward());

		if (tangent.length() == 0.0f) { // if magnitude == is equal to 0
			tangent = cross(normal, Vector3::up());
		}
		return tangent;
	}

	Vector3 biTangent(const Vector3 &normal, const Vector3 &tangent) noexcept { return cross(normal, tangent); }

	Vector3 biNormal(const Vector3 &normal, const Vector3 &tangent) noexcept { return cross(tangent, normal); }

	Vector3 operator*(const Vector3 &vec, float scalar) noexcept {
		return Vector3(vec.x() * scalar, vec.y() * scalar, vec.z() * scalar);
	}

	Vector3 operator/(const Vector3 &vec, float scalar) noexcept {
		return Vector3(vec.x() / scalar, vec.y() / scalar, vec.z() / scalar);
	}
} // namespace LIBHPM

Vector3 &Vector3::operator=(const Vector3 &v2) noexcept {
	hpm_vec4_copyfv(&this->e, &v2.e);
	return *this;
}

Vector3 &Vector3::operator+=(const Vector3 &vec2) noexcept {
	*this = *this + vec2;
	return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &vec2) noexcept {
	*this = *this - vec2;
	return *this;
}

Vector3 &Vector3::operator*=(float scalar) noexcept {
	*this = *this * scalar;
	return *this;
}

Vector3 &Vector3::operator/=(float scalar) noexcept {
	*this = *this / scalar;
	return *this;
}

namespace LIBHPM {
	float tripleProduct(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3) noexcept {
		return hpm_vec3_tripleProductfv(&v1.e, &v2.e, &v3.e);
	}
} // namespace LIBHPM

Vector3 Vector3::lerp(const Vector3 &vec1, const Vector3 &vec2, float t) noexcept { return (vec1 + (vec2 - vec1) * t); }

Vector3 Vector3::slerp(const Vector3 &vec1, const Vector3 &vec2, float t) noexcept { return Vector3(); }

namespace LIBHPM {

	std::istream &operator>>(std::istream &is, Vector3 &t) {
		float temp;
		is >> temp;
		t.setX(temp);
		is >> temp;
		t.setY(temp);
		is >> temp;
		t.setZ(temp);
		return is;
	}

	std::ostream &operator<<(std::ostream &os, const Vector3 &t) {
		os << '(' << t.x() << " " << t.y() << " " << t.z() << ')';
		return os;
	}

	Vector3 unitVector3(const Vector3 &v) {
		Vector3 unit = v;
		hpm_vec4_setwf(unit.e, 0.0f);
		hpm_vec4_normalizefv(&unit.e);
		return unit;
	}
} // namespace LIBHPM