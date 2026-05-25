/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
* @version     0.1.0
*/
#include "dos_error.h"
#include "dos_error_types.h"
#include "dos_errror_messages.h"

#include <stdio.h>

const char* dos_strerror(dos_error_code_t err) {
    if (err >= sizeof(DOS_ERROR_STRINGS) / sizeof(DOS_ERROR_STRINGS[0]))
        return "Unknown error";
    return DOS_ERROR_STRINGS[err];
}

void dos_perror(const char* prefix, dos_error_code_t err) {
    if (prefix && *prefix)
        fprintf(stderr, "%s: %s\n", prefix, dos_strerror(err));
    else
        fprintf(stderr, "%s\n", dos_strerror(err));
}
