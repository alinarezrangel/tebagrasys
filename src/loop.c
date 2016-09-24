/* **********************************************
**********************
*** loop.c: Basic Loop utilities for TEBAGRASYS
**********************
********************************************** */

#include "loop.h"

tebagrasys_main_loop_t* tebagrasys_main_loop_new(
  tebagrasys_cursor_t* cursor,
	tebagrasys_loop_exit_events_enum_t endOn
)
{
	tebagrasys_main_loop_t* loop =
		malloc(sizeof(tebagrasys_main_loop_t));
	loop->haveOnInput = FALSE;
	loop->onInput = NULL;
	loop->cursor = cursor;
	loop->endOn = endOn;
	return loop;
}

void tebagrasys_main_loop_dealloc(tebagrasys_main_loop_t* loop)
{
	tebagrasys_dealloc(loop->cursor);
	tebagrasys_dealloc(loop);
}

tebagrasys_error_t tebagrasys_loop_next(void)
{
	return EXIT_SUCCESS;
}

tebagrasys_error_t tebagrasys_loop_on_click(
	tebagrasys_mouse_event_t* event
)
{
	tebagrasys_mouse_area_controller(event, NULL);
}

