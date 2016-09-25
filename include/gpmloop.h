/* **********************************************
**********************
*** gpmloop.h: Main Loop Utilities for GPM
**********************
********************************************** */

#if !defined(__TEBAGRASYS_LIB_GPMLOOP_H__)
#define __TEBAGRASYS_LIB_GPMLOOP_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gpm.h>

#include "common.h"
#include "geometry.h"
#include "mousehandler.h"
#include "gpmconvert.h"
#include "loop.h"

TEBAGRASYS_DECLR_BEGIN

extern tebagrasys_geometry_point_t tebagrasys_gpm_lastCursorPosition;
extern tebagrasys_main_loop_t** tebagrasys_gpm_mainLoop;

int tebagrasys_gpm_loop_mouse_event(Gpm_Event* ev, void* dt);

/**
* @brief Starts the main loop using GPM.
*/
tebagrasys_error_t tebagrasys_main_loop_do_gpm(
	tebagrasys_main_loop_t* loop
);

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_GPMLOOP_H__ */
