# C Unit Tests

This repo uses an in-house unit test framework, which is about as minimal as unit tests can be.

## How to Write a Test

The following guide demonstrates an example of creating a testable function, and then writing
unit tests for that function.

1.  Come up with a testable function (called the Function-Under-Test, or FUT). For examples:

    ```c
    // File: transforms/byte_transforms.c

    #include "transforms/byte_transforms.h"

    uint32_t GEN_convert_big_endian_four_byte_array_to_uint32(uint8_t four_byte_array[]) {
        // recall: big endian means the Most Significant Bit (MSB) is at index 0 (left side)
        return (four_byte_array[0] << 24) | (four_byte_array[1] << 16) |
                (four_byte_array[2] << 8)  | four_byte_array[3];
    }
    ```

2.  Create a new file in `Core/Src/unit_tests` called `test_bytes_transforms.c`. Create the unit test
    function within that file:

        ```c
        // File: unit_tests/test_bytes_transforms.c

        #include "unit_tests/unit_test_helpers.h" // for all unit tests
        #include "transforms/byte_transforms.h" // for the Function-Under-Test

        uint8_t TEST_EXEC__GEN_convert_big_endian_four_byte_array_to_uint32() {
            // TODO: implement unit test later
            TEST_ASSERT_TRUE(1 == 1);

            return 0; // THIS LINE MUST BE INCLUDED to indicate the test passed
        }
        ```

3.  Add the function prototype to the header file `Core/Inc/unit_tests/test_bytes_transforms.h`:

    ```c
    // File: unit_tests/test_bytes_transforms.h
    // ...
    uint8_t TEST_EXEC__GEN_convert_big_endian_four_byte_array_to_uint32();
    // ...
    ```

4.  Add the test to the "inventory table" of tests in `Core/Src/unit_tests/unit_test_inventory.c`:

    ```c
    // File: unit_tests/unit_test_inventory.c
    #include "unit_tests/test_byte_transforms.h"

    const TEST_Definition_t TEST_definitions[] = {
        // ...
        // Add the following section:
        {
            .test_func = TEST_EXEC__GEN_convert_big_endian_four_byte_array_to_uint32,
            .test_file = "transforms/byte_transforms",
            .test_func_name = "GEN_convert_big_endian_four_byte_array_to_uint32"
        },
        // ...
    };

    ```

5.  Flash the ESP32, and check the monitor ESP-IDF Monitor window. See that the test passes.

6.  Go back to the `TEST_EXEC__GEN_convert_big_endian_four_byte_array_to_uint32` function, and implement
    the test:

        ```c
        // File: unit_tests/test_bytes_transforms.c

        uint8_t TEST_EXEC__GEN_convert_big_endian_four_byte_array_to_uint32() {
            uint8_t test_array_1[4] = {0x12, 0x34, 0x56, 0x78};
            uint32_t expected_result_1 = 0x12345678;
            TEST_ASSERT_TRUE(GEN_convert_big_endian_four_byte_array_to_uint32(test_array_1) == expected_result_1);

            uint8_t test_array_2[4] = {0xFE, 0xDC, 0xBA, 0x98};
            uint32_t expected_result_2 = 4275878552; // 0xFEDCBA98
            TEST_ASSERT_TRUE(GEN_convert_big_endian_four_byte_array_to_uint32(test_array_2) == expected_result_2);

            return 0; // THIS LINE MUST BE INCLUDED to indicate the test passed
        }
        ```

7.  Run the test again.
