/* **********************************************
**********************
*** cursor.c: Basic Cursor Handling
**********************
********************************************** */

#include "cursor.h"

tebagrasys_cursor_t* tebagrasys_cursor_new(const char* bs)
{
	size_t bsl = strlen(bs);
	tebagrasys_cursor_t* cursor =
		tebagrasys_malloc(
			sizeof(tebagrasys_cursor_t)
		);
	cursor->byteSec =
		tebagrasys_malloc(sizeof(char) * (bsl + 1));
	cursor->byteSecLength = bsl + 1;
	strncpy(cursor->byteSec, bs, bsl);
	cursor->byteSec[bsl] = '\0';
	cursor->position = (tebagrasys_geometry_point_t){0, 0};
	return cursor;
}

void tebagrasys_cursor_dealloc(tebagrasys_cursor_t* cursor)
{
	tebagrasys_dealloc(cursor->byteSec);
	tebagrasys_dealloc(cursor);
}

