#include "main.h"
#include "IO.h"
#include "pwm.h"
#include "rgb.h"
#include "unit_tests/unit_test_executor.h"

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

void app_main(void)
{

    GPIO_init();
    LED_PWM_Init();

    char response_output_buf[2048] = {0};
    uint8_t unit_tests_result = TEST_run_all_unit_tests_and_log(response_output_buf, sizeof(response_output_buf));
    printf(response_output_buf);

    if (unit_tests_result)
    {
        printf("\nAll tests passed!\n");
    }
    else
    {
        printf("\nSome tests failed!\n");
    }

    ESP_LOGI("Main", "Hello, ESP32-C3!");

    // For demonstration, create a simple task
    while (true)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1 second
        ESP_LOGI("Main", "Running...");
        LED_test_dimming();

        // TODO: Create an rtos thread to handle the dimming
        LED_RGB_t rgb_values;
        const uint8_t hex_parse_result = RGB_convert_hex_to_rgb("#FFAABB", &rgb_values);

        if(hex_parse_result == 0){
            printf("Great Success\n");
        }
        uint8_t brightness = 50;
        const uint8_t brightness_result = RGB_apply_brightness_to_rgb(&brightness,&rgb_values);

        if(brightness_result == 0){
            printf("Very Nice: Dimming Applied\n");
        }
    }
}