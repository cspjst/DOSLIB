#include "dos_services_tools.h"

char* dos_time_to_str(const dos_time_t* t, char* buf, char sep) {
    if (!t || !buf) return buf;

    char* p = buf;
    // hour
    *p++ = (t->hour   / 10) + '0';
    *p++ = (t->hour   % 10) + '0';
    *p++ = sep;
    // minutes
    *p++ = (t->minutes / 10) + '0';
    *p++ = (t->minutes % 10) + '0';
    *p++ = sep;
    // seconds
    *p++ = (t->seconds / 10) + '0';
    *p++ = (t->seconds % 10) + '0';
    // null terminate
    *p = '\0';
    return p;
}

char* dos_date_to_str(const dos_date_t* d, char* buf, char sep) {
    if (!d || !buf) return buf;

    char* p = buf;

    // year 4 digits (1980-2099)
    *p++ = (d->year / 1000)      + '0';
    *p++ = (d->year / 100  % 10) + '0';
    *p++ = (d->year / 10   % 10) + '0';
    *p++ = (d->year        % 10) + '0';
    *p++ = sep;
    // month
    *p++ = (d->month / 10) + '0';
    *p++ = (d->month % 10) + '0';
    *p++ = sep;
    // day
    *p++ = (d->day   / 10) + '0';
    *p++ = (d->day   % 10) + '0';
    // null terminate
    *p = '\0';
    return p;
}
