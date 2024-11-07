#include "IO.h"
#include "main.h"

#include "driver/gpio.h"
#include "driver/i2c_master.h"
#include <stdio.h>

/// @brief GPIO Pin Initialization
/// @param None
/// TODO: Set up pins that will be used as input and outputs for current monitoring
void GPIO_init(void)
{

   // Initializing GPIO0 as an input with a pulldown
   // TODO: Update with appropriate pins that will be used
   gpio_set_direction(GPIO_NUM_0, GPIO_MODE_OUTPUT);
   gpio_set_pull_mode(GPIO_NUM_0, GPIO_PULLDOWN_ONLY);
}

/// @brief I2C Initialization
/// @param None
/// TODO: Set up pins that will be used as input and outputs for current monitoring
void i2c_init(void)
{

   // Initializing GPIO0 as an input with a pulldown
   // TODO: Update with appropriate pins that will be used
   gpio_set_direction(GPIO_NUM_0, GPIO_MODE_OUTPUT);
   gpio_set_pull_mode(GPIO_NUM_0, GPIO_PULLDOWN_ONLY);
}