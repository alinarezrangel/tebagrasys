/* **********************************************
**********************
*** gpmconvert.h: Convert between GPM and TEBAGRASYS
**********************
********************************************** */

#if !defined(__TEBAGRASYS_LIB_GPMCONVERT_H__)
#define __TEBAGRASYS_LIB_GPMCONVERT_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <gpm.h>

#include "common.h"
#include "mousehandler.h"

TEBAGRASYS_DECLR_BEGIN

/**
* @brief Converts a Gpm_Event to a tebagrasys_mouse_event_t.
* The resulting event should be deallocated using tebagrasys_dealloc.
*/
tebagrasys_mouse_event_t* tebagrasys_gpm_event_to_native_event(Gpm_Event* event);

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_GPMCONVERT_H__ */
