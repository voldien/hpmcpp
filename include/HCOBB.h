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
#ifndef _HPMCPP_OBB_H_
#define _HPMCPP_OBB_H_ 1
#include"HCONB.h"
#include"HCVector3.h"

/**
 *	Oriented bounding box.
 */
class HCDECLSPEC HCOBB{
public:

	HCOBB(void);
	HCOBB(const HCOBB& obb);
	HCOBB(const HCVector3& u, const HCVector3& v, const HCVector3& w);
	HCOBB(const HCVector3& u, const HCVector3& v, const HCVector3& w, const HCVector3& size);
	HCOBB(const HCVector3& u, const HCVector3& v, const HCVector3& w, const HCVector3& center, const HCVector3& size);

	/**
	 *	Get U axis.
	 *	@Return normailized axis.
	 */
	HCVector3 getU(void)const;

	/**
	 *	Get V axis.
	 *	@Return normailized axis.
	 */
	HCVector3 getV(void)const;

	/**
	 *	Get W axis.
	 *	@Return normailized axis.
	 */
	HCVector3 getW(void)const;

	/**
	 *	Set size of box.
	 */
	void setSize(const HCVector3& size){
		this->size = size;
	}

	/**
	 *	@Return
	 */
	inline HCVector3 getSize(void){
		return size;
	}

	/**
	 *	@Return
	 */
	inline const HCVector3& getSize(void)const{
		return this->size;
	}

	/**
	 *	@Return
	 */
	void setCenter(const HCVector3& size);

	/**
	 *	@Return
	 */
	inline HCVector3 getCenter(void)const{
		return HCVector3(halfu, halfv, halfw);
	}

	/**
	 *	
	 *	@Return
	 */
	HCOBB& operator=(const HCOBB& obb);


private:	/*	Attributes.	*/

	HCONB onb;	/*	*/
	HCVector3 size;	/*	*/
	float halfu;	/*	*/
	float halfv;	/*	*/
	float halfw;	/*	*/
};


#endif