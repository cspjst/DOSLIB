#ifndef DOS_SERVICES_TOOLS_H
#define DOS_SERVICES_TOOLS_H

#include "dos_services_types.h"

char* dos_time_to_str(const dos_time_t* t, char* buf, char sep);

char* dos_date_to_str(const dos_date_t* d, char* buf, char sep);

#endif
