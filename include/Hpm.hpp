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
#ifndef _HPMCPP_H_
#define _HPMCPP_H_ 1
#include "HCMatrix3x3.hpp"
#include "HCMatrix4x4.hpp"
#include "HCQuaternion.hpp"
#include "HCTypes.hpp"
#include "HCVector2.hpp"
#include "HCVector3.hpp"
#include "HCVector4.hpp"

namespace LIBHPM {

	//typedef Vector3<float> Vector3f;

	/**
	 * hpmcpp initialization class.
	 * See more description of the SIMD enumerator.
	 * see hpm.h for more information.
	 */
	class HPMDECLSPEC Hpm {
	  public:
		/**
		 * HPM SIMD(Single Instruction Multiple Data) enumerator.
		 */
		enum HPMSIMD {
			eHPM_NONE = (0 << 0),	  /*	No HPM SIMD exention flag.	*/
			eHPM_NOSIMD = (1 << 0),	  /*	No SIMD hardware feature, using the FPU and ALU.	*/
			eHPM_MMX = (1 << 1),	  /*	MMX. (Yet not supported)	*/
			eHPM_SSE = (1 << 2),	  /*	SSE (Streaming SIMD Extensions).	*/
			eHPM_SSE2 = (1 << 3),	  /*	SSE2 (Streaming SIMD Extensions).	*/
			eHPM_SSE3 = (1 << 4),	  /*	SSE3 (Streaming SIMD Extensions).	*/
			eHPM_SSSE3 = (1 << 5),	  /*	SSSE3 (Streaming SIMD Extensions).	*/
			eHPM_SSE4_1 = (1 << 6),	  /*	SSE4.1 (Streaming SIMD Extensions).	*/
			eHPM_SSE4_2 = (1 << 7),	  /*	SSE4.2 (Streaming SIMD Extensions).	*/
			eHPM_AVX = (1 << 8),	  /*	AVX Version 1 (Advanced Vector Extension).	*/
			eHPM_AVX2 = (1 << 9),	  /*	AVX Version 2 (Advanced Vector Extension).	(Not tested)*/
			eHPM_AVX512 = (1 << 10),  /*	AVX512 (Advanced Vector Extension). (Yet not supported)	*/
			eHPM_NEON = (1 << 11),	  /*	ARM	FPU (floating-point unit) feature.	*/
			eHPM_SVML = (1 << 29),	  /*	Not supported.	*/
			eHPM_ACML = (1 << 30),	  /*	Not supported.	*/
			eHPM_DEFAULT = (1 << 31), /*	Default, makes attempt to take the best SIMD extension on the system.	*/
		};

		/**
		 * @brief Initialize hpm library.
		 * This function has to be
		 * called before using the library.
		 *
		 * @param flag valid hpm flag.
		 * @return int  1 if successfully initialized. 0 if there was a failure.
		 */
		static int HCAPIENTRY init(HPMSIMD flag) noexcept(false) {
			if (!isSupported(flag))
				throw std::runtime_error("Hpm SIMD extension flag not supported");
			return hpm_init((unsigned int)flag);
		}

		static bool HCAPIENTRY isSupported(HPMSIMD SIMD) noexcept { return hpm_support_cpu_feat(SIMD); }
	};

} // namespace LIBHPM

#endif
