/* **********************************************
**********************
*** geometry.c: Defines geometry types
**********************
********************************************** */

#include "geometry.h"

tebagrasys_geometry_rectangle_t* tebagrasys_geometry_rectangle_new(
	tebagrasys_geometry_point_t st,
	tebagrasys_geometry_size_t sz
)
{
	tebagrasys_geometry_rectangle_t* rect =
		tebagrasys_malloc(
			sizeof(tebagrasys_geometry_rectangle_t)
		);
	if(rect == NULL)
		return NULL;
	rect->start = st;
	rect->size = sz;
	return rect;
}

tebagrasys_geometry_circle_t* tebagrasys_geometry_circle_new(
	tebagrasys_geometry_point_t st,
	tebagrasys_screen_size_t rd
)
{
	tebagrasys_geometry_circle_t* circ =
		tebagrasys_malloc(
			sizeof(tebagrasys_geometry_circle_t)
		);
	if(circ == NULL)
		return NULL;
	circ->center = st;
	circ->radius = rd;
	return circ;
}

tebagrasys_bool_t tebagrasys_geometry_rectangle_have(
	tebagrasys_geometry_rectangle_t* rect,
	tebagrasys_geometry_point_t pt
)
{
	return (
		(pt.x >= rect->start.x) &&
		(pt.y >= rect->start.y) &&
		(pt.x <= (rect->start.x + rect->size.sizeX)) &&
		(pt.y <= (rect->start.y + rect->size.sizeY))
	);
}

tebagrasys_bool_t tebagrasys_geometry_circle_have(
	tebagrasys_geometry_circle_t* circ,
	tebagrasys_geometry_point_t pt
)
{
	// |A| = sqrt(x1^2 + x2^2)
	return sqrt(
		pow(abs(circ->center.x - pt.x), 2) +
		pow(abs(circ->center.y - pt.y), 2)
	) <= circ->radius;
}
