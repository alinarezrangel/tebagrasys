/* **********************************************
**********************
*** mousehandler.h: Handles the mouse of GPM
**********************
********************************************** */

#if !defined(__TEBAGRASYS_LIB_MOUSEHANDLER_H__)
#define __TEBAGRASYS_LIB_MOUSEHANDLER_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <gpm.h>

#include "common.h"

TEBAGRASYS_DECLR_BEGIN

/*
Secuences:
mouse move => TEBAGRASYS_MOUSE_MOVE
click => TEBAGRASYS_MOUSE_DOWN + TEBAGRASYS_MOUSE_CLICK ++ TEBAGRASYS_MOUSE_UP
drag => TEBAGRASYS_MOUSE_DOWN + TEBAGRASYS_DRAGGING + TEBAGRASYS_DRAG_END
*/
/**
* @brief Represents the type of a mouse event.
* Is compatible with the GPM mouse events enums.
*/
typedef enum
{
	TEBAGRASYS_MOUSE_MOVE = 1,
	TEBAGRASYS_MOUSE_DOWN = 20,
	TEBAGRASYS_MOUSE_CLICK = 21,
	TEBAGRASYS_MOUSE_UP = 24,
	TEBAGRASYS_DRAGGING = 146,
	TEBAGRASYS_DRAG_END = 152
} tebagrasys_mouse_event_enum_t;

/**
* @brief Is a MouseEvent.
* The original attribute can be NULL.
*/
typedef struct
{
	tebagrasys_mouse_event_enum_t type;
	tebagrasys_screen_size_t x;
	tebagrasys_screen_size_t y;
	Gpm_Event* original;
} tebagrasys_mouse_event_t;

/**
* @brief Converts a Gpm_Event to a tebagrasys_mouse_event_t.
* The resulting event should be deallocated using free.
*/
tebagrasys_mouse_event_t* tebagrasys_gpm_event_to_native_event(Gpm_Event* event);

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_MOUSEHANDLER_H__ */
