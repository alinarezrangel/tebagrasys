/* **********************************************
**********************
*** mousearea.c: Defines a area when the cursor is enabled
**********************
********************************************** */

#include "mousearea.h"

tebagrasys_mouse_area_t* tebagrasys_mouse_area_new(tebagrasys_pointer_t geo)
{
#if defined(TEBAGRASYS_STRICT_MODE)
	if(geo == NULL)
	{
		errno = EINVAL; // set errno
		return NULL;
	}
#endif
	tebagrasys_mouse_area_t* area =
		(tebagrasys_mouse_area_t*)tebagrasys_malloc(
			sizeof(tebagrasys_mouse_area_t)
		);
	if(area == NULL)
		return NULL;
	area->geometry = geo;
	area->haveOnClick = FALSE;
	area->haveOnHover = FALSE;
	area->haveOnLeave = FALSE;
	area->haveOnMove = FALSE;
	area->haveOnDrag = FALSE;
	area->haveOnDragOver = FALSE;
	return area;
}

void tebagrasys_mouse_area_dealloc(tebagrasys_mouse_area_t* area)
{
	tebagrasys_dealloc(area->geometry);
	tebagrasys_dealloc(area);
}
