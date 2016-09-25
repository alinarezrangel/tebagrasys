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

/**
* @brief Creates a new cursor.
* Can be deallocated using tebagrasys_cursor_dealloc.
* bs is the cursor representation and can be NULL.
*/
tebagrasys_cursor_t* tebagrasys_cursor_new(const char* bs);

/**
* @brief Deallocates a cursor.
*/
void tebagrasys_cursor_dealloc(tebagrasys_cursor_t* cursor);

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_CURSOR_H__ */
