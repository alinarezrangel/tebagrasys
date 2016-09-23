/* **********************************************
**********************
*** mousearea.h: Defines a area when the cursor is enabled
**********************
********************************************** */

#if !defined(__TEBAGRASYS_LIB_MOUSEAREA_H__)
#define __TEBAGRASYS_LIB_MOUSEAREA_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <gpm.h>

#include "common.h"
#include "mousehandler.h"
#include "geometry.h"

TEBAGRASYS_DECLR_BEGIN

typedef struct
{
	tebagrasys_screen_size_t startX;
	tebagrasys_screen_size_t startY;
	tebagrasys_screen_size_t sizeX;
	tebagrasys_screen_size_t sizeY;
} tebagrasys_mouse_area_t;
// Inherits tebagrasys_geometry_rectangle_t

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_MOUSEAREA_H__ */
