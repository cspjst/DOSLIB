/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
*
*/
#ifndef DOS_EERROR_CODES_H
#define DOS_EERROR_CODES_H
/**
* Classic 12h codes
*/
#define DOS_SUCCESS                                0
#define DOS_INVALID_FUNCTION_NUMBER                1
#define DOS_FILE_NOT_FOUND                         2
#define DOS_PATH_NOT_FOUND                         3
#define DOS_TOO_MANY_OPEN_FILES                    4
#define DOS_ACCESS_DENIED                          5
#define DOS_INVALID_HANDLE                         6
#define DOS_MCB_DESTROYED                          7
#define DOS_INSUFFICIENT_MEMORY                    8
#define DOS_INVALID_MEMORY_BLOCK_ADDRESS           9
#define DOS_INVALID_ENVIRONMENT                    10
#define DOS_INVALID_FORMAT                         11
#define DOS_INVALID_ACCESS_MODE                    12
#define DOS_INVALID_DATA                           13
#define DOS_RESERVED                               14
#define DOS_INVALID_DRIVE_SPECIFIED                15
#define DOS_ATTEMPT_TO_REMOVE_CURRENT_DIRECTORY    16
#define DOS_NOT_SAME_DEVICE                        17
#define DOS_NO_MORE_FILES                          18
#endif
