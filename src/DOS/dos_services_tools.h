#ifndef DOS_SERVICES_TOOLS_H
#define DOS_SERVICES_TOOLS_H

#include "dos_services_types.h"

char* dos_byte_to_str(unsigned char byte, char* buf);

char* dos_word_to_str(unsigned short word, char* buf);

char* dos_time_to_str(const dos_time_t* t, char* buf, char sep);

char* dos_date_to_str(const dos_date_t* d, char* buf, char sep);

char* dos_get_first_mcb();

#endif
