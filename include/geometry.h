/* **********************************************
**********************
*** geometry.h: Defines geometry types
**********************
********************************************** */

#if !defined(__TEBAGRASYS_LIB_GEOMETRY_H__)
#define __TEBAGRASYS_LIB_GEOMETRY_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <gpm.h>

#include "common.h"

TEBAGRASYS_DECLR_BEGIN

typedef struct
{
	tebagrasys_screen_size_t startX;
	tebagrasys_screen_size_t startY;
	tebagrasys_screen_size_t sizeX;
	tebagrasys_screen_size_t sizeY;
} tebagrasys_geometry_rectangle_t;

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_GEOMETRY_H__ */
