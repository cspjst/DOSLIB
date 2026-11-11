#include "test_dos_files.h"
#include "test_dos_memory.h"
#include "test_dos_services.h"
#include "../DOS/dos_version.h"

#include <stdio.h>

static void test_dos() {
    test_dos_files();
    test_dos_memory();
    test_dos_services();
    printf("DOSLIB v %s PASS.\n", dos_version_string());
}
