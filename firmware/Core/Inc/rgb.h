#ifndef __INCLUDE_GUARD__RGB_H__
#define __INCLUDE_GUARD__RGB_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Struct to hold RGB values.
typedef struct {
    uint8_t RGB_red;  // Red component (0-255)
    uint8_t RGB_green;  // Green component (0-255)
    uint8_t RGB_blue;  // Blue component (0-255)
} LED_RGB_t;


uint8_t RGB_convert_hex_to_rgb(char *hex_color_code, LED_RGB_t *rgb_result);

#ifdef __cplusplus
}
#endif

#endif // __INCLUDE_GUARD__RGB_H__