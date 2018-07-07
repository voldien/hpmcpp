/**
    C++ Wrapper for the hpm library.
    Copyright (C) 2017  Valdemar Lindberg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef _HPMCPP_VECTOR_3D_H_
#define _HPMCPP_VECTOR_3D_H_ 1
#include "HCTypes.h"

/**
 *	Vector3 class. Contains
 *	x, y, z component. Where the
 *	size of the object is 128 bit.
 */
class HCDECLSPEC HCVector3{
public:
	HCVector3(void);
	HCVector3(float val);
	HCVector3(float e0, float e1, float e2);
	HCVector3(const HCVector3& v);

	/**
	 *	Get indiviual component of vector.
	 *	@Return
	 */
	float HCAPIFASTENTRY x(void) const;
	float HCAPIFASTENTRY y(void) const;
	float HCAPIFASTENTRY z(void) const;

	/**
	 *
	 */
	void HCAPIFASTENTRY setX(float _x);
	void HCAPIFASTENTRY setY(float _y);
	void HCAPIFASTENTRY setZ(float _z);

	/**
	 *
	 * @return
	 */
	const HCVector3& operator+(void) const;
	HCVector3 operator-(void) const;

	/**
	 *
	 * @param i
	 * @return
	 */
	inline float operator[](int i) const {
		return this->e[i];
	}
	inline float& operator[](int i) {
		return this->e[i];
	}
	inline operator float*(void) {
		return (float*) this;
	}

	/**
	 *	Compute length.
	 *	@Return non-negative number.
	 */
	float HCAPIENTRY length(void) const;
	float HCAPIENTRY squaredLength(void) const;

	/**
	 *
	 */
	void HCAPIENTRY makeUnitVector(void);

	/**
	 *
	 *	@Return
	 */
	float HCAPIENTRY minComponent(void) const;
	float HCAPIENTRY maxComponent(void) const;
	float HCAPIENTRY maxAbsComponent(void) const;
	float HCAPIENTRY minAbsComponent(void) const;

	/**
	 *	Normalize vector.
	 *	@Return normalized vector.
	 */
	HCVector3 HCAPIENTRY normalize(void) const;

	/**
	 *	Check equality.
	 *	@Return
	 */
	friend bool operator==(const HCVector3& v1, const HCVector3& v2);
	friend bool operator!=(const HCVector3& v1, const HCVector3& v2);

	/**
	 *	Create input stream for creating vector
	 *	from input stream.
	 *	@Return stream reference.
	 */
	friend std::istream &operator>>(std::istream &is, HCVector3& t);

	/**
	 *	Create output stream of vector value.
	 *	@Return stream reference.
	 */
	friend std::ostream &operator<<(std::ostream &os, const HCVector3& t);

	/**
	 *	@Return
	 */
	friend HCVector3 operator+(const HCVector3& v1, const HCVector3& v2);
	friend HCVector3 operator-(const HCVector3& v1, const HCVector3& v2);
	friend HCVector3 operator/(const HCVector3& vec, float scalar);
	friend HCVector3 operator*(const HCVector3& vec, float scalar);
	friend HCVector3 operator*(float scalar, const HCVector3& vec);
	friend HCVector3 operator*(const HCVector3& vec1, const HCVector3& vec2);

	/**
	 *	@Return
	 */
	HCVector3& operator=(const HCVector3& v2);
	HCVector3& operator+=(const HCVector3& v2);
	HCVector3& operator-=(const HCVector3& v2);
	HCVector3& operator/=(float scalar);
	HCVector3& operator*=(float scalar);

	/**
	 *	@Return
	 */
	friend HCVector3 HCAPIENTRY unitVector3(const HCVector3& v);

	/**
	 *	@Return
	 */
	friend HCVector3 HCAPIENTRY minVec(const HCVector3& v1,
	        const HCVector3& v2);

	/**
	 *	@Return
	 */
	friend HCVector3 HCAPIENTRY maxVec(const HCVector3& v1,
	        const HCVector3& v2);

	/**
	 *	@Return
	 */
	friend HCVector3 HCAPIENTRY cross(const HCVector3& v1, const HCVector3& v2);

	/**
	 *	Create reflection vector.
	 *	@Return reflected vector with same magnitude.
	 */
	friend HCVector3 HCAPIENTRY reflection(const HCVector3& vector,
	        const HCVector3& normal);

	/**
	 *	@Return
	 */
	friend HCVector3 HCAPIENTRY refraction(const HCVector3& v1,
	        const HCVector3& normal, float refraction);

	/**
	 *	@Return
	 */
	friend float HCAPIENTRY dot(const HCVector3& v1, const HCVector3& v2);

	/**
	 *	@Return
	 */
	friend float HCAPIENTRY tripleProduct(const HCVector3& v1,
	        const HCVector3& v2, const HCVector3& v3);

	/**
	 *	@Return
	 */
	friend HCVector3 HCAPIENTRY tangent(const HCVector3& normal);

	/**
	 *  @Return
	 */
	friend HCVector3 HCAPIENTRY biTangent(const HCVector3& normal,
	        const HCVector3& tangent);

	/**
	 *  @Return
	 */
	friend HCVector3 HCAPIENTRY biNormal(const HCVector3& normal,
	        const HCVector3& tangent);

private:	/*	Private method.	*/

	hpmvec3f e;

public:	/*	Static methods.	*/

	/**
	 *	Create predefined vector3.
	 */
	inline static HCVector3 forward(void){return HCVector3(0.0f, 0.0f, 1.0f);}
	inline static HCVector3 back(void){return HCVector3(0.0f, 0.0f, -1.0f);}
	inline static HCVector3 right(void){return HCVector3(1.0f, 0.0f, 0.0f);}
	inline static HCVector3 left(void){return HCVector3(-1.0f, 0.0f, 0.0f);}
	inline static HCVector3 up(void){return HCVector3(0.0f, 1.0f, 0.0f);}
	inline static HCVector3 down(void){return HCVector3(0.0f, -1.0f, 0.0f);}
	inline static HCVector3 zero(void){return HCVector3(0.0f, 0.0, 0.0f);}

	/**
	 *	Linear interpolation between v1 and v2 based on t.
	 *	@Return
	 */
	static HCVector3 HCAPIENTRY lerp(const HCVector3& vec1,
	        const HCVector3& vec2, float t);

	/**
	 *	Spherical interpolation.
	 *	@Return
	 */
	static HCVector3 HCAPIENTRY slerp(const HCVector3& vec1,
	        const HCVector3& vec2, float t);
};

#endif
