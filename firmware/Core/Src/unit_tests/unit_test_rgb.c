#include "unit_tests/unit_test_helpers.h"
#include "unit_tests/unit_test_rgb.h"
#include "rgb.h"

#include <string.h>

uint8_t TEST_EXEC__RGB_convert_hex_to_rgb()
{
    char hex_color_code[10] = "\0";
    LED_RGB_t rgb_result;
    uint8_t status;

    // Fail Criteria

    // Empty string
    status = RGB_convert_hex_to_rgb(hex_color_code, &rgb_result);
    TEST_ASSERT_TRUE(status == 1);

    // Missing "#"
    strcpy(hex_color_code, "FFAABB");
    status = RGB_convert_hex_to_rgb(hex_color_code, &rgb_result);
    TEST_ASSERT_TRUE(status == 2);

    // Invalid Length - Missing hex value
    strcpy(hex_color_code, "#FFAAB");
    status = RGB_convert_hex_to_rgb(hex_color_code, &rgb_result);
    TEST_ASSERT_TRUE(status == 3);

    // Invalid Hex Value
    strcpy(hex_color_code, "#K2AABB");
    status = RGB_convert_hex_to_rgb(hex_color_code, &rgb_result);
    TEST_ASSERT_TRUE(status == 4);

    // Pass Criteria
    strcpy(hex_color_code, "#D2AABB");
    status = RGB_convert_hex_to_rgb(hex_color_code, &rgb_result);
    TEST_ASSERT_TRUE(status == 0);

    TEST_ASSERT_TRUE(rgb_result.RGB_red == 0xD2);
    TEST_ASSERT_TRUE(rgb_result.RGB_green == 0xAA);
    TEST_ASSERT_TRUE(rgb_result.RGB_blue == 0xBB);

    return 0;
}
