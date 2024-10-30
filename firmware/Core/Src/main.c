#include "main.h"
#include "IO.h"
#include "pwm.h"
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
        printf("\nall tests passed\n");
    }
    else
    {
        printf("\nsome tests failed\n");
    }

        ESP_LOGI("Main", "Hello, ESP32-C3!");

    // For demonstration, create a simple task
    while (true)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1 second
        ESP_LOGI("Main", "Running...");
        LED_test_dimming();
    }
}