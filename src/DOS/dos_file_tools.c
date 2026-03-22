#include "dos_file_tools.h"

#include "dos_error_types.h"
#include "dos_file_services.h"
#include "dos_file_types.h"

unsigned char dos_file_exists(const char* path_name) {
    dos_file_attributes_t attr;
    return dos_get_file_attributes(path_name, &attr) == 0;
}

unsigned char dos_file_is_eof(dos_file_handle_t fhandle) {            // invalid handle = EOF
    dos_file_position_t i, j = 0;
    dos_error_code_t e;
    e = dos_move_file_pointer(fhandle, 0, FSEEK_CUR, &i);       // save current position
    if(e) return e;
    e = dos_move_file_pointer(fhandle, 0, FSEEK_END, &j);       // get file size (seek to end)
    if(e) return e;
    e = dos_move_file_pointer(fhandle, i, FSEEK_SET, 0L);     // restore original position
    if(e) return e;
    return (i >= j);                                            // dual-seek method for reliable EOF detection
}

dos_error_code_t dos_file_size(dos_file_handle_t fhandle,  dos_file_size_t* size) {
    dos_file_position_t i, j;
    dos_error_code_t e;
    e = dos_move_file_pointer(fhandle, 0, FSEEK_CUR, &i);      // save current position
    if(e) return e;
    e = dos_move_file_pointer(fhandle, 0, FSEEK_END, &j);      // seek to the end
    if(e) return e;
    e = dos_move_file_pointer(fhandle, i, FSEEK_SET, &i);      // restore original position
    if(e) return e;
    *size = j;
    return DOS_SUCCESS;
}

const char* dos_file_ext(const char* path_name) {
    if (!path_name || !path_name[0]) return 0L;
    const char* dot = 0L;
    const char* p = path_name;

    while (*p) {
        if (*p == '\\' || *p == '/' || *p == ':') dot = 0L;   // Path separator so reset dot
        if (*p == '.') dot = p;
        p++;
    }
    return (dot && *(dot + 1)) ? dot + 1 : 0L;    // return pointer to extension or 0L
}
