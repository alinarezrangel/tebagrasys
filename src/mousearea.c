/* **********************************************
**********************
*** mousearea.c: Defines a area when the cursor is enabled
**********************
********************************************** */

#include "mousearea.h"

tebagrasys_mouse_area_t** tebagrasys_mouse_area_list = NULL;
tebagrasys_size_t tebagrasys_mouse_area_list_length = 0;

tebagrasys_mouse_area_t* tebagrasys_mouse_area_new(
  tebagrasys_pointer_t geo,
  tebagrasys_geometry_controller_havecbk_t cbk
)
{
#if defined(TEBAGRASYS_STRICT_MODE)
	if((geo == NULL) || (cbk == NULL))
	{
		errno = EINVAL; // set errno to invalid argument
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
	area->havePoint = cbk;
	area->haveOnClick = FALSE;
	area->haveOnHover = FALSE;
	area->haveOnLeave = FALSE;
	area->haveOnMove = FALSE;
	area->haveOnDrag = FALSE;
	area->haveOnDragOver = FALSE;
	area->haveOnDown = FALSE;
	area->haveOnUp = FALSE;
	tebagrasys_mouse_area_list =
		(tebagrasys_mouse_area_t**)tebagrasys_realloc(
			tebagrasys_mouse_area_list,
			sizeof(tebagrasys_mouse_area_t*) * tebagrasys_mouse_area_list_length
		);
	if(tebagrasys_mouse_area_list == NULL)
	{
		tebagrasys_mouse_area_dealloc(area);
		return NULL;
	}
	area->index = tebagrasys_mouse_area_list_length;
	tebagrasys_mouse_area_list[tebagrasys_mouse_area_list_length++] =
		area;
	return area;
}

void tebagrasys_mouse_area_dealloc(tebagrasys_mouse_area_t* area)
{
	tebagrasys_size_t i = 0;
  for(i = area->index; i < tebagrasys_mouse_area_list_length; i++)
  {
    tebagrasys_mouse_area_t* ar = tebagrasys_mouse_area_list[i];
		tebagrasys_mouse_area_t* nx = NULL;
		if((i + 1) >= tebagrasys_mouse_area_list_length)
		{
			break;
		}
		*ar = *nx;
  }
	tebagrasys_mouse_area_list =
    (tebagrasys_mouse_area_t**)tebagrasys_realloc(
      tebagrasys_mouse_area_list,
      sizeof(tebagrasys_mouse_area_t*) * (--tebagrasys_mouse_area_list_length)
    );
	tebagrasys_dealloc(area->geometry);
	tebagrasys_dealloc(area);
}

int tebagrasys_mouse_area_controller(tebagrasys_mouse_event_t* e, void *dt)
{
	tebagrasys_size_t i = 0;
	for(i = 0; i < tebagrasys_mouse_area_list_length; i++)
	{
		tebagrasys_mouse_area_t* area = tebagrasys_mouse_area_list[i];
		if(area->havePoint(area->geometry, (tebagrasys_geometry_point_t){e->x, e->y}))
		{
			switch(e->type)
			{
				case TEBAGRASYS_MOUSE_MOVE:
					if(area->haveOnMove)
						area->onMove(e);
					break;
				case TEBAGRASYS_MOUSE_DOWN:
          if(area->haveOnDown)
            area->onDown(e);
          break;
				case TEBAGRASYS_MOUSE_CLICK:
          if(area->haveOnClick)
            area->onClick(e);
          break;
        case TEBAGRASYS_MOUSE_UP:
					if(area->haveOnClick)
						area->onClick(e);
          if(area->haveOnUp)
            area->onUp(e);
          break;
				case TEBAGRASYS_DRAGGING:
          if(area->haveOnDrag)
            area->onDrag(e);
          break;
				case TEBAGRASYS_DRAG_END:
          if(area->haveOnDragOver)
            area->onDragOver(e);
          break;
			}
		}
	}
	return EXIT_SUCCESS;
}
