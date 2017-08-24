#include"HCONB.h"
#include"HCVector3.h"

HCONB::HCONB(void) {
}
HCONB::HCONB(const HCONB& other) {
	*this = other;
}
HCONB::HCONB(const HCVector3& a, const HCVector3& b, const HCVector3& c) {
	this->set(a, b, c);
}

void HCONB::set(const HCVector3& a, const HCVector3& b, const HCVector3& c) {
	this->m[0] = a;
	this->m[1] = b;
	this->m[2] = c;
}

void HCONB::setU(const HCVector3& u) {
	this->m[0] = u;
}
void HCONB::setV(const HCVector3& v) {
	this->m[1] = v;
}
void HCONB::setW(const HCVector3& w) {
	this->m[2] = w;
}

HCONB& HCONB::operator=(const HCONB& onb) {
	setU(onb.u());
	setV(onb.v());
	setW(onb.w());
	return *this;
}

void HCONB::initFromU(const HCVector3& u) {
	HCVector3 n(1.0f, 0.0f, 0.0f);
	HCVector3 m(0.0f, 1.0f, 0.0f);

	//this->setU(unitVector(u));
	this->setV(cross(this->u(), n));
	if (this->v().length() < ONB_EPSILON) {
		this->setV(cross(this->u(), m));
	}
	this->setW(cross(this->u(), this->v()));
}

void HCONB::initFromV(const HCVector3& v) {
	HCVector3 n(1.0f, 0.0f, 0.0f);
	HCVector3 m(0.0f, 1.0f, 0.0f);

	//this->setV(unitVector(v));
	this->setU(cross(this->v(), n));
	if (this->u().length() < ONB_EPSILON) {
		this->setU(cross(this->v(), m));
	}
	this->setW(cross(this->u(), this->v()));
}

void HCONB::initFromW(const HCVector3& w) {
	HCVector3 n(1.0f, 0.0f, 0.0f);
	HCVector3 m(0.0f, 1.0f, 0.0f);

	//this->setW(unitVector(w));
	this->setU(cross(this->w(), n));
	if (this->u().length() < ONB_EPSILON) {
		this->setU(cross(this->w(), m));
	}
	this->setW(cross(this->w(), this->v()));
}

std::istream &operator>>(std::istream& is, HCONB& t) {
//	is >> t.u();
//	is >> t.v();
//	is >> t.w();
	return is;
}

std::ostream &operator<<(std::ostream& is, const HCONB& t) {
	is << t.u() << t.v() << t.w();
	return is;
}

bool operator==(const HCONB& o1, const HCONB& o2) {
	return (o1.u() == o2.u()) && (o1.v() == o2.v()) && (o1.w() == o2.w());
}
bool operator!=(const HCONB& o1, const HCONB& o2) {
	return (o1.u() != o2.u()) && (o1.v() != o2.v()) && (o1.w() != o2.w());
}

