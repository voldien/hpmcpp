#include "HCONB.h"
#include "HCVector3.h"

using namespace LIBHPM;

ONB::ONB(const ONB &other) { *this = other; }

ONB::ONB(const Vector3 &a, const Vector3 &b, const Vector3 &c) { this->set(a, b, c); }

void ONB::set(const Vector3 &a, const Vector3 &b, const Vector3 &c) {
	this->m[0] = a;
	this->m[1] = b;
	this->m[2] = c;
}

void ONB::setU(const Vector3 &u) { this->m[0] = u; }

void ONB::setV(const Vector3 &v) { this->m[1] = v; }

void ONB::setW(const Vector3 &w) { this->m[2] = w; }

ONB &ONB::operator=(const ONB &onb) {
	setU(onb.u());
	setV(onb.v());
	setW(onb.w());
	return *this;
}

void ONB::initFromU(const Vector3 &u) {
	Vector3 n(1.0f, 0.0f, 0.0f);
	Vector3 m(0.0f, 1.0f, 0.0f);

	this->setU(u.normalize());
	this->setV(cross(this->u(), n));
	if (this->v().length() < HPMCPP_ONB_EPSILON) {
		this->setV(cross(this->u(), m));
	}
	this->setW(cross(this->u(), this->v()));
}

void ONB::initFromV(const Vector3 &v) {
	Vector3 n(1.0f, 0.0f, 0.0f);
	Vector3 m(0.0f, 1.0f, 0.0f);

	this->setV(v.normalize());
	this->setU(cross(this->v(), n));
	if (this->u().length() < HPMCPP_ONB_EPSILON) {
		this->setU(cross(this->v(), m));
	}
	this->setW(cross(this->u(), this->v()));
}

void ONB::initFromW(const Vector3 &w) {
	Vector3 n(1.0f, 0.0f, 0.0f);
	Vector3 m(0.0f, 1.0f, 0.0f);

	this->setW(w.normalize());
	this->setU(cross(this->w(), n));
	if (this->u().length() < HPMCPP_ONB_EPSILON) {
		this->setU(cross(this->w(), m));
	}
	this->setW(cross(this->w(), this->v()));
}

void ONB::initFromUV(const Vector3 &u, const Vector3 &v) {}

void ONB::initFromVU(const Vector3 &v, const Vector3 &u) {}

void ONB::initFromUW(const Vector3 &u, const Vector3 &w) {}

void ONB::initFromWU(const Vector3 &w, const Vector3 &u) {}

void ONB::initFromVW(const Vector3 &v, const Vector3 &w) {}

void ONB::initFromWV(const Vector3 &w, const Vector3 &v) {}

// std::istream &operator>>(std::istream &is, ONB &t) {
//     is >> t.m[0];
//     is >> t.m[1];
//     is >> t.m[2];
//     return is;
// }

std::ostream &operator<<(std::ostream &os, const ONB &t) {
	os << t.u() << t.v() << t.w();
	return os;
}

bool operator==(const ONB &o1, const ONB &o2) { return (o1.u() == o2.u()) && (o1.v() == o2.v()) && (o1.w() == o2.w()); }

bool operator!=(const ONB &o1, const ONB &o2) { return (o1.u() != o2.u()) && (o1.v() != o2.v()) && (o1.w() != o2.w()); }
