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
        // LED_test_dimming();

        // char rgb_string[10] = "#FF6347";
        LED_RGB_t rgb_values;
        // const uint8_t LED_brightness = 100;

        // uint8_t rgb_conversion_result = RGB_convert_hex_to_rgb("#F542E6",&rgb_values);

        // if(rgb_conversion_result == 0){
        //     printf("RGB Conversion Done\n");
        //     // continue;
        // }

        // uint8_t brightness_application = RGB_apply_brightness(LED_brightness, &rgb_values);
        // printf(brightness_application);

        // if(brightness_application == 0){
        //     printf("Brightness applied\n");
        //     continue;
        // }

        rgb_values.RGB_red = 245;
        rgb_values.RGB_green = 66;
        rgb_values.RGB_blue = 230;
        uint8_t dimming_result = LED_set_rgb(&rgb_values);
        

        if(dimming_result == 0){
            printf("Success");
            continue;
        }

        // rgb_conversion_result = RGB_convert_hex_to_rgb("#2B93C7",&rgb_values);
        // brightness_application = RGB_apply_brightness((uint8_t)50, &rgb_values);
        // dimming_result = LED_set_rgb(&rgb_values);


    }
}