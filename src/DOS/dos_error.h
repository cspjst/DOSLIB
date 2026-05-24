/**
* @author      Jeremy Simon Thornton
* @copyright   2024 Jeremy Simon Thornton
* @version     0.1.0
*/
#ifndef DOS_ERROR
#define DOS_ERROR

#include "dos_error_types.h"

const char* dos_strerror(dos_error_code_t err);

void dos_perror(const char* prefix, dos_error_code_t err);

#endif
