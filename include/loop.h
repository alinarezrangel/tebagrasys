/* **********************************************
**********************
*** loop.h: Basic Loop utilities for TEBAGRASYS
**********************
********************************************** */

#if !defined(__TEBAGRASYS_LIB_H__)
#define __TEBAGRASYS_LIB_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "common.h"
#include "mousearea.h"
#include "mousehandler.h"
#include "cursor.h"

TEBAGRASYS_DECLR_BEGIN

/**
* @brief Represents the types of exit events.
* When one of these are throwed, the loop will
* exit.
*/
typedef enum
{
	TEBAGRASYS_EXIT_ON_EOF,
	TEBAGRASYS_EXIT_ON_KEYPRESS,
	TEBAGRASYS_EXIT_ON_CUSTOM,
	TEBAGRASYS_EXIT_ON_ENTER
} tebagrasys_loop_exit_events_enum_t;

typedef
	tebagrasys_error_t (*tebagrasys_loop_oninput_cbk_t)(
		char readedByte
	);

/**
* @brief Represents an event loop.
*/
typedef struct
{
	tebagrasys_cursor_t* cursor;
	tebagrasys_loop_exit_events_enum_t endOn;

	tebagrasys_loop_oninput_cbk_t onInput;
	tebagrasys_bool_t haveOnInput;
} tebagrasys_main_loop_t;

/**
* @brief Creates a new main loop.
*/
tebagrasys_main_loop_t* tebagrasys_main_loop_new(
	tebagrasys_cursor_t* cursor,
	tebagrasys_loop_exit_events_enum_t endOn
);

/**
* @brief Deallocates a main loop.
*/
void tebagrasys_main_loop_dealloc(tebagrasys_main_loop_t* loop);

/**
* @brief Do thing needed in a loop iteration.
*/
tebagrasys_error_t tebagrasys_loop_next(void);

/**
* @brief Do thing needed in a loop iteration.
*/
tebagrasys_error_t tebagrasys_loop_on_click(
	tebagrasys_mouse_event_t* event
);

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_H__ */
