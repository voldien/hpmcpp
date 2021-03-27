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
#ifndef _HPMCPP_TYPES_H_
#define _HPMCPP_TYPES_H_ 1
#include <hpm.h>
#include <iostream>
#include <math.h>
#include <string.h>

/**
 *	Compiler
 */
#ifdef _MSC_VER /*	Visual Studio C++ Compiler.	*/
#define HC_VC
#define ENGINE_EX_COMPILER 1
#if _MSC_VER >= 1900
#define HC_V13 _MSC_VER
#elif _MSC_VER >= 1800
#define HC_V12 _MSC_VER
#elif _MSC_VER >= 1700
#define HC_VC11 _MSC_VER
#elif _MSC_VER >= 1600
#define HC_VC10 _MSC_VER
#elif _MSC_VER >= 1500
#define HC_VC9 _MSC_VER
#elif _MSC_VER >= 1400
#define HC_VC8 _MSC_VER
#elif _MSC_VER >= 1300
#define HC_VC7 _MSC_VER
#else
#define HC_VC6 _MSC_VER
#endif
#pragma warning(disable : 4201)
#define HC_COMPILER_NAME "Visual Studio C++/C"

#elif defined(__clang__) || defined(__llvm__) /*  LLVM, clang   */
#define HC_LLVM 1
#define HC_CLANG 1
#define ENGINE_HC_COMPILER 5
#define HC_COMPILER_NAME "LLVM/CLANG"
#define HC_COMPILER_MAJOR_VERSION __clang_major__
#define HC_COMPILER_MINOR_VERSION __clang_minor__

#elif defined(__GNUC__) || defined(__SNC__) || defined(__GNUC_MINOR__) /*  GNU C Compiler	*/
#define HC_GNUC 1
#define ENGINE_HC_COMPILER 2
#define HC_COMPILER_NAME "GNU C"
#define HC_COMPILER_MAJOR_VERSION __clang_major__
#define HC_COMPILER_MINOR_VERSION __clang_minor__
#if defined(__GNUG__) /*  GNU C++ Compiler*/
#define HC_GNUCXX
#endif

#elif defined(__ghs__) /* GHS	*/
#define HC_GHS 1
#define ENGINE_HC_COMPILER 3

#elif defined(__HP_cc) || defined(__HP_aCC) /*	*/

#elif defined(__PGI) /*	*/

#elif defined(__ICC) || defined(__INTEL_COMPILER) /*  Intel Compiler  */
#define HC_INTEL
#define ENGINE_HC_COMPILER 4
#define HC_COMPILER_NAME "Intel C++"

#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)

#else
#error Unsupported Compiler.
#endif

/*
 *	Alignment.
 */
#ifndef HC_ALIGN
#if defined(HC_MSVC)
#define HC_ALIGN(alignment, decl) __declspec(align(alignment)) decl
#define HC_ALIGN_PREFIX(alignment) __declspec(align(alignment))
#define HC_ALIGN_VECTOR(alignment) __declspec((__vector_size__(alignment), __may_alias__))
#elif defined(HC_GNUC)
#define HC_ALIGN(alignment, decl) decl __attribute__((aligned(alignment)))
#define HC_ALIGN_PREFIX(alignment) __attribute__((aligned(alignment)))
#define HC_ALIGN_VECTOR(alignment) __attribute__((__vector_size__(alignment), __may_alias__))
#elif defined(HC_CLANG)
#define HC_ALIGN(alignment, decl) decl __attribute__((aligned(alignment)))
#define HC_ALIGN_PREFIX(alignment) __attribute__((aligned(alignment)))
#define HC_ALIGN_VECTOR(alignment) __attribute__((__vector_size__(alignment), __may_alias__))
#else
#pragma message("Warning: You'd need to add HC_ALIGN, HC_ALIGN_PREFIX, HC_ALIGN_VECTOR for this compiler.")
#define HC_ALIGN(alignment, decl)
#define HC_ALIGN_PREFIX(alignment)
#define HC_ALIGN_VECTOR(alignment)
#endif
#endif

/**
 *	Calling function convention.
 */
#ifdef HC_WINDOWS /** Windows Calling Convention.*/
#define HCAPIENTRY __cdecl
#define HCAPIFASTENTRY __fastcall
#define HCAPITHISENTRY __thiscall
#define HCAPISTDENTRY __stdcall
#elif defined(HC_ANDROID) /** Android Calling Convention	*/
#define HCAPIENTRY JNICALL
#define HCAPIFASTENTRY JNICALL
#define HCAPITHISENTRY JNICALL
#define HCAPISTDENTRY JNICALL
#else
#if !defined(__cdecl) && (defined(HC_GNUC) || defined(HC_CLANG))
#define __cdecl __attribute__((__cdecl__))
#define __stdcall __attribute__((stdcall))
#define __fastcall __attribute__((fastcall))
#endif
#define HCAPIENTRY __cdecl
#define HCAPISTDENTRY __stdcall
#define HCAPIFASTENTRY __fastcall
#endif

/**
 *	library declaration.
 */
#ifdef HC_GNUC
#if defined(HC_UNIX)
#define HCDECLSPEC __attribute__((__visibility__("default")))
#else
#define HCDECLSPEC
#endif
#elif defined(HC_CLANG)
#if defined(HC_UNIX)
#define HCDECLSPEC __attribute__((visibility(default)))
#else
#define HCDECLSPEC
#endif

#elif defined(HC_VC)
#if HC_INTERNAL
#define HCDECLSPEC __declspec(dllexport)
#else
#define HCDECLSPEC __declspec(dllimport)
#endif
#endif

#if defined(HC_ARM) || defined(HC_I386)

#endif

namespace LIBHPM {
	/**
	 *	Class forwarding.
	 */
	class HpmCpp;
	class Quaternion;
	class Matrix4x4;
	class Matrix3x3;
	class Vector4;
	class Vector3;
	class Vector2;
	class Ray;
	class ONB;
	class OBB;
	class AABB;
	class Plane;
	class BoundingSphere;
} // namespace LIBHPM

#endif
