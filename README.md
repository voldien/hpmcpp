# HPMCPP
[![Actions Build Status](https://github.com/voldien/hpmcpp/workflows/HpmCpp/badge.svg?branch=master)](https://github.com/voldien/hpmcpp/actions)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

The *hpmcpp* is a C++ wrapper library for the [hpm](https://github.com/voldien/hpm) library. This makes it more friendly to use in an object-oriented programming environment.

## Examples ##

```c++
#include<hpmcpp/HC.h>
int main(int argc, const char** argv){

	HCMatrix4x4 iden;
	HCMatrix4x4 tra;
	HCMatrix4x4 res;

	iden.identity();
	tra = HCMatrix4x4::translate(0,0,0);
	res = iden * res;
	std::cout << res;
	
	return EXIT_SUCCESS;
}
```

## Dependencies

The *hpmcpp* library only depends on the *hpm* library.

## License

This project is licensed under the GPL+3 License - see the [LICENSE](LICENSE) file for details
