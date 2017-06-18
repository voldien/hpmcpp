#include <HCMatrix4x4.h>
#include <HCQuaternion.h>
#include <HCVector3.h>
#include <HCVector4.h>
#include<iostream>

HCMatrix4x4::HCMatrix4x4(void) {

}
HCMatrix4x4::HCMatrix4x4(const HCMatrix4x4& other) {
	*this = other;
}

bool HCMatrix4x4::isIdentity(void){
	return *this == HCMatrix4x4::identity();
}

float HCMatrix4x4::determinant(void) const {
	return hpm_mat4x4_determinantfv(this->e);
}

HCMatrix4x4 HCMatrix4x4::inverse(void) const {
	HCMatrix4x4 res;
	hpm_mat4x4_inversefv(this->e, res.e);
	return res;
}

HCMatrix4x4 HCMatrix4x4::transpose(void) const {
	HCMatrix4x4 mat = *this;
	hpm_mat4x4_transposefv(mat.e);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::operator*(const HCMatrix4x4& rh) const {
	HCMatrix4x4 mat;
	hpm_mat4x4_multiply_mat4x4fv(this->e, rh.e,mat.e);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::operator+(const HCMatrix4x4& rh) const {
	HCMatrix4x4 mat;
	hpm_mat4x4_additition_mat4x4fv(this->e, rh.e, mat.e);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::operator-(const HCMatrix4x4& rh) const {
	HCMatrix4x4 mat;
	hpm_mat4x4_subraction_mat4x4fv(this->e, rh.e, mat.e);
	return mat;
}

HCVector4 HCMatrix4x4::operator*(const HCVector4& rh) const {
	HCVector4 vm;
	hpm_mat4x4_multiply_mat1x4fv(this->e, (const hpmvec4f*)&rh, (hpmvec4f*)&vm);
	return vm;
}

HCMatrix4x4& HCMatrix4x4::operator=(const HCMatrix4x4& rh) {
	hpm_mat4x4_copyfv(this->e, rh.e);
	return *this;
}

HCMatrix4x4& HCMatrix4x4::operator+=(const HCMatrix4x4& rh) {
	*this = *this + rh;
	return *this;
}

HCMatrix4x4& HCMatrix4x4::operator-=(const HCMatrix4x4& rh) {
	*this = *this - rh;
	return *this;
}

HCMatrix4x4& HCMatrix4x4::operator*=(const HCMatrix4x4& rh) {
	*this = *this * rh;
	return *this;
}

bool HCMatrix4x4::operator==(const HCMatrix4x4& rh){
	return (bool)hpm_mat4_eqfv(this->e, rh.e);
}
bool HCMatrix4x4::operator!=(const HCMatrix4x4& rh){
	return (bool)hpm_mat4_neqfv(this->e, rh.e);
}

std::istream &operator>>(std::istream &is, HCMatrix4x4& t){
	is >> *((HCVector4*)t[0]);
	is >> *((HCVector4*)t[1]);
	is >> *((HCVector4*)t[2]);
	is >> *((HCVector4*)t[3]);
	return is;
}
std::ostream &operator<<(std::ostream &os, const HCMatrix4x4& t){

	os << '|' << *((HCVector4*)t[0]) << "|\n";
	os << '|' << *((HCVector4*)t[1]) << "|\n";
	os << '|' << *((HCVector4*)t[2]) << "|\n";
	os << '|' << *((HCVector4*)t[3]) << "|\n";
	return os;
}

HCMatrix4x4 HCMatrix4x4::translate(float x, float y, float z) {
	HCMatrix4x4 mat;
	hpm_mat4x4_translationf(mat.e, x, y, z);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::translate(const HCVector3& translation) {
	HCMatrix4x4 mat;
	hpm_mat4x4_translationfv(mat.e, (hpmvec3f*)&translation);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::rotate(float angle, const HCVector3& axis) {
	HCMatrix4x4 mat;
	hpm_mat4x4_rotationfv(mat.e, angle, (hpmvec3f*)&axis);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::rotate(const HCQuaternion& quat) {
	HCMatrix4x4 mat;
	hpm_mat4x4_rotationQf(mat.e, &quat.e);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::scale(float x, float y, float z) {
	HCMatrix4x4 mat;
	hpm_mat4x4_scalef(mat.e, x, y, z);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::scale(const HCVector3& scale) {
	HCMatrix4x4 mat;
	hpm_mat4x4_scalefv(mat.e, (const hpmvec3f*)&scale);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::perspective(float fov, float aspect, float near,
		float far) {
	HCMatrix4x4 mat;
	hpm_mat4x4_projfv(mat.e, fov, aspect, near, far);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::orth(float left, float right, float bottom, float top,
		float near, float far) {
	HCMatrix4x4 mat;
	hpm_mat4x4_orthfv(mat.e, left, right, bottom, top, near, far);
	return mat;
}

HCMatrix4x4 HCMatrix4x4::biasMatrix(void) {
	/*
	return HCMatrix4x4(0.5f, 0.0, 0.0, 0.0, 0.0, 0.5f, 0.0, 0.0, 0.0, 0.0f,
			0.5f, 0.0, 0.5f, 0.5f, 0.5f, 1.0f);
	*/
}

HCMatrix4x4 HCMatrix4x4::identity(void){
	HCMatrix4x4 mat;
	hpm_mat4x4_identityfv(mat.e);
	return mat;
}
