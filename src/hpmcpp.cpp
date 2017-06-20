#include"HpmCpp.h"

int HpmCpp::init(HPMSIMD hpmSIMD){
	return hpm_init((unsigned int)hpmSIMD);
}
