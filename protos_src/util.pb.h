/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.5 */

#ifndef PB_UTIL_UTIL_PB_H_INCLUDED
#define PB_UTIL_UTIL_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _util_MsgStatus { 
    util_MsgStatus_STATUS_OK = 0, 
    util_MsgStatus_STATUS_UNKNOWN_MESSAGE = 1 
} util_MsgStatus;

/* Helper constants for enums */
#define _util_MsgStatus_MIN util_MsgStatus_STATUS_OK
#define _util_MsgStatus_MAX util_MsgStatus_STATUS_UNKNOWN_MESSAGE
#define _util_MsgStatus_ARRAYSIZE ((util_MsgStatus)(util_MsgStatus_STATUS_UNKNOWN_MESSAGE+1))


#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif