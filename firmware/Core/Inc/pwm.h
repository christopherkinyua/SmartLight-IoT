#ifndef __INCLUDE_GUARD__PWM_H__
#define __INCLUDE_GUARD__PWM_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void LED_PWM_Init(void);
    uint8_t LED_set_dimming(uint32_t duty_percentage);
    void LED_test_dimming(void);

#ifdef __cplusplus
}
#endif

#endif // __INCLUDE_GUARD__PWM_H__