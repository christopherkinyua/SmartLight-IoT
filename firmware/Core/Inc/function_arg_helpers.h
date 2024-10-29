#ifndef __INCLUDE_GUARD__FUNCTION_ARG_HELPERS_H__
#define __INCLUDE_GUARD__FUNCTION_ARG_HELPERS_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t is_valid_hex_string(const char *hex_string, uint8_t string_len);

#ifdef __cplusplus
}
#endif

#endif // __INCLUDE_GUARD__FUNCTION_ARG_HELPERS_H__