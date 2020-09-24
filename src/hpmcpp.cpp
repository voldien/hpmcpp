#include"HpmCpp.h"
#include<hpm.h>

using namespace hpmcpp;

int Hpm::init(HPMSIMD hpmSIMD){
	return hpm_init((unsigned int)hpmSIMD);
}

bool Hpm::isSupported(HPMSIMD SIMD){
	return hpm_support_cpu_feat(SIMD);
}