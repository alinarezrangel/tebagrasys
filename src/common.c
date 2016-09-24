/* **********************************************
**********************
*** common.c: Common types and functions
**********************
********************************************** */

#include "common.h"

tebagrasys_pointer_t tebagrasys_malloc(size_t bts)
{
	return malloc(bts);
}
tebagrasys_pointer_t tebagrasys_realloc(tebagrasys_pointer_t ptr, size_t ns)
{
	return realloc(ptr, ns);
}
void tebagrasys_dealloc(tebagrasys_pointer_t ptr)
{
	free(ptr);
}
