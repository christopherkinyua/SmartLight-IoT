#include "pwm.h"
#include "IO.h"
#include "rgb.h"

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
    ledc_channel_config_t RGB_red_channel = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = RED_CHANNEL,
        .timer_sel = LEDC_TIMER_0,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = RED_GPIO_PIN,
        .duty = 0, // Initially off
        .hpoint = 0};
    ledc_channel_config(&RGB_red_channel);

    ledc_channel_config_t RGB_green_channel = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = GREEN_CHANNEL,
        .timer_sel = LEDC_TIMER_0,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = GREEN_GPIO_PIN,
        .duty = 0, // Initially off
        .hpoint = 0};
    ledc_channel_config(&RGB_green_channel);

    ledc_channel_config_t RGB_blue_channel= {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = BLUE_CHANNEL,
        .timer_sel = LEDC_TIMER_0,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = BLUE_GPIO_PIN,
        .duty = 0, // Initially off
        .hpoint = 0};
    ledc_channel_config(&RGB_blue_channel);

    ledc_channel_config_t RGB_white_channel = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = WHITE_CHANNEL,
        .timer_sel = LEDC_TIMER_0,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = WHITE_GPIO_PIN,
        .duty = 0, // Initially off
        .hpoint = 0};
    ledc_channel_config(&RGB_white_channel);

    ledc_channel_config_t ledc_channel_8 = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = LEDC_CHANNEL_4,
        .timer_sel = LEDC_TIMER_0,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = GPIO_NUM_8,
        .duty = 0, // Initially off
        .hpoint = 0};
    ledc_channel_config(&ledc_channel_8);
}

/// @brief Sets the dimming level of a specified LED channel to a percentage
/// @param channel The LED channel to dim (LEDC_CHANNEL_0, LEDC_CHANNEL_1, etc.)
/// @param duty_percentage The desired brightness level as a percentage (0-100)
/// @return 0 on success, > 0 on error
uint8_t LED_set_dimming(ledc_channel_t channel, uint32_t duty_percentage)
{
    if (duty_percentage > 100)
    {
        // Error: Percentage out of range
        return 1; 
    }

    // Calculate duty cycle based on percentage (0-100)
    uint32_t duty = (8191 * duty_percentage) / 100; // 8191 = 2^13 - 1 (13-bit resolution)

    // Set the duty cycle and update the PWM output for the specified channel
    ledc_set_duty(LEDC_LOW_SPEED_MODE, channel, duty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, channel);

    return 0; // Success
}

/// @brief Ramps the dimming of a specified LED channel up and down
/// @param channel The LED channel to dim (LEDC_CHANNEL_0, LEDC_CHANNEL_1, etc.)
/// @param delay_ms Delay in milliseconds between brightness adjustments
/// @return 0 on success, > 0 on error
uint8_t LED_channel_ramp(ledc_channel_t channel, uint32_t delay_ms)
{
    uint8_t dimming_result;

    // Ramp up brightness from 0 to 100%
    for (int i = 0; i <= 100; i += 5)
    {
        dimming_result = LED_set_dimming(channel, i);
        if (dimming_result > 0) {
            // Error handling
            return dimming_result;
        } 
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    }

    // Ramp down brightness from 100 to 0%
    for (int i = 100; i >= 0; i -= 5)
    {
        dimming_result = LED_set_dimming(channel, i);
        if (dimming_result > 0) {
            // Error handling
            return dimming_result;
        }  
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    }

    return 0; // Success
}


/// @brief 0-10V Dimming: Testing the 0-10V Dimming through PWM
/// @param None
/// @return 0 on success, >0 on error
/// TODO: Implement the error checks obtained from LED_set_dimming
void LED_test_dimming(void)
{
    LED_channel_ramp(RED_CHANNEL, 100); // Red
    LED_channel_ramp(BLUE_CHANNEL, 100); // Blue
    LED_channel_ramp(GREEN_CHANNEL, 100); // Green
    LED_channel_ramp(WHITE_CHANNEL, 100); // White
    LED_channel_ramp(LEDC_CHANNEL_4, 100); // Not Sure
}


/// @brief Sets the PWM duty cycles based on RGB values with brightness adjustment
/// @param rgb_values The struct containing RGB values and brightness
/// @return 0 on success, > 0 on error
uint8_t LED_set_rgb(const LED_RGB_t *rgb_values)
{
    // Validate the brightness level
    if (rgb_values->RGB_brightness > 100)
    {
        return 1; // Error: Invalid brightness value
    }

    // Calculate duty cycles for each color component based on brightness
    uint32_t duty_red = (8191 * rgb_values->RGB_red) / (255);
    uint32_t duty_green = (8191 * rgb_values->RGB_green ) / (255);
    uint32_t duty_blue = (8191 * rgb_values->RGB_blue ) / (255);

    // Apply the duty cycles to the respective LED channels
    ledc_set_duty(LEDC_LOW_SPEED_MODE, RED_CHANNEL, duty_red);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, RED_CHANNEL);

    ledc_set_duty(LEDC_LOW_SPEED_MODE, GREEN_CHANNEL, duty_green);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, GREEN_CHANNEL);

    ledc_set_duty(LEDC_LOW_SPEED_MODE, BLUE_CHANNEL, duty_blue);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, BLUE_CHANNEL);

    return 0; // Success
}