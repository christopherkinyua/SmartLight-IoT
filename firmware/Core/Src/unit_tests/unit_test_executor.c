#include "unit_tests/unit_test_executor.h"
#include "unit_tests/unit_test_inventory.h"

#include "main.h"

#include "string.h"
#include "stdio.h"
#include "esp_timer.h"

uint8_t TEST_run_all_unit_tests_and_log(char log_buffer[], uint16_t log_buffer_size)
{
    uint16_t total_exec_count = 0;
    uint16_t total_pass_count = 0;
    uint16_t total_fail_count = 0;
    const uint32_t start_time_ms = esp_timer_get_time() / 1000;

    log_buffer[0] = '\0';

    for (uint8_t test_num = 0; test_num < TEST_definitions_count; test_num++)
    {
        TEST_Function_Ptr test_function = TEST_definitions[test_num].test_func;
        uint8_t result = test_function();

        char test_log_buffer[200];
        snprintf(
            test_log_buffer,
            sizeof(test_log_buffer),
            "Test #%03d: %s (%s > %s)\n",
            test_num,
            (result == 0) ? "PASS ✅" : "FAIL ❌",
            TEST_definitions[test_num].test_file,
            TEST_definitions[test_num].test_func_name);
        printf(test_log_buffer);

        total_exec_count++;
        if (result == 0)
        {
            total_pass_count++;
        }
        else
        {
            total_fail_count++;
        }
    }
    const uint32_t end_time_ms = esp_timer_get_time() / 1000;

    snprintf(
        log_buffer,
        log_buffer_size,
        "Total tests: %d - Pass: %d, Fail: %d, Duration: %lums",
        total_exec_count,
        total_pass_count,
        total_fail_count,
        end_time_ms - start_time_ms);

    return total_fail_count == 0;
}
