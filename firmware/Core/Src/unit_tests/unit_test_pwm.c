#include "unit_tests/unit_test_helpers.h"
#include "unit_tests/unit_test_pwm.h"
#include "pwm.h"

#include <string.h>

uint8_t TEST_EXEC__LED_set_dimming()
{
    uint8_t status;

    // Pass Criteria
    status = LED_set_dimming(50);
    TEST_ASSERT_TRUE(status == 0);

    // Fail Criteria
    status = LED_set_dimming(110);
    TEST_ASSERT_TRUE(status == 1);

    return 0;
}
