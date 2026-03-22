/**
* @author      Jeremy Simon Thornton
* @copyright   2024 Jeremy Simon Thornton
* @version     0.1.0
*/
#ifndef DOS_MEMORY_TYPES_H
#define DOS_MEMORY_TYPES_H

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

#endif
