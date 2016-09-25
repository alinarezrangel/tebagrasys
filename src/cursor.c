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
	strcpy(cursor->byteSec, bs);
	cursor->position = {0, 0};
	return cursor;
}

void tebagrasys_cursor_dealloc(tebagrasys_cursor_t* cursor)
{
	tebagrasys_dealloc(cursor->byteSec);
	tebagrasys_dealloc(cursor);
}

