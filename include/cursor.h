/* **********************************************
**********************
*** cursor.h: Basic Cursor Handling
**********************
********************************************** */

#if !defined(__TEBAGRASYS_LIB_CURSOR_H__)
#define __TEBAGRASYS_LIB_CURSOR_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "common.h"
#include "geometry.h"

TEBAGRASYS_DECLR_BEGIN

/**
* @brief Represents a cursor in the screen.
*/
typedef struct
{
	tebagrasys_geometry_point_t position;
	char* byteSec;
	tebagrasys_size_t byteSecLength;
} tebagrasys_cursor_t;

tebagrasys_cursor_t* tebagrasys_cursor_new(const char* bs);

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_CURSOR_H__ */
