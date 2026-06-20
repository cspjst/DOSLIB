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
* MCB - DOS Memory Control Block size 16 bytes ie a paragraph
*/
#define DOS_MCB_SIZE DOS_PARAGRAPH_SIZE

#endif
