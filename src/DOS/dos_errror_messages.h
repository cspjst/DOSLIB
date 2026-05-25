/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
*
*/
#ifndef DOS_ERROR_MESSAGES_H
#define DOS_ERROR_MESSAGES_H

static const char* const DOS_ERROR_STRINGS[] = {
    "Success",                              // 0  DOS_SUCCESS
    "Invalid function number",              // 1  DOS_INVALID_FUNCTION_NUMBER
    "File not found",                       // 2  DOS_FILE_NOT_FOUND
    "Path not found",                       // 3  DOS_PATH_NOT_FOUND
    "Too many open files",                  // 4  DOS_TOO_MANY_OPEN_FILES
    "Access denied",                        // 5  DOS_ACCESS_DENIED
    "Invalid handle",                       // 6  DOS_INVALID_HANDLE
    "Memory control block destroyed",       // 7  DOS_MCB_DESTROYED
    "Insufficient memory",                  // 8  DOS_INSUFFICIENT_MEMORY
    "Invalid memory block address",         // 9  DOS_INVALID_MEMORY_BLOCK_ADDRESS
    "Invalid environment",                  // 10 DOS_INVALID_ENVIRONMENT
    "Invalid format",                       // 11 DOS_INVALID_FORMAT
    "Invalid access mode",                  // 12 DOS_INVALID_ACCESS_MODE
    "Invalid data",                         // 13 DOS_INVALID_DATA
    "Reserved",                             // 14 DOS_RESERVED
    "Invalid drive specified",              // 15 DOS_INVALID_DRIVE_SPECIFIED
    "Attempt to remove current directory",  // 16 DOS_ATTEMPT_TO_REMOVE_CURRENT_DIRECTORY
    "Not same device",                      // 17 DOS_NOT_SAME_DEVICE
    "No more files"                         // 18 DOS_NO_MORE_FILES
};

#endif
