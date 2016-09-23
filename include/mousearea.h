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
#include <errno.h>
#include <gpm.h>

#include "common.h"
#include "mousehandler.h"
#include "geometry.h"

TEBAGRASYS_DECLR_BEGIN

typedef
	tebagrasys_error_t (*tebagrasys_mouse_area_callback_t)(
		tebagrasys_mouse_event_t*
	);

/**
* @brief Represents an area in the screen than is mouse sensible.
* You can attach events to this area. For this works, need
* to call tebagrasys_main_loop or tebagrasys_loop_now.
*/
typedef struct
{
	tebagrasys_pointer_t geometry;

	tebagrasys_mouse_area_callback_t onClick; // Click event
	tebagrasys_mouse_area_callback_t onMove; // Move event
	tebagrasys_mouse_area_callback_t onHover; // Hover event
	tebagrasys_mouse_area_callback_t onLeave; // Leave event
	tebagrasys_mouse_area_callback_t onDrag; // Drag event
	tebagrasys_mouse_area_callback_t onDragOver; // Drag over event
	tebagrasys_bool_t haveOnClick;
	tebagrasys_bool_t haveOnMove;
	tebagrasys_bool_t haveOnHover;
	tebagrasys_bool_t haveOnLeave;
	tebagrasys_bool_t haveOnDrag;
	tebagrasys_bool_t haveOnDragOver;
} tebagrasys_mouse_area_t;

/**
* @brief Creates a new mousearea.
* The returned data should be deallocated using tebagrasys_mouse_area_dealloc.
*/
tebagrasys_mouse_area_t* tebagrasys_mouse_area_new(tebagrasys_pointer_t geo);
/**
* @brief Deallocates a mousearea.
* If you allocate the same area before using this function,
* the program will not note the difference.
*/
void tebagrasys_mouse_area_dealloc(tebagrasys_mouse_area_t* area);

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_MOUSEAREA_H__ */
