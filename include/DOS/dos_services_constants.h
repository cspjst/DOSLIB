/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
*
*/
#ifndef DOS_SERVICES_CONSTANTS_H
#define DOS_SERVICES_CONSTANTS_H

#define DOS_SERVICE                                         0x21

#define DOS_ERROR                                           0xFFFF

// DOS SERVICES AH FOR 0x21
#define DOS_PROGRAM_TERMINATE                               0x00
#define DOS_KEYBOARD_INPUT_WITH_ECHO                        0x01
#define DOS_DISPLAY_OUTPUT                                  0x02
#define DOS_WAIT_FOR_AUXILIARY_DEVICE_INPUT                 0x03
#define DOS_AUXILIARY_OUTPUT                                0x04
#define DOS_PRINTER_OUTPUT                                  0x05
#define DOS_DIRECT_CONSOLE_IO                               0x06
#define DOS_WAIT_FOR_DIRECT_CONSOLE_INPUT_WITHOUT_ECHO      0x07
#define DOS_WAIT_FOR_CONSOLE_INPUT_WITHOUT_ECHO             0x08
#define DOS_PRINT_STRING                                    0x09
#define DOS_BUFFERED_KEYBOARD_INPUT                         0x0A
#define DOS_CHECK_STANDARD_INPUT_STATUS                     0x0B
#define DOS_CLEAR_KEYBOARD_BUFFER                           0x0C
#define DOS_DISK_RESET                                      0x0D
#define DOS_SELECT_DISK                                     0x0E
#define DOS_OPEN_FILE_USING_FCB                             0x0F
#define DOS_CLOSE_FILE_USING_FCB                            0x10
#define DOS_SEARCH_FOR_FIRST_ENTRY_USING_FCB                0x11
#define DOS_SEARCH_FOR_NEXT_ENTRY_USING_FCB                 0x12
#define DOS_DELETE_FILE_USING_FCB                           0x13
#define DOS_SEQUENTIAL_READ_USING_FCB                       0x14
#define DOS_SEQUENTIAL_WRITE_USING_FCB                      0x15
#define DOS_CREATEFILE_USING_FCB                            0x16
#define DOS_RENAME_FILE_USING_FCB                           0x17
#define DOS_DOS_DUMMY_FUNCTION_1                            0x18    // CP/M_NOT_USED/LISTED
#define DOS_GET_CURRENT_DEFAULT_DRIVE                       0x19
#define DOS_SET_DISK_TRANSFER_ADDRESS                       0x1A
#define DOS_GET_ALLOCATION_TABLE_INFORMATION                0x1B
#define DOS_GET_ALLOCATION_TABLE_INFO_FOR_SPECIFIC_DEVICE   0x1C
#define DOS_DOS_DUMMY_FUNCTION_2                            0x1D    // CP/M_NOT_USED/LISTED
#define DOS_DOS_DUMMY_FUNCTION_3                            0x1E    // CP/M_NOT_USED/LISTED
#define DOS_GET_POINTER_TO_DEFAULT_DRIVE_PARAMETER_TABLE    0x1F    // UNDOCUMENTED
#define DOS_DOS_DUMMY_FUNCTION_4                            0x20    // CP/M_NOT_USED/LISTED
#define DOS_RANDOM_READ_USING_FCB                           0x21
#define DOS_RANDOM_WRITE_USING_FCB                          0x22
#define DOS_GET_FILE_SIZE_USING_FCB                         0x23
#define DOS_SET_RELATIVE_RECORD_FIELD_FOR_FCB               0x24
#define DOS_SET_INTERRUPT_VECTOR                            0x25
#define DOS_CREATE_NEW_PROGRAM_SEGMENT                      0x26
#define DOS_RANDOM_BLOCK_READ_USING_FCB                     0x27
#define DOS_RANDOM_BLOCK_WRITE_USING_FCB                    0x28
#define DOS_PARSE_FILENAME_FOR_FCB                          0x29
#define DOS_GET_DATE                                        0x2A
#define DOS_SET_DATE                                        0x2B
#define DOS_GET_TIME                                        0x2C
#define DOS_SET_TIME                                        0x2D
#define DOS_TOGGLE_VERIFY_SWITCH                            0x2E
#define DOS_GET_DISK_TRANSFER_ADDRESS                       0x2F
#define DOS_GET_DOS_VERSION_NUMBER                          0x30
#define DOS_TERMINATE_PROCESS_AND_REMAIN_RESIDENT           0x31
#define DOS_GET_POINTER_TO_DRIVE_PARAMETER_TABLE            0x32    // UNDOCUMENTED
#define DOS_GET_SET_CTRL                                    0x33
#define DOS_GET_ADDRESS_TO_DOS_CRITICAL_FLAG                0x34    // UNDOCUMENTED
#define DOS_GET_INTERRUPT_VECTOR                            0x35
#define DOS_GET_DISK_FREE_SPACE                             0x36
#define DOS_GET_SET_SWITCH_CHARACTER                        0x37    // UNDOCUMENTED
#define DOS_GET_SET_COUNTRY_DEPENDENT_INFORMATION           0x38
#define DOS_CREATE_SUBDIRECTORY                             0x39
#define DOS_REMOVE_SUBDIRECTORY                             0x3A
#define DOS_CHANGE_CURRENT_SUBDIRECTORY                     0x3B
#define DOS_CREATE_FILE_USING_HANDLE                        0x3C
#define DOS_OPEN_FILE_USING_HANDLE                          0x3D
#define DOS_CLOSE_FILE_USING_HANDLE                         0x3E
#define DOS_READ_FILE_OR_DEVICE_USING_HANDLE                0x3F
#define DOS_WRITE_FILE_OR_DEVICE_USING_HANDLE               0x40
#define DOS_DELETE_FILE                                     0x41
#define DOS_MOVE_FILE_POINTER_USING_HANDLE                  0x42
#define DOS_FILE_ATTRIBUTES                                 0x43
#define DOS_IO_CONTROL_FOR_DEVICES                          0x44
#define DOS_DUPLICATE_FILE_HANDLE                           0x45
#define DOS_FORCE_DUPLICATE_FILE_HANDLE                     0x46
#define DOS_GET_CURRENT_DIRECTORY                           0x47
#define DOS_ALLOCATE_MEMORY_BLOCKS                          0x48
#define DOS_FREE_ALLOCATED_MEMORY_BLOCKS                    0x49
#define DOS_MODIFY_ALLOCATED_MEMORY_BLOCKS                  0x4A
#define DOS_EXEC_LOAD_AND_EXECUTE_PROGRAM                   0x4B
#define DOS_TERMINATE_PROCESS_WITH_RETURN_CODE              0x4C
#define DOS_GET_RETURN_CODE_OF_SUB_PROCESS                  0x4D
#define DOS_FIND_FIRST_MATCHING_FILE                        0x4E
#define DOS_FIND_NEXT_MATCHING_FILE                         0x4F
#define DOS_SET_CURRENT_PROCESS_ID                          0x50    // UNDOCUMENTED
#define DOS_GET_CURRENT_PROCESS_ID                          0x51    // UNDOCUMENTED
#define DOS_GET_POINTER_TO_DOS_INVARS                       0x52    // UNDOCUMENTED
#define DOS_GENERATE_DRIVE_PARAMETER_TABLE                  0x53    // UNDOCUMENTED
#define DOS_GET_VERIFY_SETTING                              0x54
#define DOS_CREATE_PSP                                      0x55    // UNDOCUMENTED
#define DOS_RENAME_FILE                                     0x56
#define DOS_GET_SET_FILE_DATE_AND_TIME_USING_HANDLE         0x57
#define DOS_GET_SET_MEMORY_ALLOCATION_STRATEGY              0x58    // 3.X + UNDOCUMENTED
#define DOS_GET_EXTENDED_ERROR_INFORMATION                  0x59    // 3.X +
#define DOS_CREATE_TEMPORARY_FILE                           0x5A    // 3.X +
#define DOS_CREATE_NEW_FILE                                 0x5B    // 3.X +
#define DOS_LOCK_UNLOCK_FILE_ACCESS                         0x5C    // 3.X +
#define DOS_CRITICAL_ERROR_INFORMATION                      0x5D    // UNDOCUMENTED
#define DOS_NETWORK_SERVICES                                0x5E    // 3.1 +
#define DOS_NETWORK_REDIRECTION                             0x5F    // 3.1 +
#define DOS_GET_FULLY_QUALIFIED_FILE_NAME                   0x60    // UNDOCUMENTED
// 0x61 reserved
#define DOS_GET_ADDRESS_OF_PROGRAM_SEGMENT_PREFIX           0x62    // 3.X +
#define DOS_GET_SYSTEM_LEAD_BYTE_TABLE                      0x63    // MSDOS_2.25_ONLY
#define DOS_SET_DEVICE_DRIVER_LOOK_AHEAD                    0x64    // UNDOCUMENTED
#define DOS_GET_EXTENDED_COUNTRY_INFORMATION                0x65    // 3.3 +
#define DOS_GET_SET_GLOBAL_CODE_PAGE                        0x66    // 3.3 +
#define DOS_SET_HANDLE_COUNT                                0x67    // 3.3 +
#define DOS_FLUSH_BUFFER                                    0x68    // 3.3 +
#define DOS_GET_SET_DISK_SERIAL_NUMBER                      0x69    // UNDOCUMENTED

// SOFTWARE INTERRUPT NUMBERS
#define IDIVIDE_BY_ZERO                                     0
#define ISINGLE_STEP                                        1
#define INONMASKABLE                                        2
#define IBREAKPOINT                                         3
#define IOVERFLOW                                           4
#define IPRINT_SCREEN                                       5
#define ISYSTEM_TIMER                                       8
#define IKEYBOARD                                           9
#define IDISKETTE                                           14
#define IVIDEO                                              16
#define IEQUIPMENT_DETERMINATION                            17

// Undocumented table of pointers used by DOS (varies with DOS version)
#define DOS_INVARS_MCB                                      -2      // word   segment of first Memory Control Block (MCB)

#endif
