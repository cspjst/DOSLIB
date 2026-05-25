/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
*
*/
#include "dos_memory_services.h"
#include "../DOS/dos_error_types.h"
#include "../DOS/dos_services_constants.h"
#include "../DOS/dos_error_codes.h"

/**
* @brief INT 21,48 - Allocate Memory
* Allocates a specified number of memory paragraphs.
*
* AH = 48h
* BX = number of memory paragraphs requested
* @note paragraph is a memory unit of size 16 bytes,  relevant primarily (if not exclusively) in x86 real mode
* @url https://en.wikipedia.org/wiki/X86_memory_segmentation
* on return:
* AX = segment address of allocated memory block (MCB + 1para)
*    = error code if CF set  (see DOS ERROR CODES)
* BX = size in paras of the largest block of memory available
*      if CF set, and AX = 08 (Not Enough Mem)
* CF = 0 if successful
*    = 1 if error
*
* Error codes:   7          Memory control blocks destroyed
*                8          Insufficient memory
* @note 1. Call Function 59h for extended error code information (DOS 3.0 and above).
*
* - returns segment address of allocated memory block AX:0000
* - each allocation requires a 16 byte overhead for the MCB
* - returns maximum block size available if error
*
* @note 2. By setting BX=FFFFh before calling, this function can be used to find the amount of
* available memory, which will be returned in BX. (The call will return an error, which can be
* ignored, since DOS cannot allocate more than 640k of memory.)
*
* @see  INT 21,49,  INT 21,4A
*
* @param       number of paragraphs (16 bytes) requested
* @param       segment* pointer to segment variable
* @return      0 on success or error code
*/
dos_error_code_t dos_allocate_memory_blocks(unsigned short paragraphs, unsigned short* segment) {
    if (!segment) return DOS_INVALID_DATA;
    dos_error_code_t ecode = 0;
    __asm {
        .8086
        pushf
        push    ds

        mov     bx, paragraphs              ; number requested paragraphs
        mov     ah, DOS_ALLOCATE_MEMORY_BLOCKS  ; allocate memory
        int     DOS_SERVICE                 ; 48h service
        jnc     OK                          ; success CF = 0
        mov     ecode, ax                ; CF set, and AX = 08 (Not Enough Mem)
        xor     ax, ax
OK:     les     di, segment
        stosw

        pop     ds
        popf
    }
    return ecode;
}

/**
* @brief INT 21,49 - Free Allocated Memory
*
* AH = 49h
* ES = segment of the block to be returned (MCB + 1para)
*
* on return:
* AX = error code if CF set  (see DOS ERROR CODES)
*
* - releases memory and MCB allocated by INT 21,48
* - may cause unpredictable results if memory wasn't allocated using INT 21,48
* or if memory wasn't allocated by the current process
* - checks for valid MCB id, but does NOT check for process ownership care must be
* taken when freeing the memory of another process to assure the segment isn't in use
* by a TSR or ISR
* @note this function is unreliable in a TSR once resident, since COMMAND.COM and many
*  other .COM files take all available memory when they load.
* @see  INT 21,4A
*/
dos_error_code_t dos_free_allocated_memory_blocks(unsigned short segment) {
    if (!segment) return DOS_INVALID_DATA;
    dos_error_code_t ecode = 0;
    __asm {
        .8086
        pushf
        push    ds

        mov     ax, segment                         ; the segment to be released
        mov     es, ax                              ; segment of the block to be returned(MCB + 1para)
        mov     ah, DOS_FREE_ALLOCATED_MEMORY_BLOCKS    ; de-allocate memory
        int     DOS_SERVICE                         ; dos call 49h
        jnc     OK                                  ; success CF = 0
        mov     ecode, ax                        ; de-allocation failed ax is dos error code
    OK:
        pop     ds
        popf
    }
    return ecode;
}

/**
 * Report DOS user available low memory
 * Abuses the DOS dos_allocate_memory_blocks function by forcing an error.
 * By setting BX=FFFFh before calling, this function can be used to find the amount of
 * available memory, which will be returned in BX. (The call will return an error, which can be
 * ignored, since DOS cannot allocate more than 640k of memory.)
 */
dos_error_code_t dos_get_free_memory_paragraphs(unsigned short* free) {
    if (!free) return DOS_INVALID_DATA;
    dos_error_code_t ecode = 0;
    __asm {
        .8086
        pushf
        push    ds

        mov     bx, 0FFFFh                  ; number requested paragraphs
        mov     ah, DOS_ALLOCATE_MEMORY_BLOCKS  ; allocate memory
        int     DOS_SERVICE                 ; 48h service
        mov     ecode, ax                ; CF set, and AX = 08 (Not Enough Mem)
        les     di, free
        mov     es:[di], bx                ; size in paras of the largest block of low memory available

        pop     ds
        popf
    }
    // Treat "insufficient memory" as success for this query hack
    if (ecode == DOS_INSUFFICIENT_MEMORY) {
        return DOS_SUCCESS;
    }
    return ecode;
}
