/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
*
*/
#ifndef DOS_MEMORY_CONSTANTS_H
#define DOS_MEMORY_CONSTANTS_H

/**
* A paragraph is 16 bytes. Intel made the paragraph size of the x86 16 bytes, or four bits of the physical address.
* (Whether this decision was architectural based on programming paradigms of the time or a simple engineering expediency is debated)
* It's relevant primarily (if not exclusively) in x86 real mode,
* being the distance between two addresses when increment/decrement a *segment* register by one.
*/
#define DOS_PARAGRAPH_SIZE 16UL

/**
* The DOS INT 21,48 - Allocate Memory function takes a 16 bit word size request in paragraphs (ie 16 byte chunks),
* and returns a memory segment address.
* Because the request is a word the maximum number of paragraphs requestable allocate is 0xFFFF, 65535 paragrapghs
* or 65535 x 16 = 1048560 bytes - i.e. 16 bytes, one paragraph, less than 1 Mebibyte (MiB)
* @note 1MiB is the max addressable memory of the original 8086/8088 microprocessor with its 20 address lines 0 - F,FFFF
* 20-bit address bus can address 1,048,576 bytes of memory, it segments it into sixteen 64kB segments.
* Working within those 1,048,576 bytes of memory using its four segment:offset register pairs to address 64KiB chunks.
*/
#define DOS_MAX_ALLOCATE_BYTES 1048560

/**
* MCB - DOS Memory Control Block size 16 bytes ie a paragraph
*/
#define DOS_MCB_SIZE DOS_PARAGRAPH_SIZE

#endif
