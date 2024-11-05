#include "rgb.h"
#include "function_arg_helpers.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// @brief Converts HEX color code value to RGB values.
/// @param hex_color_code - The Hex color code to be parsed (string)
/// @param rgb_result - The struct to store the parsed RGB values
/// @return 0 on success, > 0 on error
uint8_t RGB_convert_hex_to_rgb(const char *hex_color_code, LED_RGB_t *rgb_result)
{

    // The string, hex_color_code, should be in the form of #RRGGBB

    // Check if the string is empty
    if (hex_color_code == NULL || hex_color_code[0] == '\0')
    {
        // Empty or NULL string, return error
        return 1;
    }

    // Check if the string starts with "#"
    if (hex_color_code[0] != '#')
    {
        // Error: Missing sync_char "#"
        return 2;
    }

    // Check if the string contains all RGB values (length should be 7 for "#RRGGBB")
    const uint8_t hex_code_length = strlen(hex_color_code);
    if (hex_code_length != 7)
    {
        // Error: Invalid length- missing hex values for the RGB
        return 3;
    }

    // Check if the string contains valid hex values (skip the first character "#")
    const uint8_t hex_check = is_valid_hex_string(hex_color_code + 1, hex_code_length - 1);
    if (hex_check > 0)
    {
        // Error: Invalid hexadecimal within the string
        return 4;
    }

    // Parse the string and pass the values into the struct holding the RBG Values
    // Extracting the string RGB values from hex_color_code
    char red[3] = {hex_color_code[1], hex_color_code[2], '\0'};
    char green[3] = {hex_color_code[3], hex_color_code[4], '\0'};
    char blue[3] = {hex_color_code[5], hex_color_code[6], '\0'};

    // Converting the string values into decimals and passing them into the struct
    rgb_result->RGB_red = (uint8_t)strtol(red, NULL, 16);
    rgb_result->RGB_green = (uint8_t)strtol(green, NULL, 16);
    rgb_result->RGB_blue = (uint8_t)strtol(blue, NULL, 16);

    return 0;
}


/// @brief Applies the brightness param to the RGB values.
/// @param LED_brightness - The brightness value to be applied (uint8_t)
/// @param rgb_result - The struct to store the parsed RGB values
/// @return 0 on success, > 0 on error
uint8_t RGB_apply_brightness_to_rgb(const uint8_t *LED_brightness, LED_RGB_t *rgb_result)
{
    if(LED_brightness == NULL || *LED_brightness > 100){
        // Error: Missing brightness value
        return 1;
    }

    if(rgb_result == NULL){
        // Error: Missing RGB value
        return 2;
    }

    //Apply brightness to RGB Values
    rgb_result->RGB_red = (rgb_result->RGB_red * (*LED_brightness)) / 100;
    rgb_result->RGB_green = (rgb_result->RGB_green * (*LED_brightness)) / 100;
    rgb_result->RGB_blue = (rgb_result->RGB_blue * (*LED_brightness)) /100;

    return 0;
}