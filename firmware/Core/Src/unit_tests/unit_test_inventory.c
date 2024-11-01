#include "unit_tests/unit_test_helpers.h"
#include "unit_tests/unit_test_inventory.h"
#include "unit_tests/unit_test_pwm.h"
#include "unit_tests/unit_test_rgb.h"
#include "unit_tests/unit_test_function_arg_helpers.h"

// extern
const TEST_Definition_t TEST_definitions[] = {

    {.test_func = TEST__is_valid_hex_string,
     .test_file = "unit_tests/unit_test_function_arg_helpers",
     .test_func_name = "is_valid_hex_string"},

    // {.test_func = TEST_EXEC__LED_set_dimming,
    //  .test_file = "unit_tests/unit_test_pwm",
    //  .test_func_name = "LED_set_dimming"},

    {.test_func = TEST_EXEC__RGB_convert_hex_to_rgb,
     .test_file = "unit_tests/unit_test_rgb",
     .test_func_name = "RGB_convert_hex_to_rgb"},

};

// extern
const int16_t TEST_definitions_count = sizeof(TEST_definitions) / sizeof(TEST_Definition_t);
