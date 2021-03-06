#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <gpm.h>

#include "tebagrasys.h"
/* #include "tbgpm.h" */
#include "gpmconvert.h"
#include "gpmloop.h"

/*
int lastX = 0;
int lastY = 0;

int MyMouseHandler(Gpm_Event* event, void* data)
{
	printf("Cursor event %d at (%d, %d)\r\n", event->type, event->x, event->y);
	tebagrasys_mouse_event_t* evt = tebagrasys_gpm_event_to_native_event(event);
	char cursor = '^';
	if(evt == NULL)
		return 1;
	printf("\033[2;2H                   ");
	tebagrasys_mouse_area_controller(evt, data);
	printf("\033[%d;%dH ", lastY, lastX);
	printf("\033[5;5H!!!!!!!!!!!");
	printf("\033[6;5H!!!!!!!!!!!");
	printf("\033[7;5H!!!!!!!!!!!");
	printf("\033[8;5H!!!!!!!!!!!");
	printf("\033[9;5H!!!!!!!!!!!");
	printf("\033[10;5H!!!!!!!!!!!");
	printf("\033[11;5H!!!!!!!!!!!");
	printf("\033[12;5H!!!!!!!!!!!");
	printf("\033[13;5H!!!!!!!!!!!");
	printf("\033[14;5H!!!!!!!!!!!");
	printf("\033[15;5H!!!!!!!!!!!");
	lastX = evt->x;
	lastY = evt->y;
	switch(evt->type)
	{
		case TEBAGRASYS_MOUSE_MOVE:
			cursor = '^';
			break;
		case TEBAGRASYS_MOUSE_DOWN:
			cursor = '@';
			break;
		case TEBAGRASYS_MOUSE_UP:
			cursor = '#';
			break;
		case TEBAGRASYS_MOUSE_CLICK:
			cursor = '$';
			break;
		case TEBAGRASYS_DRAGGING:
			cursor = '%';
			break;
		case TEBAGRASYS_DRAG_END:
			cursor = '*';
			break;
	}
	printf("\033[;HEvent on %d, %d : %d          ", evt->x, evt->y, evt->type);
	printf("\033[%d;%dH%c", evt->y, evt->x, cursor);
	fflush(stdout);
	tebagrasys_dealloc(evt);
	return 0;
}
*/

tebagrasys_error_t MyAreaOnClickHandler(tebagrasys_mouse_event_t* ev)
{
	printf("\033[2;2HClicked in MyArea");
	return EXIT_SUCCESS;
}

tebagrasys_error_t MyAreaOnHoverHandler(tebagrasys_mouse_event_t* ev)
{
	printf("\033[2;2HHovered in MyArea");
	return EXIT_SUCCESS;
}

tebagrasys_error_t MyAreaOnLeaveHandler(tebagrasys_mouse_event_t* ev)
{
	printf("\033[2;2HLeaved from MyArea");
	return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
	/*Gpm_Connect conn;
	int c = 0;*/
	tebagrasys_mouse_area_t* area = tebagrasys_mouse_area_new(
		tebagrasys_geometry_rectangle_new(
			(tebagrasys_geometry_point_t){5, 5},
			(tebagrasys_geometry_size_t){10, 10}
		),
		tebagrasys_geometry_rectangle_have
	);
	if(area == NULL)
	{
		perror("Unable to create a new mousearea");
		return EXIT_FAILURE;
	}
	tebagrasys_main_loop_t* loop = tebagrasys_main_loop_new(
		tebagrasys_cursor_new("#"),
		TEBAGRASYS_EXIT_ON_EOF
	);
	if(loop == NULL)
	{
		tebagrasys_mouse_area_dealloc(area);
		perror("Unable to create a new loop");
		return EXIT_FAILURE;
	}

	setlocale(LC_ALL, "");
/*
	conn.eventMask = ~0;
	conn.defaultMask = 0;
	conn.minMod = 0;
	conn.maxMod = ~0;
*/
	tebagrasys_mouse_area_attach(
		area,
		TEBAGRASYS_EVENT_CLICK,
		MyAreaOnClickHandler
	);
	tebagrasys_mouse_area_attach(
		area,
		TEBAGRASYS_EVENT_HOVER,
		MyAreaOnHoverHandler
	);
	tebagrasys_mouse_area_attach(
		area,
		TEBAGRASYS_EVENT_LEAVE,
		MyAreaOnLeaveHandler
	);
/*
	if(Gpm_Open(&conn, 0) < 0)
	{
		fprintf(stderr, "Error: cant connect to the mouse server\r\n");
		return EXIT_FAILURE;
	}
*/
	printf("\033[2J\033[?25l");
/*
	gpm_handler = MyMouseHandler;

	while((c = Gpm_Getc(stdin)) != EOF)
		printf("%c", c);
*/
	printf("Entering loop\r\n");
	tebagrasys_main_loop_do_gpm(loop);
	printf("Exiting loop\r\n");

	tebagrasys_main_loop_dealloc(loop);
	tebagrasys_mouse_area_dealloc(area);
/*
	Gpm_Close();
*/
	printf("\033[2J\033[;H\033[?25h");

	return EXIT_SUCCESS;
}
