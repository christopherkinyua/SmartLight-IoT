#include "unit_tests/unit_test_helpers.h"
#include "unit_tests/unit_test_inventory.h"
#include "unit_tests/unit_test_pwm.h"

// extern
const TEST_Definition_t TEST_definitions[] = {

    {.test_func = TEST_EXEC__LED_set_dimming,
     .test_file = "unit_tests/unit_test_pwm",
     .test_func_name = "LED_set_dimming"},

};

// extern
const int16_t TEST_definitions_count = sizeof(TEST_definitions) / sizeof(TEST_Definition_t);
