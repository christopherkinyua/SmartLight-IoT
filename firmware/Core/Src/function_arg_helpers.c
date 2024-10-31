#include "function_arg_helpers.h"

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

/// @brief Checks if the passed string is a proper hexadecimal representation.
/// @param hex_string - The HEX string to be checked (const char *)
/// @param string_len - The length of the passed string to be checked (uint8_t)
/// @return 0 on success, > 0 on error
uint8_t is_valid_hex_string(const char *hex_string, uint8_t string_len)
{

    if (hex_string == NULL || string_len == 0 || *hex_string == '\0')
    {
        // Error if string and string_len is NULL or empty
        return 1;
    }

    for (uint8_t i = 0; i < string_len; i++)
    {
        char character = *hex_string;

        // Checking if the character is between 0-9, A-F, or a-f
        if (!(isdigit(character) || (toupper(character) >= 'A' && toupper(character) <= 'F')))
        {
            // Error: Invalid hex character within the string
            return 2;
        }

        hex_string++;
    }

    return 0;
}