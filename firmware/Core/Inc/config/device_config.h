#ifndef __INCLUDE_GUARD__DEVICE_CONFIG_H__
#define __INCLUDE_GUARD__DEVICE_CONFIG_H__

#include <stdint.h>
#include "rgb.h"

#ifdef __cplusplus
extern "C"
{
#endif

    // TODO: Confirm if this is the correct approach
    typedef struct
    {
        char device_id[30];   // Unique identifier for the device. TODO: Need to determine the format for the identifier
        char dimming_type;    // Type of dimming, e.g., "0_10V" or "RGBW_PWM"
        uint8_t brightness;   // Brightness level (0-100%)
        LED_RGB_t rgb_values; // Color Intensity for each channel (0-255)
    } LED_dimming_control_t;

#ifdef __cplusplus
}
#endif

#endif // __INCLUDE_GUARD__DEVICE_CONFIG_H__