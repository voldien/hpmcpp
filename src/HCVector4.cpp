#include <HCVector4.h>

HCVector4::HCVector4(void){}
HCVector4::HCVector4(float val){
	hpm_vec4_setsf(&this->e, val);
}
HCVector4::HCVector4(float x, float y, float z, float w) {
	hpm_vec4_setf(&this->e, x, y, x, w);
}
HCVector4::HCVector4(const HCVector4& v) {
	*this = v;
}

float HCVector4::x(void) const {
	return hpm_vec4_getxf(this->e);
}
float HCVector4::y(void) const {
	return hpm_vec4_getyf(this->e);
}
float HCVector4::z(void) const {
	return hpm_vec4_getzf(this->e);
}
float HCVector4::w(void) const {
	return hpm_vec4_getwf(this->e);
}

void HCVector4::setX(float x) {
	hpm_vec4_setxf(this->e, x);
}
void HCVector4::setY(float y) {
	hpm_vec4_setyf(this->e, y);
}
void HCVector4::setZ(float z) {
	hpm_vec4_setzf(this->e, z);
}
void HCVector4::setW(float w) {
	hpm_vec4_setwf(this->e, w);
}

float HCVector4::operator[](int i) const {
	return this->e[i];
}
float& HCVector4::operator[](int i) {
	return this->e[i];
}

HCVector4 HCVector4::operator-(void) const {
	HCVector4 copy = *this;
	hpm_vec4_negatefv(&copy.e);
	return copy;
}

float HCVector4::length(void) const {
	return hpm_vec4_lengthfv(&this->e);
}

float HCVector4::squaredLength(void) const {
	return hpm_vec4_lengthsqurefv(&this->e);
}

void HCVector4::makeUnitVector(void) {
	hpm_vec4_normalizefv(&this->e);
}

HCVector4 HCVector4::normalize(void) const {
	HCVector4 vec = *this;
	hpm_vec4_normalizefv(&vec.e);
	return vec;
}

float HCVector4::minComponent(void) const{
	return hpm_vec4_min_compfv(&this->e);
}

float HCVector4::maxComponent(void) const {
	return hpm_vec4_max_compfv(&this->e);
}

float HCVector4::maxAbsComponent(void) const {
	return abs(hpm_vec4_max_compfv(&this->e));
}

float HCVector4::minAbsComponent(void) const {
	return abs(hpm_vec4_min_compfv(&this->e));
}

bool operator==(const HCVector4& v1, const HCVector4& v2) {
	return hpm_vec4_eqfv(&v1.e, &v2.e);
}

bool operator!=(const HCVector4& v1, const HCVector4& v2) {
	return hpm_vec4_neqfv(&v1.e, &v2.e);
}

HCVector4 operator*(float scaler, const HCVector4& vec) {
	HCVector4 copy = vec;
	hpm_vec4_multi_scalef(&copy.e, scaler);
	return copy;
}
HCVector4 operator*(const HCVector4&vec, float scalar) {
    HCVector4 copy = vec;
    hpm_vec4_multi_scalef(&copy.e, scalar);
    return copy;
}
HCVector4 operator/(const HCVector4&vec, float scalar) {
    HCVector4 copy = vec;
    hpm_vec4_multi_scalef(&copy.e, 1.0f / scalar);
    return copy;
}

HCVector4 operator/(const HCVector4& v1, const HCVector4& v2){
    HCVector4 copy = v1;
    HCVector4 c3 = 1.0f / v2;
    hpm_vec4_multifv(&copy.e, &c3.e);
    return copy;
}

HCVector4 operator+(const HCVector4& v1, const HCVector4& v2) {
	HCVector4 copy = v1;
	hpm_vec4_addition_scalefv(&copy.e, &v2.e);
	return copy;
}

HCVector4 operator-(float v1, const HCVector4& v2) {
	HCVector4 copy = HCVector4(v1);
	hpm_vec4_subtractionfv((hpmvec4f*)&copy, (const hpmvec4f*)&v2);
	return copy;
}
HCVector4 operator-(const HCVector4& v1, const HCVector4& v2) {
	HCVector4 copy = v1;
	hpm_vec4_subtractionfv(&copy.e, &v2.e);
	return copy;
}

float dot(const HCVector4& v1, const HCVector4& v2) {
	return hpm_vec4_dotfv(&v1.e, &v2.e);
}

HCVector4 unitVector(const HCVector4& v) {
	HCVector4 vec = v;
	hpm_vec4_normalizefv((hpmvec4f*)&vec);
	return vec;
}

HCVector4 minVec(const HCVector4& v1, const HCVector4& v2) {
	HCVector4 vec;
	hpm_vec4_minfv(&v1.e, &v2.e, &vec.e);
	return vec;
}

HCVector4 maxVec(const HCVector4& v1, const HCVector4& v2) {
	HCVector4 vec;
	hpm_vec4_maxfv(&v1.e, &v2.e, &vec.e);
	return vec;
}

HCVector4& HCVector4::operator=(const HCVector4& v2) {
	hpm_vec4_copyfv(&this->e, &v2.e);
	return *this;
}

std::istream & operator>>(std::istream &is, HCVector4& t) {
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

std::ostream & operator<<(std::ostream& os, const HCVector4& t) {
	os << '(' << t.x() << " " << t.y() << " " << t.z() << " " << t.y()
			<< ')';
	return os;
}

HCVector4 HCVector4::lerp(const HCVector4& vec1, const HCVector4& vec2, float speed){
	HCVector4 vec;
	hpm_vec4_lerpfv(&vec1.e, &vec2.e, speed, &vec.e);
	return vec;
}
HCVector4 HCVector4::slerp(const HCVector4& vec1, const HCVector4& vec2, float speed){
	HCVector4 vec;
	hpm_vec4_slerpfv(&vec1.e, &vec2.e, speed, &vec.e);
	return vec;
}

HCVector4 &HCVector4::operator+=(const HCVector4 &v2) {
	*this = *this + v2;
	return *this;
}

HCVector4 &HCVector4::operator-=(const HCVector4 &v2) {
	*this = *this - v2;
	return *this;
}

HCVector4 &HCVector4::operator/=(float scalar) {
	*this = *this / scalar;
	return *this;
}

HCVector4 &HCVector4::operator*=(float scalar) {
	*this = *this * scalar;
	return *this;
}
