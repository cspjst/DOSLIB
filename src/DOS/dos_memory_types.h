/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
*
*/
#ifndef DOS_MEMORY_TYPES_H
#define DOS_MEMORY_TYPES_H

// NB 8086 20-bit address bus can address 1,048,576 bytes of memory
typedef unsigned long dos_memsize_t;

typedef union {
    unsigned short word;
    unsigned char bytes[2];
} dos_word_t;

#pragma pack(1)
typedef struct {
    unsigned short offset;
    unsigned short segment;   // N.B. reverse order as Intel is little-endian
} dos_segoff_t;
#pragma pack()

typedef union {
    void* ptr;
    unsigned long memloc;
    dos_segoff_t segoff;
    unsigned short words[2];
    unsigned char bytes[4];
} dos_address_t;

typedef struct {
    dos_address_t begin;
    dos_address_t end;
} dos_mem_block_t;

/**
 * MCB Fields
 *  Address     Memory Control Blaock Fields
 *              Chain ID    PID     size    unused
 *  yyy0:000       0        1-2     3-4     5-15
 *
 * ID = MCB chain-identification byte.
 * Its value is Z for the last MCB in DOS MCB chain and M otherwise
 *
 * PID  = Process ID, or the program segment prefix of the program
 * that "owns" the MCB and the memory it controls.
 * size = Size of the contiguous block of memeory controlled by the
 * MCB in units of paragraphs.
 * @note It does not include the MCB itself.
 */
#pragma pack(1)
typedef struct {
    unsigned char chain_id;     // 'Z' for last, 'M' otherwise
    unsigned short pid;         // Process ID (PSP segment)
    unsigned short block_size;  // Size in paragraphs (16-byte units)
    unsigned char reserved[11]; // Unused/reserved bytes
} dos_mcb_t;
#pragma pack()

#endif
