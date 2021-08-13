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
#ifndef _HPMCPP_MATH_H_
#define _HPMCPP_MATH_H_ 1
#include "HCTypes.hpp"
#include <cmath>
#include <float.h>

namespace LIBHPM {
	/**
	 *
	 */
	class HCDECLSPEC Math {
	  public:
		template <class T> inline constexpr static T clamp(T a, T min, T max) {
			static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value,
						  "Must be a decimal type(float/double/half) or integer.");
			return Math::max<T>(min, Math::min<T>(max, a));
		}

		/**
		 *	Get max value of a and b.
		 */
		template <typename T> inline constexpr static T max(T a, T b) {
			static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value,
						  "Must be a decimal type(float/double/half) or integer.");
			return (static_cast<T>(a) < static_cast<T>(b)) ? static_cast<T>(b) : static_cast<T>(a);
		}

		/**
		 *	Get min value of a and b.
		 */
		template <typename T> inline constexpr static T min(T a, T b) noexcept {
			static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value,
						  "Must be a decimal type(float/double/half) or integer.");
			return (static_cast<T>(b) < static_cast<T>(a)) ? static_cast<T>(b) : static_cast<T>(a);
		}

		template <typename T> inline constexpr static T frac(T a) noexcept {
			static_assert(std::is_floating_point<T>::value, "Must be a decimal type(float/double/half).");
			T part;
			std::modf(a, &part);
			return part;
		}

		/**
		 *	Convert degree to radian.
		 */
		template <typename T> inline constexpr static T deg2Rad(T deg) noexcept {
			static_assert(std::is_floating_point<T>::value, "Must be a decimal type(float/double/half).");
			return deg * static_cast<T>(Deg2Rad);
		}

		/**
		 *	Convert radian to degree.
		 */
		template <typename T> inline constexpr static T radToDeg(T deg) noexcept {
			static_assert(std::is_floating_point<T>::value, "Must be a decimal type(float/double/half).");
			return deg * static_cast<T>(Rad2Deg);
		}

		/**
		 * Linear interpolation.
		 */
		template <typename T> inline constexpr static T lerp(T a, T b, T t) noexcept {
			static_assert(std::is_floating_point<T>::value, "Must be a decimal type(float/double/half).");
			return (a + (b - a) * t);
		}
		template <typename T> inline constexpr static T lerpClamped(T a, T b, T t) noexcept {
			static_assert(std::is_floating_point<T>::value, "Must be a decimal type(float/double/half).");
			return (a + (b - a) * Math::clamp<T>(t, static_cast<T>(0.0), static_cast<T>(1.0)));
		}

		inline static constexpr float Epsilon = FLT_EPSILON;
		inline static constexpr float PI = 3.14159265358979323846;
		inline static constexpr float Infinite = 0;
		inline static constexpr float Deg2Rad = Math::PI / 180.0f;
		inline static constexpr float Rad2Deg = 180 / Math::PI;
		inline static constexpr float NegativeInfinity = 0;
	};
} // namespace LIBHPM

#endif