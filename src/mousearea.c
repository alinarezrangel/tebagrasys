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
		tebagrasys_malloc(
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
	area->mouseIsIn = FALSE;
	tebagrasys_mouse_area_list =
		tebagrasys_realloc(
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
    tebagrasys_realloc(
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
			if((!area->mouseIsIn) && (area->haveOnHover))
			{
				(*area->onHover)(e);
				area->mouseIsIn = TRUE;
			}
			switch(e->type)
			{
				case TEBAGRASYS_MOUSE_MOVE:
					if(area->haveOnMove)
						(*area->onMove)(e);
					break;
				case TEBAGRASYS_MOUSE_DOWN:
          if(area->haveOnDown)
            (*area->onDown)(e);
          break;
				case TEBAGRASYS_MOUSE_CLICK:
          if(area->haveOnClick)
            (*area->onClick)(e);
          break;
        case TEBAGRASYS_MOUSE_UP:
					if(area->haveOnClick)
						(*area->onClick)(e);
          if(area->haveOnUp)
            (*area->onUp)(e);
          break;
				case TEBAGRASYS_DRAGGING:
          if(area->haveOnDrag)
            (*area->onDrag)(e);
          break;
				case TEBAGRASYS_DRAG_END:
          if(area->haveOnDragOver)
            (*area->onDragOver)(e);
          break;
			}
		}
		else if((area->mouseIsIn) && (area->haveOnLeave))
		{
			(*area->onLeave)(e);
			area->mouseIsIn = FALSE;
		}
	}
	return EXIT_SUCCESS;
}

void tebagrasys_mouse_area_attach(
	tebagrasys_mouse_area_t* area,
	tebagrasys_mouse_area_event_enum_t eventtype,
	tebagrasys_mouse_area_callback_t handler
)
{
	switch(eventtype)
	{
		case TEBAGRASYS_EVENT_MOVE:
			area->haveOnMove = TRUE;
			area->onMove = handler;
			break;
		case TEBAGRASYS_EVENT_DOWN:
			area->haveOnDown = TRUE;
			area->onDown = handler;
			break;
		case TEBAGRASYS_EVENT_CLICK:
			area->haveOnClick = TRUE;
			area->onClick = handler;
			break;
		case TEBAGRASYS_EVENT_UP:
			area->haveOnUp = TRUE;
			area->onUp = handler;
			break;
		case TEBAGRASYS_EVENT_DRAG:
			area->haveOnDrag = TRUE;
			area->onDrag = handler;
			break;
		case TEBAGRASYS_EVENT_DRAG_OVER:
			area->haveOnDragOver = TRUE;
			area->onDragOver = handler;
			break;
		case TEBAGRASYS_EVENT_HOVER:
			area->haveOnHover = TRUE;
			area->onHover = handler;
			break;
		case TEBAGRASYS_EVENT_LEAVE:
			area->haveOnLeave = TRUE;
			area->onLeave = handler;
			break;
	}
}

