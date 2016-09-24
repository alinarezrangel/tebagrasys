	TEBAGRASYS (BASIC) - Terminal Basic Graphical System
--------------------------------------------------------

TEBAGRASYS (called BASIC for abbreviation) is a GPM
(General Purpose Mouse) middleware for it's use on
terminal-based programs. Is designed for provide a
simple, easy to use interface for read the mouse,
detect events an create "mouse areas" and "geometries".

	============
		Examples
	============

An simple example is:

```````````````````````````````````````````````````````````````
#include <stdio.h>
#include <stdlib.h>
#include <gpm.h>
#include <tebagrasys.h>

tebagrasys_error_t on_click(tebagrasys_mouse_event_t* event)
{
	printf("Clicked the area");
	return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
	tebagrasys_mouse_area_t* area;
	tebagrasys_main_loop_t* loop;
	tebagrasys_cursor_t* cursor;

	area = tebagrasys_mouse_area_new(
		tebagrasys_geometry_rectangle_new(
			(tebagrasys_geometry_point_t){0, 0},
			(tebagrasys_geometry_size_t){4, 4}
		),
		tebagrasys_geometry_rectangle_have
	);
	loop = tebagrasys_main_loop_new();
	cursor = tebagrasys_cursor_new("@");

	tebagrasys_mouse_area_attach(
		area,
		TEBAGRASYS_MOUSE_CLICK,
		on_click
	);

	tebagrasys_main_loop_exit_on(loop, TEBAGRASYS_EXIT_ON_EOF);

	tebagrasys_main_loop_do_gpm(loop);

	tebagrasys_mouse_area_dealloc(area);
	tebagrasys_main_loop_dealloc(loop);
	tebagrasys_cursor_dealloc(cursor);

	return EXIT_SUCCESS;
}
```````````````````````````````````````````````````````````````

	=========
		Files
	=========

CHANGELOG.txt:: ChangeLog of the project
NEWS.txt:: Changes added on this version
HOWTO.txt:: How To build, install, make, etc
LICENSE.txt:: License of the project
README.txt:: README file
Makefile:: Makefile

