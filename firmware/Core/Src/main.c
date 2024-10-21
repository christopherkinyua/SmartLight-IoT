#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"

#include "main.h"

// Define the app_main function
void app_main(void) {
    ESP_LOGI("Main", "Hello, ESP32-C3!");

    // For demonstration, create a simple task
    while (true) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay 1 second
        ESP_LOGI("Main", "Running...");
    }
}