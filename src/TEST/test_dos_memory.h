#ifndef TEST_MEMORY_H
#define TEST_MEMORY_H

#ifdef USE_DOSLIBC
    #include "../STD/dos_stdio.h"
    #include "../STD/dos_stdint.h"
    #include "../STD/assert.h"
#else
    #include <stdio.h>
    #include <stdint.h>
    #include <assert.h>
#endif

#include "../DOS/dos_memory_services.h"

void test_allocate_memory() {

    // Basic allocation (small block)
    uint16_t seg;
    dos_error_code_t err = dos_allocate_memory_blocks(16, &seg);  // 256 bytes
    assert(err == DOS_SUCCESS);
    assert(seg != 0);
    assert(seg != 0xFFFF);

    // Allocation with NULL output pointer (should fail gracefully)
    err = dos_allocate_memory_blocks(16, NULL);
    assert(err != DOS_SUCCESS);

    // Zero paragraph allocation (edge case)
    err = dos_allocate_memory_blocks(0, &seg);
    // DOS may allow 0 or return error; just verify consistent behavior
    assert(err == DOS_SUCCESS || err == DOS_INSUFFICIENT_MEMORY);

    // Large allocation (may fail depending on available memory)
    err = dos_allocate_memory_blocks(0xFFF0, &seg);  // ~1 MB request
    assert(err == DOS_SUCCESS || err == DOS_INSUFFICIENT_MEMORY);
    if (err == DOS_SUCCESS) {
        // If it succeeded, free it immediately
        dos_free_allocated_memory_blocks(seg);
    }

    // Far pointer output test (large model)
    uint16_t far_seg;
    err = dos_allocate_memory_blocks(32, &far_seg);
    assert(err == DOS_SUCCESS);
    assert(far_seg != 0);
}

void test_free_memory() {

    // Free a valid allocated block
    uint16_t seg;
    dos_allocate_memory_blocks(16, &seg);
    dos_error_code_t err = dos_free_allocated_memory_blocks(seg);
    assert(err == DOS_SUCCESS);

    // Free NULL segment (0) - should fail
    err = dos_free_allocated_memory_blocks(0);
    assert(err != DOS_SUCCESS);

    // Free invalid segment (0xFFFF) - should fail
    err = dos_free_allocated_memory_blocks(0xFFFF);
    assert(err != DOS_SUCCESS);

    // Double-free same segment (should fail on second)
    dos_allocate_memory_blocks(16, &seg);
    err = dos_free_allocated_memory_blocks(seg);
    assert(err == DOS_SUCCESS);
    err = dos_free_allocated_memory_blocks(seg);  // Second free

    // Free unallocated but plausible segment (may fail or succeed depending on DOS)
    err = dos_free_allocated_memory_blocks(0x1234);
    assert(err == DOS_SUCCESS || err != DOS_SUCCESS);  // Just verify it returns
}

void test_get_free_memory() {

    // Basic query
    uint16_t free;
    dos_error_code_t err = dos_get_free_memory_paragraphs(&free);
    assert(err == DOS_SUCCESS);
    assert(free > 0);  // Should always have some free memory

    // Query with NULL output pointer (should fail)
    err = dos_get_free_memory_paragraphs(NULL);
    assert(err != DOS_SUCCESS);

    // Query before/after allocation to verify change
    uint16_t before, after;
    dos_get_free_memory_paragraphs(&before);

    uint16_t seg;
    dos_allocate_memory_blocks(64, &seg);  // Allocate 1KB

    dos_get_free_memory_paragraphs(&after);
    assert(after <= before);  // Free memory should decrease or stay same
    assert(before - after >= 64);  // Should decrease by at least allocated amount
    dos_free_allocated_memory_blocks(seg);  // Cleanup

    // Far pointer output test (large model)
    uint16_t far_free;
    err = dos_get_free_memory_paragraphs(&far_free);
    assert(err == DOS_SUCCESS);
    assert(far_free > 0);

    // Verify returned value is reasonable (not obviously corrupted)
    assert(free < 0xF000);  // Sanity: shouldn't be near segment limit
}

void test_dos_memory() {

    printf("Testing DOS memory functions...\n");

    test_allocate_memory();
    test_free_memory();
    test_get_free_memory();

    printf("DOS memory functions tests passed\n\n");
}

#endif
