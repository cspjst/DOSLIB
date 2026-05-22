/**
* @author      Jeremy Simon Thornton
* @copyright   2024 Jeremy Simon Thornton
* @version     0.1.0
*/
#ifndef DOS_SERVICES_FILES_TYPES_H
#define DOS_SERVICES_FILES_TYPES_H

typedef unsigned short dos_file_handle_t;
typedef unsigned short dos_file_attributes_t;
typedef long dos_file_position_t;    // N.B. signed offset
typedef unsigned long dos_file_size_t;

/**
* DOS int 21h, 36h      Get Disk Free Space
*/
typedef struct {
    unsigned short sectors_per_cluster;    // 0FFFFH if the drive number is invalid
    unsigned short available_clusters;
    unsigned short bytes_per_sector;
    unsigned short clusters_per_drive;
} dos_file_disk_space_info_t;

#pragma pack(1)
typedef struct {
    unsigned char   search_attribute;       // 00  attribute of search (undocumented)
    unsigned char   drive;                  // 01  drive used in search (undocumented)
    char            search_name[11];        // 02  search name used (undocumented)
    unsigned short  dir_entry;              // 0D  directory entry number, 0 based (DOS 3.x+, undocumented)
    unsigned short  cluster_3x;             // 0F  starting cluster of current dir, 0=root (DOS 3.x+, undocumented)
    unsigned short  reserved;               // 11  reserved (undocumented)
    unsigned short  cluster_2x;             // 13  starting cluster of current dir, 0=root (DOS 2.x+, undocumented)
    unsigned char   attribute;              // 15  attribute of matching file
    unsigned short  time;                   // 16  file time
    unsigned short  date;                   // 18  file date
    unsigned long   size;                   // 1A  file size
    char            filename[13];           // 1E  ASCIIZ filename NAME.EXT, blanks stripped
} dos_dta_t;
#pragma pack()

#endif
