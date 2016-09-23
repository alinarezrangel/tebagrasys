/* **********************************************
**********************
*** mousehandler.c: Handles the mouse of GPM
**********************
********************************************** */

#include "mousehandler.h"

tebagrasys_mouse_event_t* tebagrasys_gpm_event_to_native_event(Gpm_Event* event)
{
	tebagrasys_mouse_event_t* evt =
		(tebagrasys_mouse_event_t*)tebagrasys_malloc(sizeof(tebagrasys_mouse_event_t));
	if(evt == NULL)
		return NULL;
	evt->x = event->x;
	evt->y = event->y;
	evt->type = event->type;
	evt->original = event;
	return evt;
}
