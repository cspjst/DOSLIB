/**
 * @author      Jeremy Simon Thornton
 * @copyright   2024, 2025, 2026 Jeremy Simon Thornton
 *
 * @url https://www.stanislavs.org/helppc/
 * @note all functions return dos_error_code_t the caller should test against DOS_SUCCESS
 * @see dos_perror and dos_strerror in dos_error.h and dos_error_codes.h
 */
#ifndef DOS_MEMORY_SERVICES_H
#define DOS_MEMORY_SERVICES_H

#include "dos_error_types.h"

// 48  Allocate memory blocks
dos_error_code_t dos_allocate_memory_blocks(unsigned short paragraphs, unsigned short* segment);
dos_error_code_t dos_get_free_memory_paragraphs(unsigned short* free);

// 49  Free allocated memory blocks
dos_error_code_t dos_free_allocated_memory_blocks(unsigned short segment);

// 4A  Modify allocated memory blocks

#endif
