#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include <gpm.h>

#include "mousehandler.h"
#include "geometry.h"

int lastX = 0;
int lastY = 0;

int MyMouseHandler(Gpm_Event* event, void* data)
{
	/* printf("Cursor event %d at (%d, %d)\r\n", event->type, event->x, event->y); */
	tebagrasys_mouse_event_t* evt = tebagrasys_gpm_event_to_native_event(event);
	char cursor = '^';
	if(evt == NULL)
		return 1;
	printf("\033[%d;%dH ", lastY, lastX);
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
	printf("\033[%d;%dH%c", evt->y, evt->x, cursor);
	fflush(stdout);
	free(evt);
	return 0;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	Gpm_Connect conn;
	int c = 0;
	conn.eventMask = ~0;
	conn.defaultMask = 0;
	conn.minMod = 0;
	conn.maxMod = ~0;

	if(Gpm_Open(&conn, 0) < 0)
	{
		fprintf(stderr, "Error: cant connect to the mouse server\r\n");
		return EXIT_FAILURE;
	}

	gpm_handler = MyMouseHandler;

	while((c = Gpm_Getc(stdin)) != EOF)
		printf("%c", c);

	Gpm_Close();
	return EXIT_SUCCESS;
}
