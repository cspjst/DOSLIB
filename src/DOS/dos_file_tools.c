/**
* @author      Jeremy Simon Thornton
* @copyright   2024 Jeremy Simon Thornton
*/
#include "dos_file_tools.h"
#include "dos_error.h"
#include "dos_error_types.h"
#include "dos_error_codes.h"
#include "dos_file_services.h"
#include "dos_file_types.h"
#include "dos_file_constants.h"

#include <string.h>
#include <stddef.h>

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

dos_error_code_t dos_file_exists(const char* path_name) {
    dos_file_attributes_t attr;
    return dos_get_file_attributes(path_name, &attr);
}

dos_error_code_t dos_file_eof(dos_file_handle_t fhandle) {
    dos_file_position_t i, j = 0;
    dos_error_code_t e;
    e = dos_move_file_pointer(fhandle, 0, FSEEK_CUR, &i);       // save current position
    if(e) return e;
    e = dos_move_file_pointer(fhandle, 0, FSEEK_END, &j);       // get file size (seek to end)
    if(e) return e;
    e = dos_move_file_pointer(fhandle, i, FSEEK_SET, NULL);     // restore original position
    if(e) return e;
    return i == j ? DOS_SUCCESS : DOS_INVALID_ENVIRONMENT;
}

const char* dos_file_ext(const char* path_name) {
    if (!path_name || !path_name[0]) return NULL;
    return strrchr(path_name, '.');
}

dos_file_size_t dos_get_file_size(const char* file_path) {
    dos_error_code_t e;
    dos_file_handle_t f;
    dos_file_size_t sz;
    e = dos_open_file(file_path, ATTR_READ_ONLY, &f);
    if(e) { dos_perror(__FUNCTION__, e); return 0; }
    e = dos_file_size(f, &sz);
    if(e) { dos_perror(__FUNCTION__, e); return 0; }
    e = dos_close_file(f);
    if(e) { dos_perror(__FUNCTION__, e); return 0; }
    return sz;
}
