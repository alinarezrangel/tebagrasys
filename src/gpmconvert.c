/* **********************************************
**********************
*** gpmconvert.c: Convert between GPM and TEBAGRASYS
**********************
********************************************** */

#include "gpmconvert.h"

tebagrasys_mouse_event_t* tebagrasys_gpm_event_to_native_event(Gpm_Event* event)
{
	tebagrasys_mouse_event_t* evt =
		tebagrasys_malloc(sizeof(tebagrasys_mouse_event_t));
	if(evt == NULL)
		return NULL;
	evt->x = event->x;
	evt->y = event->y;
	evt->type = event->type;
	evt->original = event;
	return evt;
}