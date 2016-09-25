/* **********************************************
**********************
*** gpmloop.c: Main Loop Utilities for GPM
**********************
********************************************** */

#include "gpmloop.h"

tebagrasys_geometry_point_t tebagrasys_gpm_lastCursorPosition = {0, 0};
tebagrasys_main_loop_t** tebagrasys_gpm_mainLoop = NULL;

int tebagrasys_gpm_loop_mouse_event(Gpm_Event* ev, void* dt)
{
	tebagrasys_mouse_event_t* event = tebagrasys_gpm_event_to_native_event(ev);
	char* str = NULL;
	tebagrasys_size_t i = 0, bsl = 0;
	if(event == NULL)
	{
		return 1;
	}
#if !defined(NOT_USE_ANSI)
	bsl = (*tebagrasys_gpm_mainLoop)->cursor->byteSecLength;
	str =
		tebagrasys_malloc(
			sizeof(char) * (bsl + 1)
		);
	if(str == NULL)
	{
		return 1;
	}
	for(i = 0; i < bsl; i++)
	{
		str[i] = ' ';
	}
	str[bsl] = '\0';
#endif
	tebagrasys_loop_on_click(event);
#if !defined(NOT_USE_ANSI)
	printf(
		"\033[%d;%dH%s",
		tebagrasys_gpm_lastCursorPosition.y,
		tebagrasys_gpm_lastCursorPosition.x,
		str
	);
	printf(
    "\033[%d;%dH%s",
    event->y,
    event->x,
    (*tebagrasys_gpm_mainLoop)->cursor->byteSec
  );
	fflush(stdout);
	tebagrasys_gpm_lastCursorPosition.x = event->x;
	tebagrasys_gpm_lastCursorPosition.y = event->y;
#endif
	tebagrasys_dealloc(event);
	return 0;
}

tebagrasys_error_t tebagrasys_main_loop_do_gpm(
	tebagrasys_main_loop_t* loop
)
{
	if(loop == NULL)
		return EXIT_FAILURE;
	Gpm_Connect conn;
	char c = '\0';

	conn.eventMask = ~0;
	conn.defaultMask = 0;
	conn.minMod = 0;
	conn.maxMod = ~0;

	tebagrasys_gpm_mainLoop = &loop;

	gpm_handler = tebagrasys_gpm_loop_mouse_event;

	if(Gpm_Open(&conn, 0) < 0)
	{
		return EXIT_FAILURE;
	}
	while((c = Gpm_Getc(stdin)) != EOF)
	{
		tebagrasys_loop_next();
		if(loop->haveOnInput)
			(*loop->onInput)(c);
	}
	Gpm_Close();
	return EXIT_SUCCESS;
}

