#include"HpmCpp.h"
#include<hpm.h>

using namespace LIBHPM;

int Hpm::init(HPMSIMD hpmSIMD){
	return hpm_init((unsigned int)hpmSIMD);
}

bool Hpm::isSupported(HPMSIMD SIMD){
	return hpm_support_cpu_feat(SIMD);
}