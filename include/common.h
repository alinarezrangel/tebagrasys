/* **********************************************
**********************
*** common.h: Common types and functions
**********************
********************************************** */

#if !defined(__TEBAGRASYS_LIB_COMMON_H__)
#define __TEBAGRASYS_LIB_COMMON_H__ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#if defined(__cplusplus)
#	define TEBAGRASYS_DECLR_BEGIN extern "C" {
#	define TEBAGRASYS_DECLR_END }
#else
#	define TEBAGRASYS_DECLR_BEGIN
#	define TEBAGRASYS_DECLR_END
#endif

#if !defined(CONST) && !defined(NOT_USE_CONST)
#	define CONST const
#else
#	define CONST
#endif

#if !defined(FALSE)
#	define FALSE 0
#endif

#if !defined(TRUE)
#	define TRUE (!FALSE)
#endif

#if !defined(BOOL)
#	define BOOL tebagrasys_bool_t
#endif

TEBAGRASYS_DECLR_BEGIN

#if !defined(NOT_DECLARE_BOOL_T)
typedef uint8_t bool_t;
#endif
typedef uint8_t tebagrasys_bool_t;

typedef uint32_t tebagrasys_error_t;

typedef uint64_t tebagrasys_screen_size_t;

TEBAGRASYS_DECLR_END

#endif /* __TEBAGRASYS_LIB_COMMON_H__ */