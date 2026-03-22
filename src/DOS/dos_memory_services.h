/**
 * @url https://www.stanislavs.org/helppc/
 */
#ifndef DOS_MEMORY_SERVICES_H
#define DOS_MEMORY_SERVICES_H

#include "dos_error_types.h"
#include "dos_memory_constants.h"
#include "dos_memory_types.h"

dos_error_code_t dos_allocate_memory_blocks(unsigned short paragraphs, unsigned short* segment);

dos_error_code_t dos_free_allocated_memory_blocks(unsigned short segment);

dos_error_code_t dos_get_free_memory_paragraphs(unsigned short* free);

#endif
