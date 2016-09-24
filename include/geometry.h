/* **********************************************
**********************
*** geometry.h: Defines geometry types
**********************
********************************************** */

#if !defined(__TEBAGRASYS_LIB_GEOMETRY_H__)
#define __TEBAGRASYS_LIB_GEOMETRY_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include "common.h"

TEBAGRASYS_DECLR_BEGIN

/**
* @brief Represents a point in the screen.
*/
typedef struct
{
	tebagrasys_screen_size_t x;
	tebagrasys_screen_size_t y;
} tebagrasys_geometry_point_t;

/**
* @brief Represents a XY size in the screen.
*/
typedef struct
{
	tebagrasys_screen_size_t sizeX;
	tebagrasys_screen_size_t sizeY;
} tebagrasys_geometry_size_t;

/**
* @brief Callback for determinate if a point is inside a geometry.
*/
typedef
  tebagrasys_bool_t (*tebagrasys_geometry_controller_havecbk_t)(
    tebagrasys_pointer_t* geo,
    tebagrasys_geometry_point_t pt
  );

/**
* @brief Represents a rectangle in the screen.
* Any type can inherit this struct.
*/
typedef struct
{
	tebagrasys_geometry_point_t start;
	tebagrasys_geometry_size_t size;
} tebagrasys_geometry_rectangle_t;

/**
* @brief Represents a circle in the screen.
* Any type can inherit this struct.
*/
typedef struct
{
	tebagrasys_geometry_point_t center;
	tebagrasys_screen_size_t radius;
} tebagrasys_geometry_circle_t;

/**
* @brief makes a new rectangle.
* The returned data should be deallocated using tebagrasys_dealloc.
*/
tebagrasys_geometry_rectangle_t* tebagrasys_geometry_rectangle_new(
	tebagrasys_geometry_point_t st,
	tebagrasys_geometry_size_t sz
);

/**
* @brief makes a new circle.
* The returned data should be deallocated using tebagrasys_dealloc.
*/
tebagrasys_geometry_circle_t* tebagrasys_geometry_circle_new(
	tebagrasys_geometry_point_t st,
	tebagrasys_screen_size_t rd
);

/**
* @brief Determintes if the point is inside the rectangle
* Returns TRUE if the point pt is inside the rectangle.
*/
tebagrasys_bool_t tebagrasys_geometry_rectangle_have(
	tebagrasys_geometry_rectangle_t* rect,
	tebagrasys_geometry_point_t pt
);

/**
* @brief Determintes if the point is inside the circle
* Returns TRUE if the point pt is inside the circle.
*/
tebagrasys_bool_t tebagrasys_geometry_circle_have(
	tebagrasys_geometry_circle_t* circ,
	tebagrasys_geometry_point_t pt
);

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_GEOMETRY_H__ */
