#ifndef __INCLUDE_GUARD__IO_H__
#define __INCLUDE_GUARD__IO_H__

#include <stdint.h>
#include "driver/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RED_CHANNEL GPIO_NUM_5
#define GREEN_CHANNEL GPIO_NUM_4
#define BLUE_CHANNEL GPIO_NUM_6

void GPIO_init(void);

#ifdef __cplusplus
}
#endif

#endif // __INCLUDE_GUARD__IO_H__