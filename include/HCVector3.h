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
 *
 */
class HCDECLSPEC HCVector3{
public:
    HCVector3(void);
    HCVector3(float val);
    HCVector3(float e0, float e1, float e2);
    HCVector3(const HCVector3& v);

    /**
     *	@Return
     */
    inline float x(void)const{return this->e[0];}
    inline float y(void)const{return this->e[1];}
    inline float z(void)const{return this->e[2];}

    /**
     *
     */
    void setX(float _x){e[0] = _x;}
    void setY(float _y){e[1] = _y;}
    void setZ(float _z){e[2] = _z;}


    /**
     *	@Return
     */
    const HCVector3& operator+(void)const;
    HCVector3 operator-(void)const;

    /**
     *	@Return
     */
    inline float operator[](int i)const {return e[i];}
    inline float& operator[](int i){return e[i];}
    inline operator float*(void){return (float*)this;}

    /**
     *	@Return
     */
    float length(void)const;
    float squaredLength(void)const;

    /**
     *
     */
    void makeUnitVector(void);

    /**
     *
     *	@Return
     */
    float minComponent(void)const;
    float maxComponent(void)const;
    float maxAbsComponent(void)const;
    float minAbsComponent(void)const;
    int indexOfMinComponent(void)const;
    int indexOfMaxComponent(void)const;
    int indexOfMinAbsComponent(void)const;
    int indexOfMaxAbsComponent(void)const;

    /**
     *
     *	@Return
     */
    HCVector3 normalize(void)const;


    /**
     *
     *	@Return
     */
    friend bool operator==(const HCVector3& v1, const HCVector3& v2);
    friend bool operator!= (const HCVector3& v1, const HCVector3& v2);

    /**
     *
     *	@Return
     */
    friend std::istream &operator>>(std::istream &is, HCVector3& t);
    friend std::ostream &operator<<(std::ostream &os, const HCVector3& t);

    /**
     *	@Return
     */
    friend HCVector3 operator+(const HCVector3& v1, const HCVector3& v2);
    friend HCVector3 operator-(const HCVector3& v1, const HCVector3& v2);
    friend HCVector3 operator/(const HCVector3& vec, float scalar);
    friend HCVector3 operator*(const HCVector3& vec, float scalar);
    friend HCVector3 operator*(float scalar,const HCVector3& vec);
    friend HCVector3 operator*(const HCVector3& vec1,const HCVector3& vec2);

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
    friend HCVector3 unitVector3(const HCVector3& v);
    friend HCVector3 minVec(const HCVector3& v1, const HCVector3& v2);
    friend HCVector3 maxVec(const HCVector3& v1, const HCVector3& v2);
    friend HCVector3 cross(const HCVector3& v1, const HCVector3& v2);
    friend HCVector3 reflection(const HCVector3& v1,const HCVector3& normal);
    friend HCVector3 refraction(const HCVector3& v1, const HCVector3& normal, float refraction);
    friend float dot(const HCVector3& v1, const HCVector3& v2);
    friend float tripleProduct(const HCVector3& v1, const HCVector3& v2, const HCVector3& v3);
    friend HCVector3 tangent(const HCVector3& normal);
    friend HCVector3 biTangent(const HCVector3& normal,const HCVector3& tangent);
    friend HCVector3 biNormal(const HCVector3& normal,const HCVector3& tangent);

private:	/*	Private method.	*/

	hpmvec3f e;

public:	/*	Static methods.	*/

    /**
     *	@Return
     */
    inline static HCVector3 forward(void){return HCVector3(0.0f, 0.0f, 1.0f);}
    inline static HCVector3 back(void){return HCVector3(0.0f, 0.0f, -1.0f);}
    inline static HCVector3 right(void){return HCVector3(1.0f, 0.0f, 0.0f);}
    inline static HCVector3 left(void){return HCVector3(-1.0f, 0.0f, 0.0f);}
    inline static HCVector3 up(void){return HCVector3(0.0f, 1.0f, 0.0f);}
    inline static HCVector3 down(void){return HCVector3(0.0f, -1.0f, 0.0f);}
    inline static HCVector3 zero(void){return HCVector3(0.0f, 0.0, 0.0f);}

    /**
     *	@Return
     */
    static HCVector3 lerp(const HCVector3& vec1, const HCVector3& vec2, float t);

    /**
     *	@Return
     */
    static HCVector3 slerp(const HCVector3& vec1, const HCVector3& vec2, float t);
};

#endif
