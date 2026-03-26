/**
* @author      Jeremy Simon Thornton
* @copyright   2024 Jeremy Simon Thornton
* @version     0.1.0
*/
#include "dos_services.h"
#include "dos_services_types.h"
#include "dos_services_constants.h"
#include "dos_error_types.h"

/**
* @brief Provides a safe method for changing interrupt vectors
* @note returns nothing
* INT 21,25 - Set Interrupt Vector
* AH = 25h
* AL = interrupt number
* DS:DX = pointer to interrupt handler
*/
void dos_set_interrupt_vector(unsigned char vec_num, void* phandler) {
    __asm {
        .8086
        pushf                                ; preserve what int 21h may not
        push    ds                           ; due to unreliable behaviour

        lds     dx, phandler                ; copy pointer to handler into DS:DX
        mov     al, vec_num                 ; interrupt vector number
        mov     ah, DOS_SET_INTERRUPT_VECTOR    ; 25h service
        int     DOS_SERVICE

        pop     ds
        popf
    }
}

/**
* @brief Standard method for retrieving interrupt vectors
* INT 21,35 - Get Interrupt Vector
* AH = 35h
* AL = interrupt vector number
* on return:
* ES:BX = pointer to interrupt handler.
*
* @param vec_num
* @return void* segment:offset pointer to interrupt handler
*/
void* dos_get_interrupt_vector(unsigned char vec_num) {
    void* phandler = 0;
    __asm {
        .8086
        pushf
        push    ds

        mov     al, vec_num                 ; interrupt vector number
        mov     ah, DOS_GET_INTERRUPT_VECTOR    ; 35h service
        int     DOS_SERVICE
        lea     di, phandler
        mov     [di], bx                    ; copy segment into address_t (little endian)
        mov     [di + 2] , es               ; copy offset

        pop     ds
        popf
    }
    return phandler;
}

/**
 * @brief INT 21,4C - Terminate Process With Return Code
 *
 * AH = 4C
 * AL = return code (for batch files)
 * returns nothing
 * - approved method of program termination
 * - restores the terminate, Ctrl-Break, and critical error exit
 * 	 addresses, flushes all buffers, frees memory and returns to
 * 	 DOS via the termination handler address
 * - does not close FCBs
 * - this function is not supported in versions of DOS before 2.x
 */
void dos_terminate_process_with_return_code(unsigned char return_code) {
    __asm {
        .8086
        mov     al, return_code
        mov     ah, DOS_TERMINATE_PROCESS_WITH_RETURN_CODE
        int     DOS_SERVICE
        // program ends here - no return
    }
}

/**
 * @brief INT 21,2A - Get Date - retrieves system date based on the DOS maintained clock
 * @note updates BIOS Data Area current date and date rollover flag at location 40:70
 *
 * AH = 2A
 * on return:
 * AL = day of the week (0=Sunday)
 * CX = year (1980-2099)
 * DH = month (1-12)
 * DL = day (1-31)
 */
void dos_get_date(dos_date_t* date) {
    __asm {
        .8086
        pushf                               ; preserve what int 21h may not
        push    ds                          ; due to unreliable behaviour

        mov     ah, DOS_GET_DATE
        int     DOS_SERVICE
        les     di, date                    ; copy pointer to date into ES:DI
        stosb                               ; fill the date struct...
        mov     [di], cx
        mov     [di + 2], dh
        mov     [di + 3], dl

        pop     ds
        popf
    }
}

/**
 * @brief INT 21,2B - Set Date - sets DOS maintained clock
 * @note DOS versions 3.3+ also update the CMOS date where applicable
 *
 * typedef struct {
 *  unsigned char   dotw;   // AL = day of the week (0=Sunday)
 * 	unsigned short  year;   // CX = year (1980-2099)
 * 	unsigned char   month;  // DH = month (1-12)
 * 	unsigned char   day;    // DL = day (1-31)
 * } dos_date_t;
 *
 * AH = 2B
 * CX = year (1980-2099)
 * DH = month (1-12)
 * DL = day (1-31)
 * on return:
 * AL = 00 if date change successful
 *    = FF if invalid date
 */
dos_error_code_t dos_set_date(const dos_date_t* date) {
    dos_error_code_t errno = DOS_INVALID_DATA;
    __asm {
        .8086
        pushf                               ; preserve what int 21h may not
        push    ds                          ; due to unreliable behaviour

        les     di, date                    ; copy pointer to date into ES:DI
        mov     cx, [di + 1]                ; copy the data struct...
        mov     dh, [di + 3]
        mov     dl, [di + 4]
        mov     ah, DOS_SET_DATE
        int     DOS_SERVICE
        test    al, al                      ; AL = 00 if date change successful
        jnz     END
        mov     errno, 0

 END:   pop     ds
        popf
    }

    return errno;
}

/**
 * @brief INT 21,2C - Get Time - retrieves DOS maintained clock time
 *
 * AH = 2C
 * on return:
 * CH = hour (0-23)
 * CL = minutes (0-59)
 * DH = seconds (0-59)
 * DL = hundredths (0-99)
 */
void dos_get_time(dos_time_t* date) {

}

/**
 * @brief
 * INT 21,2D - Set Time - changes DOS maintained clock
 * @note DOS version 3.3+ also update CMOS clock where applicable
 *
 * AH = 2D
 * CH = hour (0-23)
 * CL = minutes (0-59)
 * DH = seconds (0-59)
 * DL = hundredths (0-99)
 * on return:
 * AL = 00 if time change successful
 *    = FF if time invalid
 */
dos_error_code_t dos_set_time(const dos_time_t* date) {
    dos_error_code_t errno = 0;

    return errno;
}
