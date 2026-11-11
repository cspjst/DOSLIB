#ifndef DOS_VERSION_H
#define DOS_VERSION_H

#define DOS_VERSION_MAJOR  0
#define DOS_VERSION_MINOR  8
#define DOS_VERSION_PATCH  5

/**
 * single comparable value: 0xMMmm (major high byte, minor low byte)
 * matches the way DOS reports its own version (major in AH, minor in AL)
 */
#define DOS_VERSION        ((DOS_VERSION_MAJOR << 8) | DOS_VERSION_MINOR)

#define DOS_VERSION_STRING "0.8.5"

/**
* @brief   Version of DOS.LIB as built.
*
* Packed as 0xMMmm: major in the high byte, minor in the low byte.
* Compare with the DOS_VERSION macro to detect a header/library mismatch.
*/
unsigned int dos_version();

/**
* @brief   Full version string of DOS.LIB as built, e.g. "1.2.3".
*
* Includes the patch number, which dos_version() omits.
*/
const char* dos_version_string();

#endif
