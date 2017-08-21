#include"HpmCpp.h"

int Hpm::init(HPMSIMD hpmSIMD){
	return hpm_init((unsigned int)hpmSIMD);
}
