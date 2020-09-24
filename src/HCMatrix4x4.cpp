#include "HCMatrix4x4.h"
#include <iostream>
#include "HCQuaternion.h"
#include "HCVector3.h"
#include "HCVector4.h"

using namespace hpmcpp;


Matrix4x4::Matrix4x4(const Matrix4x4& other) {
	*this = other;
}

bool Matrix4x4::isIdentity(void){
	static const Matrix4x4 identity = Matrix4x4::identity();
	return *this == identity;
}

float Matrix4x4::determinant(void) const {
	return hpm_mat4x4_determinantfv(this->e);
}

Matrix4x4 Matrix4x4::inverse(void) const {
	Matrix4x4 res;
	hpm_mat4x4_inversefv(this->e, res.e);
	return res;
}

Matrix4x4 Matrix4x4::transpose(void) const {
	Matrix4x4 mat = *this;
	hpm_mat4x4_transposefv(mat.e);
	return mat;
}


float* Matrix4x4::operator[](int index) {
	//return (float*) &this->e[index][0];
}

float* Matrix4x4::operator[](int index)const {
	//return (float*)&this->e[0][0];
}

Matrix4x4 Matrix4x4::operator*(float rh) const{
    Matrix4x4 mat = *this;
    hpm_mat4x4_multiply_scalarf(this->e, rh, mat.e);
    return mat;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& rh) const {
	Matrix4x4 mat;
	hpm_mat4x4_multiply_mat4x4fv(this->e, rh.e, mat.e);
	return mat;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& rh) const {
	Matrix4x4 mat;
	hpm_mat4x4_additition_mat4x4fv(this->e, rh.e, mat.e);
	return mat;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& rh) const {
	Matrix4x4 mat;
	hpm_mat4x4_subraction_mat4x4fv(this->e, rh.e, mat.e);
	return mat;
}

Vector4 Matrix4x4::operator*(const Vector4& rh) const {
	Vector4 vm;
	hpm_mat4x4_multiply_mat1x4fv(this->e, (const hpmvec4f*)&rh, (hpmvec4f*)&vm);
	return vm;
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& rh) {
	hpm_mat4x4_copyfv(this->e, rh.e);
	return *this;
}

Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& rh) {
	*this = *this + rh;
	return *this;
}

Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& rh) {
	*this = *this - rh;
	return *this;
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& rh) {
	*this = *this * rh;
	return *this;
}

bool Matrix4x4::operator==(const Matrix4x4& rh){
	return (bool)hpm_mat4_eqfv(this->e, rh.e);
}
bool Matrix4x4::operator!=(const Matrix4x4& rh){
	return (bool)hpm_mat4_neqfv(this->e, rh.e);
}

std::istream &operator>>(std::istream &is, Matrix4x4& t){
	is >> *((Vector4*)t[0]);
	is >> *((Vector4*)t[1]);
	is >> *((Vector4*)t[2]);
	is >> *((Vector4*)t[3]);
	return is;
}
std::ostream &operator<<(std::ostream &os, const Matrix4x4& t){

	os << '|' << *((Vector4*)t[0]) << "|\n";
	os << '|' << *((Vector4*)t[1]) << "|\n";
	os << '|' << *((Vector4*)t[2]) << "|\n";
	os << '|' << *((Vector4*)t[3]) << "|\n";
	return os;
}

Matrix4x4 Matrix4x4::translate(float x, float y, float z) {
	Matrix4x4 mat;
	hpm_mat4x4_translationf(mat.e, x, y, z);
	return mat;
}

Matrix4x4 Matrix4x4::translate(const Vector3& translation) {
	Matrix4x4 mat;
	hpm_mat4x4_translationfv(mat.e, (hpmvec3f*)&translation);
	return mat;
}

Matrix4x4 Matrix4x4::rotate(float angle, const Vector3& axis) {
	Matrix4x4 mat;
	hpm_mat4x4_rotationfv(mat.e, angle, (hpmvec3f*)&axis);
	return mat;
}

Matrix4x4 Matrix4x4::rotate(const Quaternion& quat) {
	Matrix4x4 mat;
	hpm_mat4x4_rotationQfv(mat.e, &quat.e);
	return mat;
}

Matrix4x4 Matrix4x4::scale(float x, float y, float z) {
	Matrix4x4 mat;
	hpm_mat4x4_scalef(mat.e, x, y, z);
	return mat;
}

Matrix4x4 Matrix4x4::scale(const Vector3& scale) {
	Matrix4x4 mat;
	hpm_mat4x4_scalefv(mat.e, (const hpmvec3f*)&scale);
	return mat;
}

Matrix4x4 Matrix4x4::lookAt(const Vector3& lookPosition,
        const Vector3& position, const Vector3& up){
	Matrix4x4 look;
	hpm_util_lookatfv((hpmvec3f*)&lookPosition, (hpmvec3f*)&position, (hpmvec3f*)&up, look.e);
	return look;
}

Matrix4x4 Matrix4x4::perspective(float fov, float aspect, float near,
		float far) {
	Matrix4x4 mat;
	hpm_mat4x4_projfv(mat.e, fov, aspect, near, far);
	return mat;
}

Matrix4x4 Matrix4x4::orth(float left, float right, float bottom, float top,
		float near, float far) {
	Matrix4x4 mat;
	hpm_mat4x4_orthfv(mat.e, left, right, bottom, top, near, far);
	return mat;
}

int Matrix4x4::unProject(float winx,
                            float winy, float winz, const Matrix4x4 *projection,
                            const Matrix4x4 *modelview, const int *HPM_RESTRICT viewport,
                            HCVector3 *HPM_RESTRICT pos) {
	return hpm_mat4x4_unprojf(winx, winy, winz, projection->e, modelview->e, viewport, &pos->e);
}

Matrix4x4 Matrix4x4::biasMatrix(void) {
	const hpmvec4x4f_t bias = {
		{ 0.5f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.5f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 0.5f, 0.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
	};

	Matrix4x4 biasMatrix;
	hpm_mat4x4_copyfv(biasMatrix.e, bias);
	return biasMatrix;
}

Matrix4x4 Matrix4x4::identity(void){
	Matrix4x4 mat;
	hpm_mat4x4_identityfv(mat.e);
	return mat;
}
