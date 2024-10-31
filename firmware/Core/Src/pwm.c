#include "pwm.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include <stdio.h>

/// @brief : LEDC Timer and Channel Configuration
/// @param None
/// TODO: Add other channels for the RGBWW PWM Dimming
void LED_PWM_Init(void)
{

    // Setting up the LEDC Timer Configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .duty_resolution = LEDC_TIMER_13_BIT, // 13-bit resolution for the duty cycle
        .freq_hz = 5000,                      // Frequency in Hertz
        .clk_cfg = LEDC_AUTO_CLK};
    ledc_timer_config(&ledc_timer);

    // Setting up the LEDC channel Configuration for GPIO pin 0
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = LEDC_CHANNEL_0,
        .timer_sel = LEDC_TIMER_0,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = GPIO_NUM_0,
        .duty = 0, // Initially off
        .hpoint = 0};
    ledc_channel_config(&ledc_channel);
}

/// @brief 0-10V Dimming: Controls the dimming level of an LED using PWM.
/// @param duty_percentage
/// - Arg 0: The desired brightness level as a percentage (uint32_t)
/// @return 0 on success, > 0 on error
/// TODO: Add error checks for the ledc_set_duty and ledc_update_duty
uint8_t LED_set_dimming(uint32_t duty_percentage)
{
    if (duty_percentage > 100)
    {
        return 1;
    }

    // Calculate duty cycle based on percentage (0-100)
    uint32_t duty = (8191 * duty_percentage) / 100; // 8191 = 2^13 - 1 (13-bit resolution)

    // Set the duty cycle and update the PWM output
    ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

    return 0;
}

/// @brief 0-10V Dimming: Testing the 0-10V Dimming through PWM
/// @param None
/// @return 0 on success, >0 on error
/// TODO: Implement the error checks obtained from LED_set_dimming
void LED_test_dimming(void)
{
    uint8_t dimming_result;
    for (int i = 0; i <= 100; i += 5)
    {
        dimming_result = LED_set_dimming(i);
        if (dimming_result == 0)
        {
            continue;
        }
        vTaskDelay(500 / portTICK_PERIOD_MS); // Delay 500ms
    }
    for (int i = 100; i >= 0; i -= 5)
    {
        dimming_result = LED_set_dimming(i);
        if (dimming_result == 0)
        {
            continue;
        }
        vTaskDelay(500 / portTICK_PERIOD_MS); // Delay 500ms
    }
}