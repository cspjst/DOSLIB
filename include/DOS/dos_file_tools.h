/**
 * @author      Jeremy Simon Thornton
 * @copyright   2024 Jeremy Simon Thornton
 *
 * @note functions return dos_error_code_t the caller should test against DOS_SUCCESS
 * @see dos_perror and dos_strerror in dos_error.h and dos_error_codes.h
*/
#ifndef DOS_FILE_TOOLS_H
#define DOS_FILE_TOOLS_H

#include "dos_file_types.h"
#include "dos_error_types.h"

dos_error_code_t dos_file_size(dos_file_handle_t fhandle,  dos_file_size_t* size);

dos_error_code_t dos_file_exists(const char* path_name);

dos_error_code_t dos_file_eof(dos_file_handle_t fhandle);

const char* dos_file_ext(const char* path_name);

dos_file_size_t dos_get_file_size(const char* file_path);

#endif
