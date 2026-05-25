/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
*
* @url http://bitsavers.informatik.uni-stuttgart.de/pdf/borland/turbo_c/Turbo_C_Reference_Guide_1987.pdf
* @url https://www.stanislavs.org/helppc/
*/
#ifndef DOS_SERVICES_H
#define DOS_SERVICES_H

#include "dos_error_types.h"
#include "dos_services_types.h"

// 0  Program terminate
// 1  Keyboard input with echo
// 2  Display output
// 3  Wait for auxiliary device input
// 4  Auxiliary output
// 5  Printer output
// 6  Direct console I/O
// 7  Wait for direct console input without echo
// 8  Wait for console input without echo
// 9  Print string
// A  Buffered keyboard input
// B  Check standard input status
// C  Clear keyboard buffer, invoke keyboard function

// F  Open file using FCB
// 10  Close file using FCB
// 11  Search for first entry using FCB
// 12  Search for next entry using FCB
// 13  Delete file using FCB
// 14  Sequential read using FCB
// 15  Sequential write using FCB
// 16  Create a file using FCB
// 17  Rename file using FCB
// 18  DOS dummy function (CP/M) (not used/listed)

// 1B  Get allocation table information
// 1C  Get allocation table info for specific device
// 1D  DOS dummy function (CP/M) (not used/listed)
// 1E  DOS dummy function (CP/M) (not used/listed)
// 1F  Get pointer to default drive parameter table (undocumented)
// 20  DOS dummy function (CP/M) (not used/listed)
// 21  Random read using FCB
// 22  Random write using FCB
// 23  Get file size using FCB
// 24  Set relative record field for FCB

// 25  Set interrupt vector
void dos_set_interrupt_vector(unsigned char vec_num, void* phandler);

// 26  Create new program segment
// 27  Random block read using FCB
// 28  Random block write using FCB
// 29  Parse filename for FCB

// 2A  Get date
void dos_get_date(dos_date_t* date);
// 2B  Set date
dos_error_code_t dos_set_date(const dos_date_t* date);
// 2C  Get time
void dos_get_time(dos_time_t* time);
// 2D  Set time
dos_error_code_t dos_set_time(const dos_time_t* time);

// 30  Get DOS version number
// 31  Terminate process and remain resident
// 32  Get pointer to drive parameter table (undocumented)
// 33  Get/set Ctrl-Break check state & get boot drive
// 34  Get address to DOS critical flag (undocumented)

// 35  Get interrupt vector
void* dos_get_interrupt_vector(unsigned char vec_num);

// 4B  EXEC load and execute program (func 1 undocumented)

// 4C  Terminate process with return code
void dos_terminate_process_with_return_code(unsigned char return_code);

// 4D  Get return code of a sub-process

// 50  Set current process id (undocumented)
// 51  Get current process id (undocumented)

// 52  Get pointer to DOS "INVARS" (undocumented)
void* dos_undoc_get_ptr_invars();

// 53  Generate drive parameter table (undocumented)

// 55  Create PSP (undocumented)

#endif
