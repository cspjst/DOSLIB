/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
* @version     0.2.0
*/
#ifndef DOS_SERVICES_TYPES_H
#define DOS_SERVICES_TYPES_H

#pragma pack(1)
typedef struct {
    unsigned char   dotw;   // AL = day of the week (0=Sunday)
	unsigned short  year;   // CX = year (1980-2099)
	unsigned char   month;  // DH = month (1-12)
	unsigned char   day;    // DL = day (1-31)
} dos_date_t;
#pragma pack()

#pragma pack(1)
typedef struct {
    unsigned char   hour;       // CH = hour (0-23)
	unsigned char   minutes;    // CL = minutes (0-59)
	unsigned char   seconds;    // DH = seconds (0-59)
	unsigned char   hundredths; // DL = hundredths (0-99)
} dos_time_t;
#pragma pack()

#endif
