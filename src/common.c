/* **********************************************
**********************
*** common.c: Common types and functions
**********************
********************************************** */

#include "common.h"

tebagrasys_pointer_t tebagrasys_malloc(size_t bts)
{
	return (tebagrasys_pointer_t)malloc(bts);
}
tebagrasys_pointer_t tebagrasys_realloc(tebagrasys_pointer_t ptr, size_t ns)
{
	return (tebagrasys_pointer_t)realloc(ptr, ns);
}
void tebagrasys_dealloc(tebagrasys_pointer_t ptr)
{
	free(ptr);
}
