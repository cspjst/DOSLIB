#include "dos_services_tools.h"

char* dos_byte_to_str(unsigned char byte, char* buf) {
    *buf++ = (byte / 10) + '0';
    *buf++ = (byte % 10) + '0';
    return buf;
}

char* dos_word_to_str(unsigned short word, char* buf) {
    *buf++ = (word / 1000)      + '0';
    *buf++ = (word / 100  % 10) + '0';
    *buf++ = (word / 10   % 10) + '0';
    *buf++ = (word        % 10) + '0';
    return buf;
}

char* dos_time_to_str(const dos_time_t* t, char* buf, char sep) {
    if (!t || !buf) return buf;

    buf = dos_byte_to_str(t->hour, buf);
    *buf++ = sep;
    buf = dos_byte_to_str(t->minutes, buf);
    *buf++ = sep;
    buf = dos_byte_to_str(t->hour, buf);
    *buf = '\0';

    return buf;
}

char* dos_date_to_str(const dos_date_t* d, char* buf, char sep) {
    if (!d || !buf) return buf;

    buf = dos_word_to_str(d->year, buf);
    *buf++ = sep;
    buf = dos_byte_to_str(d->month, buf);
    *buf++ = sep;
    buf = dos_byte_to_str(d->day, buf);
    *buf = '\0';

    return buf;
}
