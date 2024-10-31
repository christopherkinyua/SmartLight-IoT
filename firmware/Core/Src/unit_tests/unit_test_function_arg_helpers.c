#include "unit_tests/unit_test_helpers.h"
#include "unit_tests/unit_test_function_arg_helpers.h"
#include "function_arg_helpers.h"

#include <string.h>

uint8_t TEST__is_valid_hex_string()
{
    char hex_color_code[20] = "\0";
    uint8_t status;

    // Fail Criteria

    // Empty string
    status = is_valid_hex_string(hex_color_code, strlen(hex_color_code));
    TEST_ASSERT_TRUE(status == 1);

    // Invalid Hex Value ie "#" is not a hex value
    strcpy(hex_color_code, "#FFAABB");
    status = is_valid_hex_string(hex_color_code, strlen(hex_color_code));
    TEST_ASSERT_TRUE(status == 2);

    // Pass Criteria
    strcpy(hex_color_code, "1234567890ABCDEF");
    status = is_valid_hex_string(hex_color_code, strlen(hex_color_code));
    TEST_ASSERT_TRUE(status == 0);

    return 0;
}
