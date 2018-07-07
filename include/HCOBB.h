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
class HCDECLSPEC HCOBB {
public:

    HCOBB(void);

    HCOBB(const HCOBB &obb);

    HCOBB(const HCVector3 &u, const HCVector3 &v, const HCVector3 &w);

    HCOBB(const HCVector3 &u, const HCVector3 &v, const HCVector3 &w, const HCVector3 &size);

    HCOBB(const HCVector3 &u, const HCVector3 &v, const HCVector3 &w, const HCVector3 &center, const HCVector3 &size);

    /**
     * Get U axis.
     * @return normalized axis.
     */
    const HCVector3 &HCAPIENTRY getU(void) const;

    /**
     *	Get V axis.
     *	@Return normalized axis.
     */

    /**
     *
     * @return
     */
    const HCVector3 &HCAPIENTRY getV(void) const;

    /**
     * Get W axis.
     * @return normalized axis.
     */
    const HCVector3 &HCAPIENTRY getW(void) const;

    /**
     * Set size of box.
     * @param size
     */
    void setSize(const HCVector3 &size) {
        this->size = size;
    }

    /**
     * Get half size.
     * @return non-negative vector of the size.
     */
    inline HCVector3 getSize(void) {
        return size;
    }

    /**
     *
     * @return
     */
    inline const HCVector3 &getSize(void) const {
        return this->size;
    }

    /**
     *
     * @param size
     */
    inline void setCenter(const HCVector3 &size) {

    }

    /**
     *
     * @return
     */
    inline HCVector3 getCenter(void) const {
        return HCVector3(this->halfu, this->halfv, this->halfw);
    }

    HCOBB &operator=(const HCOBB &obb);

    /**
     *
     * @param is
     * @param t
     * @return stream reference.
     */
    friend std::istream &operator>>(std::istream &is, HCOBB &t);

    /**
     *
     * @param is
     * @param t
     * @return stream reference.
     */
    friend std::ostream &operator<<(std::ostream &os, const HCOBB &t);

private:    /*	Attributes.	*/

    HCONB onb;          /*	*/
    HCVector3 size;     /*	*/
    float halfu;        /*	*/
    float halfv;        /*	*/
    float halfw;        /*	*/
};


#endif
