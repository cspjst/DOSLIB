/**
* @author      Jeremy Simon Thornton
* @copyright   2026 Jeremy Simon Thornton
*
*/
#ifndef TEST_SERVICES_H
#define TEST_SERVICES_H

#include <stdio.h>
#include <assert.h>

#include "../DOS/dos_services.h"
#include "../DOS/dos_services_tools.h"
#include "../DOS/dos_memory_types.h"
#include "../DOS/dos_services_constants.h"

/* Safe interrupt vectors for testing (60h-67h are user-available in DOS) */
#define TEST_VECTOR_1 0x60
#define TEST_VECTOR_2 0x61

void test_interrupt_vectors(void) {
    printf("Testing DOS vector functions...\n");

    // Save original vectors first (critical for system stability)
    void* orig_vec1 = dos_get_interrupt_vector(TEST_VECTOR_1);
    void* orig_vec2 = dos_get_interrupt_vector(TEST_VECTOR_2);
    printf("save-original ok\n");

    // Set a known handler address, read back, verify round-trip
    void* test_handler1 = (void*)0x1234;
    dos_set_interrupt_vector(TEST_VECTOR_1, test_handler1);
    void* read_back1 = dos_get_interrupt_vector(TEST_VECTOR_1);
    assert(read_back1 == test_handler1);
    printf("round-trip-1 ok\n");

    // Test with different handler
    void* test_handler2 = (void*)0xABCD;
    dos_set_interrupt_vector(TEST_VECTOR_2, test_handler2);
    void* read_back2 = dos_get_interrupt_vector(TEST_VECTOR_2);
    assert(read_back2 == test_handler2);
    printf("round-trip-2 ok\n");

    // NULL handler is valid (points to IRET stub typically)
    dos_set_interrupt_vector(TEST_VECTOR_1, NULL);
    void* null_read = dos_get_interrupt_vector(TEST_VECTOR_1);
    assert(null_read == NULL);
    printf("null-handler ok\n");

    // Restore original vectors (cleanup)
    dos_set_interrupt_vector(TEST_VECTOR_1, orig_vec1);
    dos_set_interrupt_vector(TEST_VECTOR_2, orig_vec2);
    printf("restore-original ok\n");

    // Restore again after far test
    dos_set_interrupt_vector(TEST_VECTOR_1, orig_vec1);
    printf("restore-far ok\n");

    printf("DOS vector functions tests passed\n\n");
}

void test_terminate_process(void) {
    printf("Test DOS Terminate with return code 42 y/n\n");
    char yn = getchar();
    if(yn == 'y') {
        dos_terminate_process_with_return_code(42);
    }
    else {
       printf("Test DOS Terminate function deferred.\n\n");
    }
}

void test_time_date() {
    dos_time_t t1, t2 = {0};
    dos_date_t d1, d2 = {0};
    char time[] = "01234567";
    char date[] = "0123456789";

    dos_get_time(&t1);
    dos_get_date(&d1);
    t2 = t1;
    d2 = d1;
    dos_time_to_str(&t2, time, ':');
    dos_date_to_str(&d2, date, '/');
    printf("%s\n", time);
    printf("%s\n", date);

    t2.hour = 25;
    t2.minutes = 70;
    t2.seconds = 3;
    //assert(dos_set_time(&t2) == DOS_INVALID_DATA);

    t2.hour = 1;
    t2.minutes = 2;
    t2.seconds = 3;
    assert(dos_set_time(&t2) == 0);

    d2.day = 1;
    d2.month = 2;
    d2.year = 0;
    assert(dos_set_date(&d2) == DOS_INVALID_DATA);

    d2.year = 1986;
    assert(dos_set_date(&d2) == 0);

    dos_get_time(&t2);
    dos_get_date(&d2);
    dos_time_to_str(&t2, time, ':');
    dos_date_to_str(&d2, date, '/');
    printf("%s\n", time);
    printf("%s\n", date);

    //assert(dos_set_time(&t1) == 0);
    //assert(dos_set_date(&d1) == 0);
}

void test_mcb() {
    char* mcb = dos_get_first_mcb();
    assert(mcb);

    printf("First MCB @ %p\n", mcb);
    printf("Chain ID: %c\n", mcb[0]);

    printf("Header: ");
    for(int i = 0; i < 16; ++i) {
        unsigned char c = (unsigned char)mcb[i];
        printf("%c", (c >= 32 && c < 127) ? c : '.');
    }
    printf("\n");
    assert(mcb[0]=='M');
}

void test_dos_services(void) {
    test_interrupt_vectors();
    test_terminate_process();
    test_time_date();
    test_mcb();
}

#endif
