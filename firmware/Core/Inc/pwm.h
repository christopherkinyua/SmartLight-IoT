#ifndef __INCLUDE_GUARD__PWM_H__
#define __INCLUDE_GUARD__PWM_H__

#include <stdint.h>
#include "driver/ledc.h"
#include "rgb.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define RED_CHANNEL LEDC_CHANNEL_0
#define GREEN_CHANNEL LEDC_CHANNEL_1
#define BLUE_CHANNEL LEDC_CHANNEL_2
#define WHITE_CHANNEL LEDC_CHANNEL_3


    void LED_PWM_Init(void);
    uint8_t LED_set_dimming(ledc_channel_t channel, uint32_t duty_percentage);
    uint8_t LED_channel_ramp(ledc_channel_t channel, uint32_t delay_ms);
    uint8_t LED_set_rgb(const LED_RGB_t *rgb_values);
    void LED_test_dimming(void);

#ifdef __cplusplus
}
#endif

#endif // __INCLUDE_GUARD__PWM_H__